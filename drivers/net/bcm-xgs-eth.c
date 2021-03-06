/*
 * Copyright 2016 Broadcom Corporation.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#include <common.h>
#include <malloc.h>
#include <net.h>
#include <config.h>

#include <phy.h>
#include <miiphy.h>

#include <asm/io.h>

#include <netdev.h>
#include "bcm-xgs-eth.h"

#if defined(CONFIG_BCM_XGS_ETH_GMAC)
#include "bcm-xgs-eth-gmac.h"
#else
#error "bcm_xgs_eth: NEED to define a MAC!"
#endif

#define BCM_NET_MODULE_DESCRIPTION	"Broadcom XGS Iproc Ethernet driver"
#define BCM_NET_MODULE_VERSION		"0.1"
#define BCM_XGS_ETH_DEV_NAME		"bcm_xgs"

static const char banner[] =
	BCM_NET_MODULE_DESCRIPTION " " BCM_NET_MODULE_VERSION "\n";

static int bcm_xgs_eth_init(struct eth_device *dev)
{
	struct eth_info *eth = (struct eth_info *)(dev->priv);
	struct eth_dma *dma = &(eth->dma);
	struct phy_device *phydev;
	int rc = 0;
	int i, phyaddr;

	rc = eth->mac_init(dev);
	if (rc) {
		error("%s: Couldn't cofigure MAC!\n", __func__);
		return rc;
	}

	/* disable DMA */
	dma->disable_dma(dev, dma, MAC_DMA_RX);
	dma->disable_dma(dev, dma, MAC_DMA_TX);

	eth->port_num = 0;

	/* not to connect phy, add by lihz - 2018.7.19 */
#if 0

	printf("Connecting PHY 0...\n");
#if (defined(CONFIG_GREYHOUND) || defined(CONFIG_HURRICANE3))
    phyaddr = CONFIG_EXTERNAL_PHY_DEV_ID;
#else
    phyaddr = dev->index + 1;
#endif
	phydev = phy_connect(miiphy_get_dev_by_name(dev->name),
			     phyaddr, dev, eth->phy_interface);
	if (phydev != NULL) {
		eth->port[0] = phydev;
		eth->port_num += 1;
	} else {
		debug("No PHY found for port 0\n");
	}

	for (i = 0; i < eth->port_num; i++)
		phy_config(eth->port[i]);
#endif
	return rc;
}

/*
 * u-boot net functions
 */

static int bcm_xgs_eth_send(struct eth_device *dev, void *packet, int length)
{
	struct eth_dma *dma = &(((struct eth_info *)(dev->priv))->dma);
	uint8_t *buf = (uint8_t *)packet;
	int rc = 0;
	int i = 0;

	debug("%s enter\n", __func__);

	/* load buf and start transmit */
	rc = dma->tx_packet(dev, dma, buf, length);
	if (rc) {
		debug("ERROR - Tx failed\n");
		return rc;
	}

	while (!(dma->check_tx_done(dev, dma))) {
		udelay(100);
		debug(".");
		i++;
		if (i > 20) {
			error("%s: Tx timeout: retried 20 times\n", __func__);
			rc = -1;
			break;
		}
	}

	debug("%s exit rc(0x%x)\n", __func__, rc);
	return rc;
}

static int bcm_xgs_eth_receive(struct eth_device *dev)
{
	struct eth_dma *dma = &(((struct eth_info *)(dev->priv))->dma);
	uint8_t *buf = (uint8_t *)net_rx_packets[0];
	int rcvlen;
	int rc = 0;
	int i = 0;

	while (1) {
		/* Poll Rx queue to get a packet */
		rcvlen = dma->check_rx_done(dev, dma, buf);
		if (rcvlen < 0) {
			/* No packet received */
			rc = -1;
#if 0
			debug("\nNO More Rx\n");
#endif
			break;
		} else if ((rcvlen == 0) || (rcvlen > RX_BUF_SIZE)) {
			debug("%s: Wrong Ethernet packet size (%d B), skip!\n",
			      __func__, rcvlen);
			break;
		} else {
			debug("recieved\n");

			/* Forward received packet to uboot network handler */
			net_process_received_packet(buf, rcvlen);

			if (++i >= PKTBUFSRX)
				i = 0;
			buf = net_rx_packets[i];
		}
	}

	return rc;
}

static int bcm_xgs_eth_write_hwaddr(struct eth_device *dev)
{
	struct eth_info *eth = (struct eth_info *)(dev->priv);

	printf(" ETH MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
	       dev->enetaddr[0], dev->enetaddr[1], dev->enetaddr[2],
	       dev->enetaddr[3], dev->enetaddr[4], dev->enetaddr[5]);

	return eth->set_mac_addr(dev, dev->enetaddr);
}

static int bcm_xgs_eth_open(struct eth_device *dev, bd_t *bt)
{
	struct eth_info *eth = (struct eth_info *)(dev->priv);
	struct eth_dma *dma = &(eth->dma);
	int i;

	debug("Enabling BCM XGS Ethernet.\n");

	eth->enable_mac(dev);

	/* enable tx and rx DMA */
	dma->enable_dma(dev, dma, MAC_DMA_RX);
	dma->enable_dma(dev, dma, MAC_DMA_TX);
	/* not to set phy, by lihz - 2018.7.19 */
#if 0
	/*
	 * Need to start PHY here because link speed can change
	 * before each ethernet operation
	 */
	for (i = 0; i < eth->port_num; i++) {
		if (phy_startup(eth->port[i])) {
			error("%s: PHY %d startup failed!\n", __func__, i);
			if (i == CONFIG_BCM_XGS_ETH_DEFAULT_PORT) {
				error("%s: No default port %d!\n", __func__, i);
				return -1;
			}
		}
	}

	/* Set MAC speed using default port */
	i = CONFIG_BCM_XGS_ETH_DEFAULT_PORT;
	debug("PHY %d: speed:%d, duplex:%d, link:%d\n", i,
	      eth->port[i]->speed, eth->port[i]->duplex, eth->port[i]->link);
	eth->set_mac_speed(dev, eth->port[i]->speed, eth->port[i]->duplex);
#endif

	debug("Enable Ethernet Done.\n");

	return 0;
}

static void bcm_xgs_eth_close(struct eth_device *dev)
{
	struct eth_info *eth = (struct eth_info *)(dev->priv);
	struct eth_dma *dma = &(eth->dma);

	/* disable DMA */
	dma->disable_dma(dev, dma, MAC_DMA_RX);
	dma->disable_dma(dev, dma, MAC_DMA_TX);

	eth->disable_mac(dev);
}

int bcm_xgs_eth_register(bd_t *bis, u8 dev_num)
{
	struct eth_device *dev;
	struct eth_info *eth;
	int rc;

	dev = (struct eth_device *)malloc(sizeof(struct eth_device));
	if (dev == NULL) {
		error("%s: Not enough memory!\n", __func__);
		return -1;
	}

	eth = (struct eth_info *)malloc(sizeof(struct eth_info));
	if (eth == NULL) {
		error("%s: Not enough memory!\n", __func__);
		return -1;
	}

	printf(banner);

	memset(dev, 0, sizeof(*dev));
	sprintf(dev->name, "%s_%s-%hu", BCM_XGS_ETH_DEV_NAME,
		BCM_XGS_ETH_MAC_NAME, dev_num);

	dev->priv = (void *)eth;
	dev->iobase = 0;
    dev->index = dev_num;
	dev->init = bcm_xgs_eth_open;
	dev->halt = bcm_xgs_eth_close;
	dev->send = bcm_xgs_eth_send;
	dev->recv = bcm_xgs_eth_receive;
	dev->write_hwaddr = bcm_xgs_eth_write_hwaddr;

#ifdef CONFIG_BCM_XGS_ETH_GMAC
	if (gmac_add(dev)) {
		free(eth);
		free(dev);
		error("%s: Adding GMAC failed!\n", __func__);
		return -1;
	}
#else
#error "bcm_xgs_eth: NEED to register a MAC!"
#endif

	eth_register(dev);

#ifdef CONFIG_CMD_MII
	miiphy_register(dev->name, eth->miiphy_read, eth->miiphy_write);
#endif

	/* Initialization */
	debug("Ethernet initialization ...");

	rc = bcm_xgs_eth_init(dev);
	if (rc != 0) {
		error("%s: configuration failed!\n", __func__);
		return -1;
	}

	printf("Basic ethernet functionality initialized\n");

	return 0;
}
