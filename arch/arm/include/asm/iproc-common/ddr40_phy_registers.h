/*
 * Copyright 2016 Broadcom Corporation.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef DDR40_PHY_REGISTERS_H__
#define DDR40_PHY_REGISTERS_H__

/**
 * m = memory, c = core, r = register, f = field, d = data.
 */
#if !defined(GET_FIELD) && !defined(SET_FIELD)
#define BRCM_ALIGN(c,r,f)   c##_##r##_##f##_ALIGN
#define BRCM_BITS(c,r,f)    c##_##r##_##f##_BITS
#define BRCM_MASK(c,r,f)    c##_##r##_##f##_MASK
#define BRCM_SHIFT(c,r,f)   c##_##r##_##f##_SHIFT

#define GET_FIELD(m,c,r,f) \
	((((m) & BRCM_MASK(c,r,f)) >> BRCM_SHIFT(c,r,f)) << BRCM_ALIGN(c,r,f))

#define SET_FIELD(m,c,r,f,d) \
	((m) = (((m) & ~BRCM_MASK(c,r,f)) | ((((d) >> BRCM_ALIGN(c,r,f)) << \
	 BRCM_SHIFT(c,r,f)) & BRCM_MASK(c,r,f))) \
	)

#define SET_TYPE_FIELD(m,c,r,f,d) SET_FIELD(m,c,r,f,c##_##d)
#define SET_NAME_FIELD(m,c,r,f,d) SET_FIELD(m,c,r,f,c##_##r##_##f##_##d)
#define SET_VALUE_FIELD(m,c,r,f,d) SET_FIELD(m,c,r,f,d)

#endif /* GET & SET */

/***************************************************************************
 *DDR40_CORE_PHY_CONTROL_REGS - DDR40 CORE DDR40 physical interface control registers
 ***************************************************************************/
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION          0x00000000 /* Address & Control revision register */
#define DDR40_CORE_PHY_CONTROL_REGS_CLK_PM_CTRL       0x00000004 /* PHY clock power management control register */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS        0x00000010 /* PHY PLL status register */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG        0x00000014 /* PHY PLL configuration register */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL       0x00000018 /* PHY PLL control register */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS      0x0000001c /* PHY PLL dividers control register */
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL       0x00000020 /* Aux Control register */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL 0x00000030 /* Address & Control coarse VDL static override control register */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL 0x00000034 /* Address & Control fine VDL static override control register */
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL  0x00000038 /* Idle mode SSTL pad control register */
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL   0x0000003c /* PVT Compensation control and status register */
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL     0x00000040 /* SSTL pad drive characteristics control register */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS 0x00000044 /* PHY Auto Init rd_data_dly result register */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE     0x00000048 /* PHY VDL calibration control register */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS  0x0000004c /* PHY VDL calibration status register */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS 0x00000050 /* PHY DQ VDL calibration status register */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS 0x00000054 /* PHY Write Channel VDL calibration status register */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS 0x00000058 /* PHY Read Enable VDL calibration status register */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL 0x0000005c /* Virtual VTT Control and Status register */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS 0x00000060 /* Virtual VTT Control and Status register */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONNECTIONS 0x00000064 /* Virtual VTT Connections register */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_OVERRIDE 0x00000068 /* Virtual VTT Override register */
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL  0x0000006c /* VREF DAC Control register */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL     0x00000070 /* PhyBist Control Register */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_SEED      0x00000074 /* PhyBist Seed Register */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS    0x00000078 /* PhyBist General Status Register */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CTL_STATUS 0x0000007c /* PhyBist Per-Bit Control Pad Status Register */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_DQ_STATUS 0x00000080 /* PhyBist Per-Bit DQ Pad Status Register */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_MISC_STATUS 0x00000084 /* PhyBist Per-Bit DM and CK Pad Status Register */
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG       0x00000090 /* DRAM Command Register */
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG0         0x00000094 /* Mode Register 0 */
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG1         0x00000098 /* Mode Register 1 */
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG2         0x0000009c /* Mode Register 2 */
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG3         0x000000a0 /* Mode Register 3 */
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL   0x000000a4 /* Standby Control register */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL     0x000000b0 /* Strap Control register */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2    0x000000b4 /* Strap Control register */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS      0x000000b8 /* Strap Status register */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2     0x000000bc /* Strap Status register */
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE 0x000000c0 /* Freeze-on-error enable register */
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK 0x000000c4 /* Datapth Loopback control register */

/***************************************************************************
 *DDR40_CORE_PHY_WORD_LANE_0 - DDR40 CORE DDR40 word lane #0 control registers
 ***************************************************************************/
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN 0x00000200 /* Read Enable Byte VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W 0x00000204 /* Write Byte VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P 0x00000208 /* Read Byte DQSP VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N 0x0000020c /* Read Byte DQSN VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W 0x00000210 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W 0x00000214 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W 0x00000218 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W 0x0000021c /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W 0x00000220 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W 0x00000224 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W 0x00000228 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W 0x0000022c /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W 0x00000230 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P 0x00000234 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N 0x00000238 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P 0x0000023c /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N 0x00000240 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P 0x00000244 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N 0x00000248 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P 0x0000024c /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N 0x00000250 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P 0x00000254 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N 0x00000258 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P 0x0000025c /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N 0x00000260 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P 0x00000264 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N 0x00000268 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P 0x0000026c /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N 0x00000270 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN 0x00000274 /* Read Enable Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W 0x000002a4 /* Write Byte VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P 0x000002a8 /* Read Byte DQSP VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N 0x000002ac /* Read Byte DQSN VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W 0x000002b0 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W 0x000002b4 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W 0x000002b8 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W 0x000002bc /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W 0x000002c0 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W 0x000002c4 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W 0x000002c8 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W 0x000002cc /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W 0x000002d0 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P 0x000002d4 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N 0x000002d8 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P 0x000002dc /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N 0x000002e0 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P 0x000002e4 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N 0x000002e8 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P 0x000002ec /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N 0x000002f0 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P 0x000002f4 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N 0x000002f8 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P 0x000002fc /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N 0x00000300 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P 0x00000304 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N 0x00000308 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P 0x0000030c /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N 0x00000310 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN 0x00000314 /* Read Enable Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P 0x00000328 /* Read DQSP VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N 0x0000032c /* Read DQSN VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P 0x00000330 /* Read DQ-P VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N 0x00000334 /* Read DQ-N VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W 0x00000338 /* Write DQ Byte VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W 0x0000033c /* Write DQ Bit VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P 0x00000348 /* Read DQSP VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N 0x0000034c /* Read DQSN VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P 0x00000350 /* Read DQ-P VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N 0x00000354 /* Read DQ-N VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W 0x00000358 /* Write DQ Byte VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W 0x0000035c /* Write DQ Bit VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_DATA_DLY      0x00000360 /* Word Lane read channel control register */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL       0x00000364 /* Word Lane read channel control register */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_0 0x00000370 /* Read fifo data register, first data */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_1 0x00000374 /* Read fifo data register, second data */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_2 0x00000378 /* Read fifo data register, third data */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_3 0x0000037c /* Read fifo data register, fourth data */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_0 0x00000380 /* Read fifo data register, first data */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_1 0x00000384 /* Read fifo data register, second data */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_2 0x00000388 /* Read fifo data register, third data */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_3 0x0000038c /* Read fifo data register, fourth data */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_STATUS   0x00000390 /* Read fifo status register */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_CLEAR    0x00000394 /* Read fifo status clear register */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL   0x000003a0 /* Idle mode SSTL pad control register */
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL      0x000003a4 /* SSTL pad drive characteristics control register */
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE  0x000003a8 /* Clock pad disable register */
#define DDR40_CORE_PHY_WORD_LANE_0_WR_PREAMBLE_MODE   0x000003ac /* Write cycle preamble control register */
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ    0x000003b0 /* PHYBIST mode VDL step select adjustment register */

/***************************************************************************
 *DDR40_CORE_PHY_WORD_LANE_1 - DDR40 CORE DDR40 word lane #1 control registers
 ***************************************************************************/
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN 0x00000400 /* Read Enable Byte VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W 0x00000404 /* Write Byte VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P 0x00000408 /* Read Byte DQSP VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N 0x0000040c /* Read Byte DQSN VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W 0x00000410 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W 0x00000414 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W 0x00000418 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W 0x0000041c /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W 0x00000420 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W 0x00000424 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W 0x00000428 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W 0x0000042c /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W 0x00000430 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P 0x00000434 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N 0x00000438 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P 0x0000043c /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N 0x00000440 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P 0x00000444 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N 0x00000448 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P 0x0000044c /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N 0x00000450 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P 0x00000454 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N 0x00000458 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P 0x0000045c /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N 0x00000460 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P 0x00000464 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N 0x00000468 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P 0x0000046c /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N 0x00000470 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN 0x00000474 /* Read Enable Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W 0x000004a4 /* Write Byte VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P 0x000004a8 /* Read Byte DQSP VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N 0x000004ac /* Read Byte DQSN VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W 0x000004b0 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W 0x000004b4 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W 0x000004b8 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W 0x000004bc /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W 0x000004c0 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W 0x000004c4 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W 0x000004c8 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W 0x000004cc /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W 0x000004d0 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P 0x000004d4 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N 0x000004d8 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P 0x000004dc /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N 0x000004e0 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P 0x000004e4 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N 0x000004e8 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P 0x000004ec /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N 0x000004f0 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P 0x000004f4 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N 0x000004f8 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P 0x000004fc /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N 0x00000500 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P 0x00000504 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N 0x00000508 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P 0x0000050c /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N 0x00000510 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN 0x00000514 /* Read Enable Bit VDL static override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P 0x00000528 /* Read DQSP VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N 0x0000052c /* Read DQSN VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P 0x00000530 /* Read DQ-P VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N 0x00000534 /* Read DQ-N VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W 0x00000538 /* Write DQ Byte VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W 0x0000053c /* Write DQ Bit VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P 0x00000548 /* Read DQSP VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N 0x0000054c /* Read DQSN VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P 0x00000550 /* Read DQ-P VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N 0x00000554 /* Read DQ-N VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W 0x00000558 /* Write DQ Byte VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W 0x0000055c /* Write DQ Bit VDL dynamic override control register */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_DATA_DLY      0x00000560 /* Word Lane read channel control register */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL       0x00000564 /* Word Lane read channel control register */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_0 0x00000570 /* Read fifo data register, first data */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_1 0x00000574 /* Read fifo data register, second data */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_2 0x00000578 /* Read fifo data register, third data */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_3 0x0000057c /* Read fifo data register, fourth data */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_0 0x00000580 /* Read fifo data register, first data */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_1 0x00000584 /* Read fifo data register, second data */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_2 0x00000588 /* Read fifo data register, third data */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_3 0x0000058c /* Read fifo data register, fourth data */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_STATUS   0x00000590 /* Read fifo status register */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_CLEAR    0x00000594 /* Read fifo status clear register */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL   0x000005a0 /* Idle mode SSTL pad control register */
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL      0x000005a4 /* SSTL pad drive characteristics control register */
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE  0x000005a8 /* Clock pad disable register */
#define DDR40_CORE_PHY_WORD_LANE_1_WR_PREAMBLE_MODE   0x000005ac /* Write cycle preamble control register */
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ    0x000005b0 /* PHYBIST mode VDL step select adjustment register */

/***************************************************************************
 *DDR40_CORE_PHY_ECC_LANE - DDR40 ECC lane control registers
 ***************************************************************************/
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN 0x00000600 /* Read Enable Byte VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W     0x00000604 /* Write Byte VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P   0x00000608 /* Read Byte DQSP VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N   0x0000060c /* Read Byte DQSN VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W 0x00000610 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W 0x00000614 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W 0x00000618 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W 0x0000061c /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W  0x00000630 /* Write Bit VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P 0x00000634 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N 0x00000638 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P 0x0000063c /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N 0x00000640 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P 0x00000644 /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N 0x00000648 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P 0x0000064c /* Read DQSP Bit VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N 0x00000650 /* Read DQSN Bit VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN 0x00000674 /* Read Enable Bit VDL static override control register */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P 0x00000728 /* Read DQSP VDL dynamic override control register */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N 0x0000072c /* Read DQSN VDL dynamic override control register */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P 0x00000730 /* Read DQ-P VDL dynamic override control register */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N 0x00000734 /* Read DQ-N VDL dynamic override control register */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W 0x00000738 /* Write DQ Byte VDL dynamic override control register */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W 0x0000073c /* Write DQ Bit VDL dynamic override control register */
#define DDR40_CORE_PHY_ECC_LANE_READ_DATA_DLY         0x00000760 /* Word Lane read channel control register */
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL          0x00000764 /* Word Lane read channel control register */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_0      0x00000770 /* Read fifo data register, first data */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_1      0x00000774 /* Read fifo data register, second data */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_2      0x00000778 /* Read fifo data register, third data */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_3      0x0000077c /* Read fifo data register, fourth data */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_STATUS      0x00000790 /* Read fifo status register */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_CLEAR       0x00000794 /* Read fifo status clear register */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL      0x000007a0 /* Idle mode SSTL pad control register */
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL         0x000007a4 /* SSTL pad drive characteristics control register */
#define DDR40_CORE_PHY_ECC_LANE_CLOCK_PAD_DISABLE     0x000007a8 /* Clock pad disable register */
#define DDR40_CORE_PHY_ECC_LANE_WR_PREAMBLE_MODE      0x000007ac /* Write cycle preamble control register */
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ       0x000007b0 /* PHYBIST mode VDL step select adjustment register */

/***************************************************************************
 *REVISION - Address & Control revision register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: REVISION :: reserved0 [31:23] */
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_reserved0_MASK             0xff800000
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_reserved0_ALIGN            0
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_reserved0_BITS             9
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_reserved0_SHIFT            23

/* DDR40_CORE_PHY_CONTROL_REGS :: REVISION :: TECHNOLOGY [22:20] */
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_TECHNOLOGY_MASK            0x00700000
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_TECHNOLOGY_ALIGN           0
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_TECHNOLOGY_BITS            3
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_TECHNOLOGY_SHIFT           20
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_TECHNOLOGY_DEFAULT    1

/* DDR40_CORE_PHY_CONTROL_REGS :: REVISION :: WB [19:19] */
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_WB_MASK                    0x00080000
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_WB_ALIGN                   0
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_WB_BITS                    1
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_WB_SHIFT                   19
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_WB_DEFAULT            0

/* DDR40_CORE_PHY_CONTROL_REGS :: REVISION :: BITS [18:16] */
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_BITS_MASK                  0x00070000
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_BITS_ALIGN                 0
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_BITS_BITS                  3
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_BITS_SHIFT                 16
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_BITS_DEFAULT          1

/* DDR40_CORE_PHY_CONTROL_REGS :: REVISION :: MAJOR [15:08] */
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_MAJOR_MASK                 0x0000ff00
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_MAJOR_ALIGN                0
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_MAJOR_BITS                 8
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_MAJOR_SHIFT                8
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_MAJOR_DEFAULT         64

/* DDR40_CORE_PHY_CONTROL_REGS :: REVISION :: MINOR [07:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_MINOR_MASK                 0x000000ff
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_MINOR_ALIGN                0
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_MINOR_BITS                 8
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_MINOR_SHIFT                0
#define DDR40_CORE_PHY_CONTROL_REGS_REVISION_MINOR_DEFAULT         4

/***************************************************************************
 *CLK_PM_CTRL - PHY clock power management control register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: CLK_PM_CTRL :: reserved0 [31:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_CLK_PM_CTRL_reserved0_MASK          0xfffffffe
#define DDR40_CORE_PHY_CONTROL_REGS_CLK_PM_CTRL_reserved0_ALIGN         0
#define DDR40_CORE_PHY_CONTROL_REGS_CLK_PM_CTRL_reserved0_BITS          31
#define DDR40_CORE_PHY_CONTROL_REGS_CLK_PM_CTRL_reserved0_SHIFT         1

/* DDR40_CORE_PHY_CONTROL_REGS :: CLK_PM_CTRL :: DIS_DDR_CLK [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_CLK_PM_CTRL_DIS_DDR_CLK_MASK        0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_CLK_PM_CTRL_DIS_DDR_CLK_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_CLK_PM_CTRL_DIS_DDR_CLK_BITS        1
#define DDR40_CORE_PHY_CONTROL_REGS_CLK_PM_CTRL_DIS_DDR_CLK_SHIFT       0
#define DDR40_CORE_PHY_CONTROL_REGS_CLK_PM_CTRL_DIS_DDR_CLK_DEFAULT 0

/***************************************************************************
 *PLL_STATUS - PHY PLL status register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_STATUS :: reserved0 [31:27] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_reserved0_MASK           0xf8000000
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_reserved0_ALIGN          0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_reserved0_BITS           5
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_reserved0_SHIFT          27

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_STATUS :: LOCK_LOST [26:26] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_LOCK_LOST_MASK           0x04000000
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_LOCK_LOST_ALIGN          0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_LOCK_LOST_BITS           1
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_LOCK_LOST_SHIFT          26

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_STATUS :: DDR_MHZ [25:14] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_DDR_MHZ_MASK             0x03ffc000
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_DDR_MHZ_ALIGN            0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_DDR_MHZ_BITS             12
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_DDR_MHZ_SHIFT            14

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_STATUS :: CLOCKING_4X [13:13] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_CLOCKING_4X_MASK         0x00002000
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_CLOCKING_4X_ALIGN        0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_CLOCKING_4X_BITS         1
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_CLOCKING_4X_SHIFT        13

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_STATUS :: STATUS [12:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_STATUS_MASK              0x00001ffe
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_STATUS_ALIGN             0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_STATUS_BITS              12
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_STATUS_SHIFT             1

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_STATUS :: LOCK [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_LOCK_MASK                0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_LOCK_ALIGN               0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_LOCK_BITS                1
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_STATUS_LOCK_SHIFT               0

/***************************************************************************
 *PLL_CONFIG - PHY PLL configuration register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_CONFIG :: reserved0 [31:07] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_reserved0_MASK           0xffffff80
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_reserved0_ALIGN          0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_reserved0_BITS           25
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_reserved0_SHIFT          7

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_CONFIG :: LP40_PLL_POST_RESET [06:06] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_LP40_PLL_POST_RESET_MASK 0x00000040
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_LP40_PLL_POST_RESET_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_LP40_PLL_POST_RESET_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_LP40_PLL_POST_RESET_SHIFT 6
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_LP40_PLL_POST_RESET_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_CONFIG :: RESET_POST_DIV [05:05] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_RESET_POST_DIV_MASK      0x00000020
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_RESET_POST_DIV_ALIGN     0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_RESET_POST_DIV_BITS      1
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_RESET_POST_DIV_SHIFT     5
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_RESET_POST_DIV_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_CONFIG :: LDO_CTRL [04:03] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_LDO_CTRL_MASK            0x00000018
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_LDO_CTRL_ALIGN           0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_LDO_CTRL_BITS            2
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_LDO_CTRL_SHIFT           3
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_LDO_CTRL_DEFAULT    2

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_CONFIG :: reserved1 [02:02] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_reserved1_MASK           0x00000004
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_reserved1_ALIGN          0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_reserved1_BITS           1
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_reserved1_SHIFT          2

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_CONFIG :: RESET [01:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_RESET_MASK               0x00000002
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_RESET_ALIGN              0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_RESET_BITS               1
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_RESET_SHIFT              1
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_RESET_DEFAULT       1

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_CONFIG :: PWRDN [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_PWRDN_MASK               0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_PWRDN_ALIGN              0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_PWRDN_BITS               1
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_PWRDN_SHIFT              0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONFIG_PWRDN_DEFAULT       0

/***************************************************************************
 *PLL_CONTROL - PHY PLL control register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_CONTROL :: reserved0 [31:31] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_reserved0_MASK          0x80000000
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_reserved0_ALIGN         0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_reserved0_BITS          1
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_reserved0_SHIFT         31

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_CONTROL :: i_kp [30:27] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_i_kp_MASK               0x78000000
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_i_kp_ALIGN              0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_i_kp_BITS               4
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_i_kp_SHIFT              27
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_i_kp_DEFAULT       10

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_CONTROL :: i_ki [26:24] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_i_ki_MASK               0x07000000
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_i_ki_ALIGN              0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_i_ki_BITS               3
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_i_ki_SHIFT              24
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_i_ki_DEFAULT       3

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_CONTROL :: i_ka [23:21] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_i_ka_MASK               0x00e00000
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_i_ka_ALIGN              0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_i_ka_BITS               3
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_i_ka_SHIFT              21
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_i_ka_DEFAULT       3

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_CONTROL :: PLL_CONTROL [20:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_PLL_CONTROL_MASK        0x001fffff
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_PLL_CONTROL_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_PLL_CONTROL_BITS        21
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_PLL_CONTROL_SHIFT       0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_CONTROL_PLL_CONTROL_DEFAULT 0

/***************************************************************************
 *PLL_DIVIDERS - PHY PLL dividers control register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_DIVIDERS :: reserved0 [31:16] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_reserved0_MASK         0xffff0000
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_reserved0_ALIGN        0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_reserved0_BITS         16
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_reserved0_SHIFT        16

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_DIVIDERS :: NDIV_40LP_HI [15:15] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_NDIV_40LP_HI_MASK      0x00008000
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_NDIV_40LP_HI_ALIGN     0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_NDIV_40LP_HI_BITS      1
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_NDIV_40LP_HI_SHIFT     15
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_NDIV_40LP_HI_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_DIVIDERS :: NDIV_40LP_LO [14:14] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_NDIV_40LP_LO_MASK      0x00004000
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_NDIV_40LP_LO_ALIGN     0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_NDIV_40LP_LO_BITS      1
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_NDIV_40LP_LO_SHIFT     14
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_NDIV_40LP_LO_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_DIVIDERS :: POST_DIV [13:11] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_POST_DIV_MASK          0x00003800
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_POST_DIV_ALIGN         0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_POST_DIV_BITS          3
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_POST_DIV_SHIFT         11
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_POST_DIV_DEFAULT  2

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_DIVIDERS :: PDIV [10:08] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_PDIV_MASK              0x00000700
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_PDIV_ALIGN             0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_PDIV_BITS              3
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_PDIV_SHIFT             8
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_PDIV_DEFAULT      4

/* DDR40_CORE_PHY_CONTROL_REGS :: PLL_DIVIDERS :: NDIV [07:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_NDIV_MASK              0x000000ff
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_NDIV_ALIGN             0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_NDIV_BITS              8
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_NDIV_SHIFT             0
#define DDR40_CORE_PHY_CONTROL_REGS_PLL_DIVIDERS_NDIV_DEFAULT      32

/***************************************************************************
 *AUX_CONTROL - Aux Control register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: AUX_CONTROL :: reserved0 [31:10] */
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_reserved0_MASK          0xfffffc00
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_reserved0_ALIGN         0
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_reserved0_BITS          22
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_reserved0_SHIFT         10

/* DDR40_CORE_PHY_CONTROL_REGS :: AUX_CONTROL :: is_cs [09:07] */
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_is_cs_MASK              0x00000380
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_is_cs_ALIGN             0
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_is_cs_BITS              3
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_is_cs_SHIFT             7
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_is_cs_DEFAULT      0

/* DDR40_CORE_PHY_CONTROL_REGS :: AUX_CONTROL :: is_ad [06:04] */
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_is_ad_MASK              0x00000070
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_is_ad_ALIGN             0
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_is_ad_BITS              3
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_is_ad_SHIFT             4
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_is_ad_DEFAULT      0

/* DDR40_CORE_PHY_CONTROL_REGS :: AUX_CONTROL :: is_odt [03:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_is_odt_MASK             0x0000000e
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_is_odt_ALIGN            0
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_is_odt_BITS             3
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_is_odt_SHIFT            1
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_is_odt_DEFAULT     0

/* DDR40_CORE_PHY_CONTROL_REGS :: AUX_CONTROL :: override [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_override_MASK           0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_override_ALIGN          0
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_override_BITS           1
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_override_SHIFT          0
#define DDR40_CORE_PHY_CONTROL_REGS_AUX_CONTROL_override_DEFAULT   0

/***************************************************************************
 *VDL_OVRIDE_BYTE_CTL - Address & Control coarse VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_OVRIDE_BYTE_CTL :: busy [31:31] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_busy_MASK       0x80000000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_busy_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_busy_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_busy_SHIFT      31
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_busy_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_OVRIDE_BYTE_CTL :: reserved0 [30:17] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_reserved0_MASK  0x7ffe0000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_reserved0_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_reserved0_BITS  14
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_reserved0_SHIFT 17

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_OVRIDE_BYTE_CTL :: ovr_en [16:16] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_ovr_en_MASK     0x00010000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_ovr_en_ALIGN    0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_ovr_en_BITS     1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_ovr_en_SHIFT    16
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_OVRIDE_BYTE_CTL :: reserved1 [15:09] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_reserved1_MASK  0x0000fe00
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_reserved1_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_reserved1_BITS  7
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_reserved1_SHIFT 9

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_OVRIDE_BYTE_CTL :: byte_sel [08:08] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_byte_sel_MASK   0x00000100
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_byte_sel_ALIGN  0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_byte_sel_BITS   1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_byte_sel_SHIFT  8
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_OVRIDE_BYTE_CTL :: reserved2 [07:06] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_reserved2_MASK  0x000000c0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_reserved2_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_reserved2_BITS  2
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_reserved2_SHIFT 6

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_OVRIDE_BYTE_CTL :: ovr_step [05:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_ovr_step_MASK   0x0000003f
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_ovr_step_ALIGN  0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_ovr_step_BITS   6
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_ovr_step_SHIFT  0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BYTE_CTL_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BIT_CTL - Address & Control fine VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_OVRIDE_BIT_CTL :: busy [31:31] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_busy_MASK        0x80000000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_busy_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_busy_BITS        1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_busy_SHIFT       31
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_busy_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_OVRIDE_BIT_CTL :: reserved0 [30:17] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_reserved0_MASK   0x7ffe0000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_reserved0_ALIGN  0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_reserved0_BITS   14
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_reserved0_SHIFT  17

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_OVRIDE_BIT_CTL :: ovr_en [16:16] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_ovr_en_MASK      0x00010000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_ovr_en_ALIGN     0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_ovr_en_BITS      1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_ovr_en_SHIFT     16
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_OVRIDE_BIT_CTL :: reserved1 [15:09] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_reserved1_MASK   0x0000fe00
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_reserved1_ALIGN  0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_reserved1_BITS   7
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_reserved1_SHIFT  9

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_OVRIDE_BIT_CTL :: byte_sel [08:08] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_byte_sel_MASK    0x00000100
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_byte_sel_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_byte_sel_BITS    1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_byte_sel_SHIFT   8
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_OVRIDE_BIT_CTL :: reserved2 [07:06] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_reserved2_MASK   0x000000c0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_reserved2_ALIGN  0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_reserved2_BITS   2
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_reserved2_SHIFT  6

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_OVRIDE_BIT_CTL :: ovr_step [05:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_ovr_step_MASK    0x0000003f
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_ovr_step_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_ovr_step_BITS    6
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_ovr_step_SHIFT   0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_OVRIDE_BIT_CTL_ovr_step_DEFAULT 0

/***************************************************************************
 *IDLE_PAD_CONTROL - Idle mode SSTL pad control register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: IDLE_PAD_CONTROL :: idle [31:31] */
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_idle_MASK          0x80000000
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_idle_ALIGN         0
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_idle_BITS          1
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_idle_SHIFT         31
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_idle_DEFAULT  0

/* DDR40_CORE_PHY_CONTROL_REGS :: IDLE_PAD_CONTROL :: reserved0 [30:09] */
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_reserved0_MASK     0x7ffffe00
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_reserved0_ALIGN    0
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_reserved0_BITS     22
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_reserved0_SHIFT    9

/* DDR40_CORE_PHY_CONTROL_REGS :: IDLE_PAD_CONTROL :: rxenb [08:08] */
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_rxenb_MASK         0x00000100
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_rxenb_ALIGN        0
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_rxenb_BITS         1
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_rxenb_SHIFT        8
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_rxenb_DEFAULT 1

/* DDR40_CORE_PHY_CONTROL_REGS :: IDLE_PAD_CONTROL :: reserved1 [07:07] */
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_reserved1_MASK     0x00000080
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_reserved1_ALIGN    0
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_reserved1_BITS     1
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_reserved1_SHIFT    7

/* DDR40_CORE_PHY_CONTROL_REGS :: IDLE_PAD_CONTROL :: ctl_iddq [06:06] */
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_ctl_iddq_MASK      0x00000040
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_ctl_iddq_ALIGN     0
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_ctl_iddq_BITS      1
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_ctl_iddq_SHIFT     6
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_ctl_iddq_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: IDLE_PAD_CONTROL :: ctl_reb [05:05] */
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_ctl_reb_MASK       0x00000020
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_ctl_reb_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_ctl_reb_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_ctl_reb_SHIFT      5
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_ctl_reb_DEFAULT 1

/* DDR40_CORE_PHY_CONTROL_REGS :: IDLE_PAD_CONTROL :: ctl_oeb [04:04] */
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_ctl_oeb_MASK       0x00000010
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_ctl_oeb_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_ctl_oeb_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_ctl_oeb_SHIFT      4
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_ctl_oeb_DEFAULT 1

/* DDR40_CORE_PHY_CONTROL_REGS :: IDLE_PAD_CONTROL :: reserved2 [03:03] */
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_reserved2_MASK     0x00000008
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_reserved2_ALIGN    0
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_reserved2_BITS     1
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_reserved2_SHIFT    3

/* DDR40_CORE_PHY_CONTROL_REGS :: IDLE_PAD_CONTROL :: cke_iddq [02:02] */
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_cke_iddq_MASK      0x00000004
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_cke_iddq_ALIGN     0
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_cke_iddq_BITS      1
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_cke_iddq_SHIFT     2
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_cke_iddq_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: IDLE_PAD_CONTROL :: cke_reb [01:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_cke_reb_MASK       0x00000002
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_cke_reb_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_cke_reb_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_cke_reb_SHIFT      1
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_cke_reb_DEFAULT 1

/* DDR40_CORE_PHY_CONTROL_REGS :: IDLE_PAD_CONTROL :: cke_oeb [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_cke_oeb_MASK       0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_cke_oeb_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_cke_oeb_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_cke_oeb_SHIFT      0
#define DDR40_CORE_PHY_CONTROL_REGS_IDLE_PAD_CONTROL_cke_oeb_DEFAULT 0

/***************************************************************************
 *ZQ_PVT_COMP_CTL - PVT Compensation control and status register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: ZQ_PVT_COMP_CTL :: reserved0 [31:26] */
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_reserved0_MASK      0xfc000000
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_reserved0_ALIGN     0
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_reserved0_BITS      6
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_reserved0_SHIFT     26

/* DDR40_CORE_PHY_CONTROL_REGS :: ZQ_PVT_COMP_CTL :: update_mode [25:25] */
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_update_mode_MASK    0x02000000
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_update_mode_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_update_mode_BITS    1
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_update_mode_SHIFT   25
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_update_mode_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: ZQ_PVT_COMP_CTL :: pd_done [24:24] */
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_pd_done_MASK        0x01000000
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_pd_done_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_pd_done_BITS        1
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_pd_done_SHIFT       24
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_pd_done_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: ZQ_PVT_COMP_CTL :: nd_done [23:23] */
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_nd_done_MASK        0x00800000
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_nd_done_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_nd_done_BITS        1
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_nd_done_SHIFT       23
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_nd_done_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: ZQ_PVT_COMP_CTL :: sample_done [22:22] */
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_sample_done_MASK    0x00400000
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_sample_done_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_sample_done_BITS    1
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_sample_done_SHIFT   22
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_sample_done_DEFAULT 1

/* DDR40_CORE_PHY_CONTROL_REGS :: ZQ_PVT_COMP_CTL :: auto_sample_en [21:21] */
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_auto_sample_en_MASK 0x00200000
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_auto_sample_en_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_auto_sample_en_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_auto_sample_en_SHIFT 21
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_auto_sample_en_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: ZQ_PVT_COMP_CTL :: sample_en [20:20] */
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_sample_en_MASK      0x00100000
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_sample_en_ALIGN     0
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_sample_en_BITS      1
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_sample_en_SHIFT     20
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_sample_en_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: ZQ_PVT_COMP_CTL :: addr_ovr_en [19:19] */
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_addr_ovr_en_MASK    0x00080000
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_addr_ovr_en_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_addr_ovr_en_BITS    1
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_addr_ovr_en_SHIFT   19
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_addr_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: ZQ_PVT_COMP_CTL :: dq_ovr_en [18:18] */
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_dq_ovr_en_MASK      0x00040000
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_dq_ovr_en_ALIGN     0
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_dq_ovr_en_BITS      1
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_dq_ovr_en_SHIFT     18
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_dq_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: ZQ_PVT_COMP_CTL :: pd_comp [17:15] */
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_pd_comp_MASK        0x00038000
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_pd_comp_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_pd_comp_BITS        3
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_pd_comp_SHIFT       15
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_pd_comp_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: ZQ_PVT_COMP_CTL :: nd_comp [14:12] */
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_nd_comp_MASK        0x00007000
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_nd_comp_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_nd_comp_BITS        3
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_nd_comp_SHIFT       12
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_nd_comp_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: ZQ_PVT_COMP_CTL :: addr_pd_override_val [11:09] */
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_addr_pd_override_val_MASK 0x00000e00
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_addr_pd_override_val_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_addr_pd_override_val_BITS 3
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_addr_pd_override_val_SHIFT 9
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_addr_pd_override_val_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: ZQ_PVT_COMP_CTL :: addr_nd_override_val [08:06] */
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_addr_nd_override_val_MASK 0x000001c0
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_addr_nd_override_val_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_addr_nd_override_val_BITS 3
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_addr_nd_override_val_SHIFT 6
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_addr_nd_override_val_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: ZQ_PVT_COMP_CTL :: dq_pd_override_val [05:03] */
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_dq_pd_override_val_MASK 0x00000038
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_dq_pd_override_val_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_dq_pd_override_val_BITS 3
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_dq_pd_override_val_SHIFT 3
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_dq_pd_override_val_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: ZQ_PVT_COMP_CTL :: dq_nd_override_val [02:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_dq_nd_override_val_MASK 0x00000007
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_dq_nd_override_val_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_dq_nd_override_val_BITS 3
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_dq_nd_override_val_SHIFT 0
#define DDR40_CORE_PHY_CONTROL_REGS_ZQ_PVT_COMP_CTL_dq_nd_override_val_DEFAULT 0

/***************************************************************************
 *DRIVE_PAD_CTL - SSTL pad drive characteristics control register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: DRIVE_PAD_CTL :: reserved0 [31:14] */
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_reserved0_MASK        0xffffc000
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_reserved0_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_reserved0_BITS        18
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_reserved0_SHIFT       14

/* DDR40_CORE_PHY_CONTROL_REGS :: DRIVE_PAD_CTL :: auto_oeb [13:13] */
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_auto_oeb_MASK         0x00002000
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_auto_oeb_ALIGN        0
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_auto_oeb_BITS         1
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_auto_oeb_SHIFT        13
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_auto_oeb_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: DRIVE_PAD_CTL :: iddq_a15 [12:12] */
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_a15_MASK         0x00001000
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_a15_ALIGN        0
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_a15_BITS         1
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_a15_SHIFT        12
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_a15_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: DRIVE_PAD_CTL :: iddq_a14 [11:11] */
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_a14_MASK         0x00000800
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_a14_ALIGN        0
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_a14_BITS         1
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_a14_SHIFT        11
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_a14_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: DRIVE_PAD_CTL :: iddq_a13 [10:10] */
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_a13_MASK         0x00000400
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_a13_ALIGN        0
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_a13_BITS         1
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_a13_SHIFT        10
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_a13_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: DRIVE_PAD_CTL :: iddq_aux [09:07] */
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_aux_MASK         0x00000380
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_aux_ALIGN        0
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_aux_BITS         3
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_aux_SHIFT        7
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_iddq_aux_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: DRIVE_PAD_CTL :: half_strength [06:06] */
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_half_strength_MASK    0x00000040
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_half_strength_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_half_strength_BITS    1
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_half_strength_SHIFT   6
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_half_strength_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: DRIVE_PAD_CTL :: gddr_symmetry [05:05] */
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_gddr_symmetry_MASK    0x00000020
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_gddr_symmetry_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_gddr_symmetry_BITS    1
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_gddr_symmetry_SHIFT   5
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_gddr_symmetry_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: DRIVE_PAD_CTL :: vddo_volts [04:03] */
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_vddo_volts_MASK       0x00000018
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_vddo_volts_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_vddo_volts_BITS       2
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_vddo_volts_SHIFT      3
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_vddo_volts_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: DRIVE_PAD_CTL :: rt60b [02:02] */
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_rt60b_MASK            0x00000004
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_rt60b_ALIGN           0
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_rt60b_BITS            1
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_rt60b_SHIFT           2
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_rt60b_DEFAULT    0

/* DDR40_CORE_PHY_CONTROL_REGS :: DRIVE_PAD_CTL :: rt120b_g [01:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_rt120b_g_MASK         0x00000002
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_rt120b_g_ALIGN        0
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_rt120b_g_BITS         1
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_rt120b_g_SHIFT        1
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_rt120b_g_DEFAULT 1

/* DDR40_CORE_PHY_CONTROL_REGS :: DRIVE_PAD_CTL :: g_ddr [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_g_ddr_MASK            0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_g_ddr_ALIGN           0
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_g_ddr_BITS            1
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_g_ddr_SHIFT           0
#define DDR40_CORE_PHY_CONTROL_REGS_DRIVE_PAD_CTL_g_ddr_DEFAULT    0

/***************************************************************************
 *VDL_RD_DATA_DLY_STATUS - PHY Auto Init rd_data_dly result register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_RD_DATA_DLY_STATUS :: reserved0 [31:12] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_reserved0_MASK 0xfffff000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_reserved0_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_reserved0_BITS 20
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_reserved0_SHIFT 12

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_RD_DATA_DLY_STATUS :: auto_init_state [11:06] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_auto_init_state_MASK 0x00000fc0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_auto_init_state_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_auto_init_state_BITS 6
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_auto_init_state_SHIFT 6
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_auto_init_state_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_RD_DATA_DLY_STATUS :: rd_data_dly_max [05:03] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_rd_data_dly_max_MASK 0x00000038
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_rd_data_dly_max_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_rd_data_dly_max_BITS 3
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_rd_data_dly_max_SHIFT 3
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_rd_data_dly_max_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_RD_DATA_DLY_STATUS :: rd_data_dly_min [02:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_rd_data_dly_min_MASK 0x00000007
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_rd_data_dly_min_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_rd_data_dly_min_BITS 3
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_rd_data_dly_min_SHIFT 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_DATA_DLY_STATUS_rd_data_dly_min_DEFAULT 7

/***************************************************************************
 *VDL_CALIBRATE - PHY VDL calibration control register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: reserved0 [31:30] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_reserved0_MASK        0xc0000000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_reserved0_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_reserved0_BITS        2
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_reserved0_SHIFT       30

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: single_cycle [29:29] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_single_cycle_MASK     0x20000000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_single_cycle_ALIGN    0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_single_cycle_BITS     1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_single_cycle_SHIFT    29
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_single_cycle_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: use_straps [28:28] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_use_straps_MASK       0x10000000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_use_straps_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_use_straps_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_use_straps_SHIFT      28
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_use_straps_DEFAULT 1

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: auto_init [27:27] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_auto_init_MASK        0x08000000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_auto_init_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_auto_init_BITS        1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_auto_init_SHIFT       27
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_auto_init_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: skip_rst [26:26] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_skip_rst_MASK         0x04000000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_skip_rst_ALIGN        0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_skip_rst_BITS         1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_skip_rst_SHIFT        26
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_skip_rst_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: exit_in_sr [25:25] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_exit_in_sr_MASK       0x02000000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_exit_in_sr_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_exit_in_sr_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_exit_in_sr_SHIFT      25
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_exit_in_sr_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: rd_dly_cal [24:24] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_rd_dly_cal_MASK       0x01000000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_rd_dly_cal_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_rd_dly_cal_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_rd_dly_cal_SHIFT      24
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_rd_dly_cal_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: bit_refresh [23:23] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_bit_refresh_MASK      0x00800000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_bit_refresh_ALIGN     0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_bit_refresh_BITS      1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_bit_refresh_SHIFT     23
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_bit_refresh_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: set_wr_dq [22:22] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_set_wr_dq_MASK        0x00400000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_set_wr_dq_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_set_wr_dq_BITS        1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_set_wr_dq_SHIFT       22
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_set_wr_dq_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: dq0_only [21:21] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_dq0_only_MASK         0x00200000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_dq0_only_ALIGN        0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_dq0_only_BITS         1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_dq0_only_SHIFT        21
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_dq0_only_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: set_mr_mpr [20:20] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_set_mr_mpr_MASK       0x00100000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_set_mr_mpr_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_set_mr_mpr_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_set_mr_mpr_SHIFT      20
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_set_mr_mpr_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: bit_cal [19:19] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_bit_cal_MASK          0x00080000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_bit_cal_ALIGN         0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_bit_cal_BITS          1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_bit_cal_SHIFT         19
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_bit_cal_DEFAULT  0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: rd_en_cal [18:18] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_rd_en_cal_MASK        0x00040000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_rd_en_cal_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_rd_en_cal_BITS        1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_rd_en_cal_SHIFT       18
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_rd_en_cal_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: calib_bit_offset [17:12] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_bit_offset_MASK 0x0003f000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_bit_offset_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_bit_offset_BITS 6
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_bit_offset_SHIFT 12
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_bit_offset_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: calib_dqs_clocks [11:11] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_dqs_clocks_MASK 0x00000800
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_dqs_clocks_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_dqs_clocks_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_dqs_clocks_SHIFT 11
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_dqs_clocks_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: calib_dqs_pair [10:10] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_dqs_pair_MASK   0x00000400
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_dqs_pair_ALIGN  0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_dqs_pair_BITS   1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_dqs_pair_SHIFT  10
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_dqs_pair_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: calib_steps [09:09] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_steps_MASK      0x00000200
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_steps_ALIGN     0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_steps_BITS      1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_steps_SHIFT     9
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_steps_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: calib_auto [08:08] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_auto_MASK       0x00000100
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_auto_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_auto_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_auto_SHIFT      8
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_auto_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: calib_ftm [07:07] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_ftm_MASK        0x00000080
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_ftm_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_ftm_BITS        1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_ftm_SHIFT       7
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_ftm_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: calib_phybist [06:06] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_phybist_MASK    0x00000040
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_phybist_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_phybist_BITS    1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_phybist_SHIFT   6
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_phybist_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: calib_byte [05:05] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_byte_MASK       0x00000020
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_byte_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_byte_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_byte_SHIFT      5
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_byte_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: calib_clocks [04:04] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_clocks_MASK     0x00000010
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_clocks_ALIGN    0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_clocks_BITS     1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_clocks_SHIFT    4
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_clocks_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: calib_test [03:03] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_test_MASK       0x00000008
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_test_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_test_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_test_SHIFT      3
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_test_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: calib_always [02:02] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_always_MASK     0x00000004
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_always_ALIGN    0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_always_BITS     1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_always_SHIFT    2
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_always_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: calib_once [01:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_once_MASK       0x00000002
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_once_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_once_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_once_SHIFT      1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_once_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIBRATE :: calib_fast [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_fast_MASK       0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_fast_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_fast_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_fast_SHIFT      0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIBRATE_calib_fast_DEFAULT 0

/***************************************************************************
 *VDL_CALIB_STATUS - PHY VDL calibration status register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIB_STATUS :: reserved0 [31:30] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_reserved0_MASK     0xc0000000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_reserved0_ALIGN    0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_reserved0_BITS     2
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_reserved0_SHIFT    30

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIB_STATUS :: auto_init_fail [29:29] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_auto_init_fail_MASK 0x20000000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_auto_init_fail_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_auto_init_fail_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_auto_init_fail_SHIFT 29
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_auto_init_fail_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIB_STATUS :: auto_init_done [28:28] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_auto_init_done_MASK 0x10000000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_auto_init_done_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_auto_init_done_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_auto_init_done_SHIFT 28
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_auto_init_done_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIB_STATUS :: calib_rd_data_dly_error [27:27] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_rd_data_dly_error_MASK 0x08000000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_rd_data_dly_error_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_rd_data_dly_error_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_rd_data_dly_error_SHIFT 27
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_rd_data_dly_error_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIB_STATUS :: calib_read_en_error [26:23] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_read_en_error_MASK 0x07800000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_read_en_error_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_read_en_error_BITS 4
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_read_en_error_SHIFT 23
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_read_en_error_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIB_STATUS :: calib_byte_error [22:19] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_byte_error_MASK 0x00780000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_byte_error_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_byte_error_BITS 4
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_byte_error_SHIFT 19
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_byte_error_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIB_STATUS :: calib_byte_sel [18:18] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_byte_sel_MASK 0x00040000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_byte_sel_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_byte_sel_SHIFT 18
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIB_STATUS :: calib_bit_offset [17:12] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_bit_offset_MASK 0x0003f000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_bit_offset_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_bit_offset_BITS 6
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_bit_offset_SHIFT 12
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_bit_offset_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIB_STATUS :: calib_total [11:02] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_total_MASK   0x00000ffc
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_total_ALIGN  0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_total_BITS   10
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_total_SHIFT  2
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_total_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIB_STATUS :: calib_lock [01:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_lock_MASK    0x00000002
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_lock_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_lock_BITS    1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_lock_SHIFT   1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_lock_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_CALIB_STATUS :: calib_idle [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_idle_MASK    0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_idle_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_idle_BITS    1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_idle_SHIFT   0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_CALIB_STATUS_calib_idle_DEFAULT 1

/***************************************************************************
 *VDL_DQ_CALIB_STATUS - PHY DQ VDL calibration status register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_DQ_CALIB_STATUS :: reserved0 [31:26] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_reserved0_MASK  0xfc000000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_reserved0_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_reserved0_BITS  6
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_reserved0_SHIFT 26

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_DQ_CALIB_STATUS :: dqs_calib_total [25:16] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_total_MASK 0x03ff0000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_total_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_total_BITS 10
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_total_SHIFT 16
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_total_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_DQ_CALIB_STATUS :: reserved1 [15:14] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_reserved1_MASK  0x0000c000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_reserved1_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_reserved1_BITS  2
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_reserved1_SHIFT 14

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_DQ_CALIB_STATUS :: dq_calib_total [13:04] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dq_calib_total_MASK 0x00003ff0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dq_calib_total_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dq_calib_total_BITS 10
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dq_calib_total_SHIFT 4
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dq_calib_total_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_DQ_CALIB_STATUS :: dqs_calib_clocks [03:03] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_clocks_MASK 0x00000008
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_clocks_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_clocks_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_clocks_SHIFT 3
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_clocks_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_DQ_CALIB_STATUS :: dqs_calib_mode [02:02] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_mode_MASK 0x00000004
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_mode_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_mode_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_mode_SHIFT 2
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_mode_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_DQ_CALIB_STATUS :: dqs_calib_lock [01:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_lock_MASK 0x00000002
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_lock_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_lock_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_lock_SHIFT 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dqs_calib_lock_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_DQ_CALIB_STATUS :: dq_calib_lock [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dq_calib_lock_MASK 0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dq_calib_lock_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dq_calib_lock_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dq_calib_lock_SHIFT 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_DQ_CALIB_STATUS_dq_calib_lock_DEFAULT 0

/***************************************************************************
 *VDL_WR_CHAN_CALIB_STATUS - PHY Write Channel VDL calibration status register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_WR_CHAN_CALIB_STATUS :: reserved0 [31:22] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_reserved0_MASK 0xffc00000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_reserved0_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_reserved0_BITS 10
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_reserved0_SHIFT 22

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_WR_CHAN_CALIB_STATUS :: wr_chan_calib_bit_offset [21:16] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_bit_offset_MASK 0x003f0000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_bit_offset_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_bit_offset_BITS 6
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_bit_offset_SHIFT 16
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_bit_offset_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_WR_CHAN_CALIB_STATUS :: reserved1 [15:14] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_reserved1_MASK 0x0000c000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_reserved1_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_reserved1_BITS 2
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_reserved1_SHIFT 14

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_WR_CHAN_CALIB_STATUS :: wr_chan_calib_total [13:04] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_total_MASK 0x00003ff0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_total_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_total_BITS 10
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_total_SHIFT 4
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_total_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_WR_CHAN_CALIB_STATUS :: reserved2 [03:03] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_reserved2_MASK 0x00000008
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_reserved2_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_reserved2_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_reserved2_SHIFT 3

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_WR_CHAN_CALIB_STATUS :: wr_chan_calib_clocks [02:02] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_clocks_MASK 0x00000004
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_clocks_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_clocks_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_clocks_SHIFT 2
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_clocks_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_WR_CHAN_CALIB_STATUS :: wr_chan_calib_byte_sel [01:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_byte_sel_MASK 0x00000002
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_byte_sel_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_byte_sel_SHIFT 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_WR_CHAN_CALIB_STATUS :: wr_chan_calib_lock [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_lock_MASK 0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_lock_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_lock_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_lock_SHIFT 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_WR_CHAN_CALIB_STATUS_wr_chan_calib_lock_DEFAULT 0

/***************************************************************************
 *VDL_RD_EN_CALIB_STATUS - PHY Read Enable VDL calibration status register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_RD_EN_CALIB_STATUS :: reserved0 [31:22] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_reserved0_MASK 0xffc00000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_reserved0_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_reserved0_BITS 10
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_reserved0_SHIFT 22

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_RD_EN_CALIB_STATUS :: rd_en_calib_bit_offset [21:16] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_bit_offset_MASK 0x003f0000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_bit_offset_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_bit_offset_BITS 6
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_bit_offset_SHIFT 16
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_bit_offset_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_RD_EN_CALIB_STATUS :: reserved1 [15:14] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_reserved1_MASK 0x0000c000
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_reserved1_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_reserved1_BITS 2
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_reserved1_SHIFT 14

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_RD_EN_CALIB_STATUS :: rd_en_calib_total [13:04] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_total_MASK 0x00003ff0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_total_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_total_BITS 10
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_total_SHIFT 4
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_total_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_RD_EN_CALIB_STATUS :: reserved2 [03:03] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_reserved2_MASK 0x00000008
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_reserved2_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_reserved2_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_reserved2_SHIFT 3

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_RD_EN_CALIB_STATUS :: rd_en_calib_clocks [02:02] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_clocks_MASK 0x00000004
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_clocks_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_clocks_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_clocks_SHIFT 2
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_clocks_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_RD_EN_CALIB_STATUS :: rd_en_calib_byte_sel [01:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_byte_sel_MASK 0x00000002
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_byte_sel_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_byte_sel_SHIFT 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VDL_RD_EN_CALIB_STATUS :: rd_en_calib_lock [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_lock_MASK 0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_lock_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_lock_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_lock_SHIFT 0
#define DDR40_CORE_PHY_CONTROL_REGS_VDL_RD_EN_CALIB_STATUS_rd_en_calib_lock_DEFAULT 0

/***************************************************************************
 *VIRTUAL_VTT_CONTROL - Virtual VTT Control and Status register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: VIRTUAL_VTT_CONTROL :: reserved0 [31:06] */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_reserved0_MASK  0xffffffc0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_reserved0_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_reserved0_BITS  26
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_reserved0_SHIFT 6

/* DDR40_CORE_PHY_CONTROL_REGS :: VIRTUAL_VTT_CONTROL :: low_vtt [05:05] */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_low_vtt_MASK    0x00000020
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_low_vtt_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_low_vtt_BITS    1
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_low_vtt_SHIFT   5
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_low_vtt_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VIRTUAL_VTT_CONTROL :: high_vtt [04:04] */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_high_vtt_MASK   0x00000010
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_high_vtt_ALIGN  0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_high_vtt_BITS   1
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_high_vtt_SHIFT  4
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_high_vtt_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VIRTUAL_VTT_CONTROL :: error_reset [03:03] */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_error_reset_MASK 0x00000008
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_error_reset_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_error_reset_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_error_reset_SHIFT 3
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_error_reset_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VIRTUAL_VTT_CONTROL :: enable_ctl_idle [02:02] */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_enable_ctl_idle_MASK 0x00000004
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_enable_ctl_idle_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_enable_ctl_idle_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_enable_ctl_idle_SHIFT 2
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_enable_ctl_idle_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VIRTUAL_VTT_CONTROL :: enable_cs_idle [01:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_enable_cs_idle_MASK 0x00000002
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_enable_cs_idle_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_enable_cs_idle_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_enable_cs_idle_SHIFT 1
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_enable_cs_idle_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VIRTUAL_VTT_CONTROL :: enable_cke_idle [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_enable_cke_idle_MASK 0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_enable_cke_idle_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_enable_cke_idle_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_enable_cke_idle_SHIFT 0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONTROL_enable_cke_idle_DEFAULT 0

/***************************************************************************
 *VIRTUAL_VTT_STATUS - Virtual VTT Control and Status register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: VIRTUAL_VTT_STATUS :: reserved0 [31:19] */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_reserved0_MASK   0xfff80000
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_reserved0_ALIGN  0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_reserved0_BITS   13
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_reserved0_SHIFT  19

/* DDR40_CORE_PHY_CONTROL_REGS :: VIRTUAL_VTT_STATUS :: error [18:03] */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_error_MASK       0x0007fff8
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_error_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_error_BITS       16
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_error_SHIFT      3
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_error_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VIRTUAL_VTT_STATUS :: error_low [02:02] */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_error_low_MASK   0x00000004
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_error_low_ALIGN  0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_error_low_BITS   1
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_error_low_SHIFT  2
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_error_low_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VIRTUAL_VTT_STATUS :: error_high [01:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_error_high_MASK  0x00000002
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_error_high_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_error_high_BITS  1
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_error_high_SHIFT 1
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_error_high_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VIRTUAL_VTT_STATUS :: ready [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_ready_MASK       0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_ready_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_ready_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_ready_SHIFT      0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_STATUS_ready_DEFAULT 0

/***************************************************************************
 *VIRTUAL_VTT_CONNECTIONS - Virtual VTT Connections register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: VIRTUAL_VTT_CONNECTIONS :: reserved0 [31:27] */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONNECTIONS_reserved0_MASK 0xf8000000
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONNECTIONS_reserved0_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONNECTIONS_reserved0_BITS 5
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONNECTIONS_reserved0_SHIFT 27

/* DDR40_CORE_PHY_CONTROL_REGS :: VIRTUAL_VTT_CONNECTIONS :: mask [26:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONNECTIONS_mask_MASK   0x07ffffff
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONNECTIONS_mask_ALIGN  0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONNECTIONS_mask_BITS   27
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONNECTIONS_mask_SHIFT  0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_CONNECTIONS_mask_DEFAULT 16777215

/***************************************************************************
 *VIRTUAL_VTT_OVERRIDE - Virtual VTT Override register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: VIRTUAL_VTT_OVERRIDE :: reserved0 [31:27] */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_OVERRIDE_reserved0_MASK 0xf8000000
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_OVERRIDE_reserved0_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_OVERRIDE_reserved0_BITS 5
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_OVERRIDE_reserved0_SHIFT 27

/* DDR40_CORE_PHY_CONTROL_REGS :: VIRTUAL_VTT_OVERRIDE :: mask [26:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_OVERRIDE_mask_MASK      0x07ffffff
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_OVERRIDE_mask_ALIGN     0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_OVERRIDE_mask_BITS      27
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_OVERRIDE_mask_SHIFT     0
#define DDR40_CORE_PHY_CONTROL_REGS_VIRTUAL_VTT_OVERRIDE_mask_DEFAULT 262143

/***************************************************************************
 *VREF_DAC_CONTROL - VREF DAC Control register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: VREF_DAC_CONTROL :: reserved0 [31:21] */
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_reserved0_MASK     0xffe00000
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_reserved0_ALIGN    0
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_reserved0_BITS     11
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_reserved0_SHIFT    21

/* DDR40_CORE_PHY_CONTROL_REGS :: VREF_DAC_CONTROL :: LDO_CK1_GT_INT [20:20] */
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_CK1_GT_INT_MASK 0x00100000
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_CK1_GT_INT_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_CK1_GT_INT_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_CK1_GT_INT_SHIFT 20
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_CK1_GT_INT_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VREF_DAC_CONTROL :: LDO_CK0_GT_INT [19:19] */
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_CK0_GT_INT_MASK 0x00080000
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_CK0_GT_INT_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_CK0_GT_INT_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_CK0_GT_INT_SHIFT 19
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_CK0_GT_INT_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VREF_DAC_CONTROL :: LDO_GT_INT [18:18] */
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_GT_INT_MASK    0x00040000
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_GT_INT_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_GT_INT_BITS    1
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_GT_INT_SHIFT   18
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_GT_INT_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VREF_DAC_CONTROL :: EXT_GT_INT [17:17] */
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_EXT_GT_INT_MASK    0x00020000
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_EXT_GT_INT_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_EXT_GT_INT_BITS    1
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_EXT_GT_INT_SHIFT   17
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_EXT_GT_INT_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VREF_DAC_CONTROL :: LDO_TESTOUT_MUX_CTL [16:15] */
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_TESTOUT_MUX_CTL_MASK 0x00018000
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_TESTOUT_MUX_CTL_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_TESTOUT_MUX_CTL_BITS 2
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_TESTOUT_MUX_CTL_SHIFT 15
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_LDO_TESTOUT_MUX_CTL_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: VREF_DAC_CONTROL :: TEST [14:14] */
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_TEST_MASK          0x00004000
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_TEST_ALIGN         0
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_TEST_BITS          1
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_TEST_SHIFT         14
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_TEST_DEFAULT  0

/* DDR40_CORE_PHY_CONTROL_REGS :: VREF_DAC_CONTROL :: PDN1 [13:13] */
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_PDN1_MASK          0x00002000
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_PDN1_ALIGN         0
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_PDN1_BITS          1
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_PDN1_SHIFT         13
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_PDN1_DEFAULT  0

/* DDR40_CORE_PHY_CONTROL_REGS :: VREF_DAC_CONTROL :: PDN0 [12:12] */
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_PDN0_MASK          0x00001000
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_PDN0_ALIGN         0
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_PDN0_BITS          1
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_PDN0_SHIFT         12
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_PDN0_DEFAULT  0

/* DDR40_CORE_PHY_CONTROL_REGS :: VREF_DAC_CONTROL :: DAC1 [11:06] */
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_DAC1_MASK          0x00000fc0
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_DAC1_ALIGN         0
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_DAC1_BITS          6
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_DAC1_SHIFT         6
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_DAC1_DEFAULT  32

/* DDR40_CORE_PHY_CONTROL_REGS :: VREF_DAC_CONTROL :: DAC0 [05:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_DAC0_MASK          0x0000003f
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_DAC0_ALIGN         0
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_DAC0_BITS          6
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_DAC0_SHIFT         0
#define DDR40_CORE_PHY_CONTROL_REGS_VREF_DAC_CONTROL_DAC0_DEFAULT  32

/***************************************************************************
 *PHYBIST_CNTRL - PhyBist Control Register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_CNTRL :: reserved0 [31:14] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_reserved0_MASK        0xffffc000
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_reserved0_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_reserved0_BITS        18
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_reserved0_SHIFT       14

/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_CNTRL :: force_error_sel [13:08] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_force_error_sel_MASK  0x00003f00
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_force_error_sel_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_force_error_sel_BITS  6
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_force_error_sel_SHIFT 8
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_force_error_sel_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_CNTRL :: reserved1 [07:05] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_reserved1_MASK        0x000000e0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_reserved1_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_reserved1_BITS        3
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_reserved1_SHIFT       5

/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_CNTRL :: bench_mode [04:04] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_bench_mode_MASK       0x00000010
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_bench_mode_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_bench_mode_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_bench_mode_SHIFT      4
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_bench_mode_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_CNTRL :: force_dat_error [03:03] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_force_dat_error_MASK  0x00000008
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_force_dat_error_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_force_dat_error_BITS  1
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_force_dat_error_SHIFT 3
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_force_dat_error_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_CNTRL :: force_ctl_error [02:02] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_force_ctl_error_MASK  0x00000004
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_force_ctl_error_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_force_ctl_error_BITS  1
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_force_ctl_error_SHIFT 2
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_force_ctl_error_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_CNTRL :: int_loopback [01:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_int_loopback_MASK     0x00000002
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_int_loopback_ALIGN    0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_int_loopback_BITS     1
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_int_loopback_SHIFT    1
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_int_loopback_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_CNTRL :: enable [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_enable_MASK           0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_enable_ALIGN          0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_enable_BITS           1
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_enable_SHIFT          0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CNTRL_enable_DEFAULT   0

/***************************************************************************
 *PHYBIST_SEED - PhyBist Seed Register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_SEED :: seed [31:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_SEED_seed_MASK              0xffffffff
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_SEED_seed_ALIGN             0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_SEED_seed_BITS              32
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_SEED_seed_SHIFT             0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_SEED_seed_DEFAULT      621693686

/***************************************************************************
 *PHYBIST_STATUS - PhyBist General Status Register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_STATUS :: reserved0 [31:04] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_reserved0_MASK       0xfffffff0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_reserved0_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_reserved0_BITS       28
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_reserved0_SHIFT      4

/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_STATUS :: dat_pass [03:03] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_dat_pass_MASK        0x00000008
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_dat_pass_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_dat_pass_BITS        1
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_dat_pass_SHIFT       3

/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_STATUS :: ctl_pass [02:02] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_ctl_pass_MASK        0x00000004
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_ctl_pass_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_ctl_pass_BITS        1
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_ctl_pass_SHIFT       2

/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_STATUS :: dat_done [01:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_dat_done_MASK        0x00000002
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_dat_done_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_dat_done_BITS        1
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_dat_done_SHIFT       1

/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_STATUS :: ctl_done [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_ctl_done_MASK        0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_ctl_done_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_ctl_done_BITS        1
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_STATUS_ctl_done_SHIFT       0

/***************************************************************************
 *PHYBIST_CTL_STATUS - PhyBist Per-Bit Control Pad Status Register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_CTL_STATUS :: reserved0 [31:27] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CTL_STATUS_reserved0_MASK   0xf8000000
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CTL_STATUS_reserved0_ALIGN  0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CTL_STATUS_reserved0_BITS   5
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CTL_STATUS_reserved0_SHIFT  27

/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_CTL_STATUS :: ctl_errors [26:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CTL_STATUS_ctl_errors_MASK  0x07ffffff
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CTL_STATUS_ctl_errors_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CTL_STATUS_ctl_errors_BITS  27
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_CTL_STATUS_ctl_errors_SHIFT 0

/***************************************************************************
 *PHYBIST_DQ_STATUS - PhyBist Per-Bit DQ Pad Status Register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_DQ_STATUS :: dat_errors [31:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_DQ_STATUS_dat_errors_MASK   0xffffffff
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_DQ_STATUS_dat_errors_ALIGN  0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_DQ_STATUS_dat_errors_BITS   32
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_DQ_STATUS_dat_errors_SHIFT  0

/***************************************************************************
 *PHYBIST_MISC_STATUS - PhyBist Per-Bit DM and CK Pad Status Register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_MISC_STATUS :: reserved0 [31:08] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_MISC_STATUS_reserved0_MASK  0xffffff00
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_MISC_STATUS_reserved0_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_MISC_STATUS_reserved0_BITS  24
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_MISC_STATUS_reserved0_SHIFT 8

/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_MISC_STATUS :: ck_errors [07:04] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_MISC_STATUS_ck_errors_MASK  0x000000f0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_MISC_STATUS_ck_errors_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_MISC_STATUS_ck_errors_BITS  4
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_MISC_STATUS_ck_errors_SHIFT 4

/* DDR40_CORE_PHY_CONTROL_REGS :: PHYBIST_MISC_STATUS :: dm_errors [03:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_MISC_STATUS_dm_errors_MASK  0x0000000f
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_MISC_STATUS_dm_errors_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_MISC_STATUS_dm_errors_BITS  4
#define DDR40_CORE_PHY_CONTROL_REGS_PHYBIST_MISC_STATUS_dm_errors_SHIFT 0

/***************************************************************************
 *COMMAND_REG - DRAM Command Register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: COMMAND_REG :: reserved0 [31:29] */
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_reserved0_MASK          0xe0000000
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_reserved0_ALIGN         0
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_reserved0_BITS          3
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_reserved0_SHIFT         29

/* DDR40_CORE_PHY_CONTROL_REGS :: COMMAND_REG :: mpr_mode [28:28] */
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_mpr_mode_MASK           0x10000000
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_mpr_mode_ALIGN          0
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_mpr_mode_BITS           1
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_mpr_mode_SHIFT          28
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_mpr_mode_DEFAULT   0

/* DDR40_CORE_PHY_CONTROL_REGS :: COMMAND_REG :: reserved1 [27:25] */
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_reserved1_MASK          0x0e000000
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_reserved1_ALIGN         0
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_reserved1_BITS          3
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_reserved1_SHIFT         25

/* DDR40_CORE_PHY_CONTROL_REGS :: COMMAND_REG :: aux [24:22] */
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_aux_MASK                0x01c00000
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_aux_ALIGN               0
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_aux_BITS                3
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_aux_SHIFT               22
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_aux_DEFAULT        0

/* DDR40_CORE_PHY_CONTROL_REGS :: COMMAND_REG :: we [21:21] */
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_we_MASK                 0x00200000
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_we_ALIGN                0
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_we_BITS                 1
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_we_SHIFT                21
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_we_DEFAULT         0

/* DDR40_CORE_PHY_CONTROL_REGS :: COMMAND_REG :: cas [20:20] */
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_cas_MASK                0x00100000
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_cas_ALIGN               0
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_cas_BITS                1
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_cas_SHIFT               20
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_cas_DEFAULT        0

/* DDR40_CORE_PHY_CONTROL_REGS :: COMMAND_REG :: ras [19:19] */
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_ras_MASK                0x00080000
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_ras_ALIGN               0
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_ras_BITS                1
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_ras_SHIFT               19
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_ras_DEFAULT        0

/* DDR40_CORE_PHY_CONTROL_REGS :: COMMAND_REG :: ba [18:16] */
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_ba_MASK                 0x00070000
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_ba_ALIGN                0
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_ba_BITS                 3
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_ba_SHIFT                16
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_ba_DEFAULT         0

/* DDR40_CORE_PHY_CONTROL_REGS :: COMMAND_REG :: ad [15:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_ad_MASK                 0x0000ffff
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_ad_ALIGN                0
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_ad_BITS                 16
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_ad_SHIFT                0
#define DDR40_CORE_PHY_CONTROL_REGS_COMMAND_REG_ad_DEFAULT         0

/***************************************************************************
 *MODE_REG0 - Mode Register 0
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: MODE_REG0 :: reserved0 [31:17] */
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG0_reserved0_MASK            0xfffe0000
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG0_reserved0_ALIGN           0
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG0_reserved0_BITS            15
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG0_reserved0_SHIFT           17

/* DDR40_CORE_PHY_CONTROL_REGS :: MODE_REG0 :: valid [16:16] */
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG0_valid_MASK                0x00010000
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG0_valid_ALIGN               0
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG0_valid_BITS                1
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG0_valid_SHIFT               16
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG0_valid_DEFAULT        0

/* DDR40_CORE_PHY_CONTROL_REGS :: MODE_REG0 :: ad [15:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG0_ad_MASK                   0x0000ffff
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG0_ad_ALIGN                  0
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG0_ad_BITS                   16
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG0_ad_SHIFT                  0
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG0_ad_DEFAULT           0

/***************************************************************************
 *MODE_REG1 - Mode Register 1
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: MODE_REG1 :: reserved0 [31:17] */
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG1_reserved0_MASK            0xfffe0000
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG1_reserved0_ALIGN           0
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG1_reserved0_BITS            15
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG1_reserved0_SHIFT           17

/* DDR40_CORE_PHY_CONTROL_REGS :: MODE_REG1 :: valid [16:16] */
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG1_valid_MASK                0x00010000
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG1_valid_ALIGN               0
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG1_valid_BITS                1
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG1_valid_SHIFT               16
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG1_valid_DEFAULT        0

/* DDR40_CORE_PHY_CONTROL_REGS :: MODE_REG1 :: ad [15:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG1_ad_MASK                   0x0000ffff
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG1_ad_ALIGN                  0
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG1_ad_BITS                   16
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG1_ad_SHIFT                  0
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG1_ad_DEFAULT           0

/***************************************************************************
 *MODE_REG2 - Mode Register 2
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: MODE_REG2 :: reserved0 [31:17] */
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG2_reserved0_MASK            0xfffe0000
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG2_reserved0_ALIGN           0
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG2_reserved0_BITS            15
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG2_reserved0_SHIFT           17

/* DDR40_CORE_PHY_CONTROL_REGS :: MODE_REG2 :: valid [16:16] */
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG2_valid_MASK                0x00010000
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG2_valid_ALIGN               0
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG2_valid_BITS                1
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG2_valid_SHIFT               16
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG2_valid_DEFAULT        0

/* DDR40_CORE_PHY_CONTROL_REGS :: MODE_REG2 :: ad [15:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG2_ad_MASK                   0x0000ffff
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG2_ad_ALIGN                  0
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG2_ad_BITS                   16
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG2_ad_SHIFT                  0
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG2_ad_DEFAULT           0

/***************************************************************************
 *MODE_REG3 - Mode Register 3
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: MODE_REG3 :: reserved0 [31:17] */
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG3_reserved0_MASK            0xfffe0000
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG3_reserved0_ALIGN           0
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG3_reserved0_BITS            15
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG3_reserved0_SHIFT           17

/* DDR40_CORE_PHY_CONTROL_REGS :: MODE_REG3 :: valid [16:16] */
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG3_valid_MASK                0x00010000
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG3_valid_ALIGN               0
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG3_valid_BITS                1
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG3_valid_SHIFT               16
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG3_valid_DEFAULT        0

/* DDR40_CORE_PHY_CONTROL_REGS :: MODE_REG3 :: ad [15:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG3_ad_MASK                   0x0000ffff
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG3_ad_ALIGN                  0
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG3_ad_BITS                   16
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG3_ad_SHIFT                  0
#define DDR40_CORE_PHY_CONTROL_REGS_MODE_REG3_ad_DEFAULT           0

/***************************************************************************
 *STANDBY_CONTROL - Standby Control register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: STANDBY_CONTROL :: reserved0 [31:19] */
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_reserved0_MASK      0xfff80000
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_reserved0_ALIGN     0
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_reserved0_BITS      13
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_reserved0_SHIFT     19

/* DDR40_CORE_PHY_CONTROL_REGS :: STANDBY_CONTROL :: standby_ready [18:18] */
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_ready_MASK  0x00040000
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_ready_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_ready_BITS  1
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_ready_SHIFT 18
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_ready_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: STANDBY_CONTROL :: standby_exit_pin_en [17:17] */
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_exit_pin_en_MASK 0x00020000
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_exit_pin_en_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_exit_pin_en_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_exit_pin_en_SHIFT 17
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_exit_pin_en_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: STANDBY_CONTROL :: standby_active [16:16] */
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_active_MASK 0x00010000
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_active_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_active_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_active_SHIFT 16
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_active_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: STANDBY_CONTROL :: armed [15:15] */
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_armed_MASK          0x00008000
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_armed_ALIGN         0
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_armed_BITS          1
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_armed_SHIFT         15
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_armed_DEFAULT  0

/* DDR40_CORE_PHY_CONTROL_REGS :: STANDBY_CONTROL :: warmstart [14:14] */
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_warmstart_MASK      0x00004000
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_warmstart_ALIGN     0
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_warmstart_BITS      1
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_warmstart_SHIFT     14
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_warmstart_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: STANDBY_CONTROL :: pwrdown_ldo_volts [13:12] */
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_ldo_volts_MASK 0x00003000
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_ldo_volts_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_ldo_volts_BITS 2
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_ldo_volts_SHIFT 12
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_ldo_volts_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: STANDBY_CONTROL :: pwrdown_skip_mrs [11:11] */
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_skip_mrs_MASK 0x00000800
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_skip_mrs_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_skip_mrs_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_skip_mrs_SHIFT 11
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_skip_mrs_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: STANDBY_CONTROL :: pwrdown_rst_n [10:10] */
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_rst_n_MASK  0x00000400
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_rst_n_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_rst_n_BITS  1
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_rst_n_SHIFT 10
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_rst_n_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: STANDBY_CONTROL :: pwrdown_cke [09:09] */
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_cke_MASK    0x00000200
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_cke_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_cke_BITS    1
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_cke_SHIFT   9
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_pwrdown_cke_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: STANDBY_CONTROL :: ldo_volts [08:07] */
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_ldo_volts_MASK      0x00000180
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_ldo_volts_ALIGN     0
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_ldo_volts_BITS      2
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_ldo_volts_SHIFT     7
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_ldo_volts_DEFAULT 2

/* DDR40_CORE_PHY_CONTROL_REGS :: STANDBY_CONTROL :: skip_mrs [06:06] */
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_skip_mrs_MASK       0x00000040
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_skip_mrs_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_skip_mrs_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_skip_mrs_SHIFT      6
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_skip_mrs_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: STANDBY_CONTROL :: rst_n [05:05] */
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_rst_n_MASK          0x00000020
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_rst_n_ALIGN         0
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_rst_n_BITS          1
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_rst_n_SHIFT         5
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_rst_n_DEFAULT  0

/* DDR40_CORE_PHY_CONTROL_REGS :: STANDBY_CONTROL :: cke [04:04] */
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_cke_MASK            0x00000010
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_cke_ALIGN           0
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_cke_BITS            1
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_cke_SHIFT           4
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_cke_DEFAULT    0

/* DDR40_CORE_PHY_CONTROL_REGS :: STANDBY_CONTROL :: standby [03:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_MASK        0x0000000f
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_BITS        4
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_SHIFT       0
#define DDR40_CORE_PHY_CONTROL_REGS_STANDBY_CONTROL_standby_DEFAULT 0

/***************************************************************************
 *STRAP_CONTROL - Strap Control register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_CONTROL :: reserved0 [31:28] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_reserved0_MASK        0xf0000000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_reserved0_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_reserved0_BITS        4
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_reserved0_SHIFT       28

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_CONTROL :: mhz [27:16] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_mhz_MASK              0x0fff0000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_mhz_ALIGN             0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_mhz_BITS              12
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_mhz_SHIFT             16
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_mhz_DEFAULT      0

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_CONTROL :: ad_width [15:14] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_ad_width_MASK         0x0000c000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_ad_width_ALIGN        0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_ad_width_BITS         2
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_ad_width_SHIFT        14
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_ad_width_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_CONTROL :: dual_rank [13:13] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_dual_rank_MASK        0x00002000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_dual_rank_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_dual_rank_BITS        1
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_dual_rank_SHIFT       13
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_dual_rank_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_CONTROL :: bus16 [12:12] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_bus16_MASK            0x00001000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_bus16_ALIGN           0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_bus16_BITS            1
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_bus16_SHIFT           12
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_bus16_DEFAULT    0

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_CONTROL :: bus8 [11:11] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_bus8_MASK             0x00000800
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_bus8_ALIGN            0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_bus8_BITS             1
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_bus8_SHIFT            11
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_bus8_DEFAULT     0

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_CONTROL :: chip_width [10:10] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_chip_width_MASK       0x00000400
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_chip_width_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_chip_width_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_chip_width_SHIFT      10
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_chip_width_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_CONTROL :: vddq [09:08] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_vddq_MASK             0x00000300
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_vddq_ALIGN            0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_vddq_BITS             2
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_vddq_SHIFT            8
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_vddq_DEFAULT     0

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_CONTROL :: chip_size [07:06] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_chip_size_MASK        0x000000c0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_chip_size_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_chip_size_BITS        2
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_chip_size_SHIFT       6
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_chip_size_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_CONTROL :: jedec_type [05:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_jedec_type_MASK       0x0000003e
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_jedec_type_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_jedec_type_BITS       5
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_jedec_type_SHIFT      1
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_jedec_type_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_CONTROL :: straps_valid [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_straps_valid_MASK     0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_straps_valid_ALIGN    0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_straps_valid_BITS     1
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_straps_valid_SHIFT    0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL_straps_valid_DEFAULT 0

/***************************************************************************
 *STRAP_CONTROL2 - Strap Control register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_CONTROL2 :: reserved0 [31:21] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_reserved0_MASK       0xffe00000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_reserved0_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_reserved0_BITS       11
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_reserved0_SHIFT      21

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_CONTROL2 :: ddr3 [20:20] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_ddr3_MASK            0x00100000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_ddr3_ALIGN           0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_ddr3_BITS            1
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_ddr3_SHIFT           20
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_ddr3_DEFAULT    0

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_CONTROL2 :: al [19:17] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_al_MASK              0x000e0000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_al_ALIGN             0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_al_BITS              3
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_al_SHIFT             17
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_al_DEFAULT      0

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_CONTROL2 :: wr [16:12] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_wr_MASK              0x0001f000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_wr_ALIGN             0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_wr_BITS              5
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_wr_SHIFT             12
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_wr_DEFAULT      0

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_CONTROL2 :: cwl [11:07] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_cwl_MASK             0x00000f80
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_cwl_ALIGN            0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_cwl_BITS             5
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_cwl_SHIFT            7
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_cwl_DEFAULT     0

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_CONTROL2 :: cl [06:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_cl_MASK              0x0000007f
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_cl_ALIGN             0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_cl_BITS              7
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_cl_SHIFT             0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_CONTROL2_cl_DEFAULT      0

/***************************************************************************
 *STRAP_STATUS - Strap Status register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS :: reserved0 [31:30] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_reserved0_MASK         0xc0000000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_reserved0_ALIGN        0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_reserved0_BITS         2
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_reserved0_SHIFT        30

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS :: from_reg [29:29] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_from_reg_MASK          0x20000000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_from_reg_ALIGN         0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_from_reg_BITS          1
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_from_reg_SHIFT         29

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS :: from_memc [28:28] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_from_memc_MASK         0x10000000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_from_memc_ALIGN        0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_from_memc_BITS         1
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_from_memc_SHIFT        28

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS :: mhz [27:16] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_mhz_MASK               0x0fff0000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_mhz_ALIGN              0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_mhz_BITS               12
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_mhz_SHIFT              16

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS :: ad_width [15:14] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_ad_width_MASK          0x0000c000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_ad_width_ALIGN         0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_ad_width_BITS          2
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_ad_width_SHIFT         14

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS :: dual_rank [13:13] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_dual_rank_MASK         0x00002000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_dual_rank_ALIGN        0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_dual_rank_BITS         1
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_dual_rank_SHIFT        13

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS :: bus16 [12:12] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_bus16_MASK             0x00001000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_bus16_ALIGN            0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_bus16_BITS             1
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_bus16_SHIFT            12

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS :: bus8 [11:11] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_bus8_MASK              0x00000800
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_bus8_ALIGN             0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_bus8_BITS              1
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_bus8_SHIFT             11

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS :: chip_width [10:10] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_chip_width_MASK        0x00000400
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_chip_width_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_chip_width_BITS        1
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_chip_width_SHIFT       10

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS :: vddq [09:08] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_vddq_MASK              0x00000300
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_vddq_ALIGN             0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_vddq_BITS              2
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_vddq_SHIFT             8

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS :: chip_size [07:06] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_chip_size_MASK         0x000000c0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_chip_size_ALIGN        0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_chip_size_BITS         2
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_chip_size_SHIFT        6

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS :: jedec_type [05:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_jedec_type_MASK        0x0000003e
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_jedec_type_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_jedec_type_BITS        5
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_jedec_type_SHIFT       1

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS :: straps_valid [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_straps_valid_MASK      0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_straps_valid_ALIGN     0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_straps_valid_BITS      1
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS_straps_valid_SHIFT     0

/***************************************************************************
 *STRAP_STATUS2 - Strap Status register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS2 :: reserved0 [31:21] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_reserved0_MASK        0xffe00000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_reserved0_ALIGN       0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_reserved0_BITS        11
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_reserved0_SHIFT       21

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS2 :: ddr3 [20:20] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_ddr3_MASK             0x00100000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_ddr3_ALIGN            0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_ddr3_BITS             1
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_ddr3_SHIFT            20

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS2 :: al [19:17] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_al_MASK               0x000e0000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_al_ALIGN              0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_al_BITS               3
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_al_SHIFT              17

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS2 :: wr [16:12] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_wr_MASK               0x0001f000
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_wr_ALIGN              0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_wr_BITS               5
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_wr_SHIFT              12

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS2 :: cwl [11:07] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_cwl_MASK              0x00000f80
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_cwl_ALIGN             0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_cwl_BITS              5
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_cwl_SHIFT             7

/* DDR40_CORE_PHY_CONTROL_REGS :: STRAP_STATUS2 :: cl [06:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_cl_MASK               0x0000007f
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_cl_ALIGN              0
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_cl_BITS               7
#define DDR40_CORE_PHY_CONTROL_REGS_STRAP_STATUS2_cl_SHIFT              0

/***************************************************************************
 *DEBUG_FREEZE_ENABLE - Freeze-on-error enable register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: DEBUG_FREEZE_ENABLE :: reserved0 [31:04] */
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_reserved0_MASK  0xfffffff0
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_reserved0_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_reserved0_BITS  28
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_reserved0_SHIFT 4

/* DDR40_CORE_PHY_CONTROL_REGS :: DEBUG_FREEZE_ENABLE :: wl1_bl1 [03:03] */
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl1_bl1_MASK    0x00000008
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl1_bl1_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl1_bl1_BITS    1
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl1_bl1_SHIFT   3
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl1_bl1_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: DEBUG_FREEZE_ENABLE :: wl1_bl0 [02:02] */
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl1_bl0_MASK    0x00000004
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl1_bl0_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl1_bl0_BITS    1
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl1_bl0_SHIFT   2
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl1_bl0_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: DEBUG_FREEZE_ENABLE :: wl0_bl1 [01:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl0_bl1_MASK    0x00000002
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl0_bl1_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl0_bl1_BITS    1
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl0_bl1_SHIFT   1
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl0_bl1_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: DEBUG_FREEZE_ENABLE :: wl0_bl0 [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl0_bl0_MASK    0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl0_bl0_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl0_bl0_BITS    1
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl0_bl0_SHIFT   0
#define DDR40_CORE_PHY_CONTROL_REGS_DEBUG_FREEZE_ENABLE_wl0_bl0_DEFAULT 0

/***************************************************************************
 *DATAPATH_LOOPBACK - Datapth Loopback control register
 ***************************************************************************/
/* DDR40_CORE_PHY_CONTROL_REGS :: DATAPATH_LOOPBACK :: reserved0 [31:03] */
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_reserved0_MASK    0xfffffff8
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_reserved0_ALIGN   0
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_reserved0_BITS    29
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_reserved0_SHIFT   3

/* DDR40_CORE_PHY_CONTROL_REGS :: DATAPATH_LOOPBACK :: xor_dm_rd_en [02:02] */
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_xor_dm_rd_en_MASK 0x00000004
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_xor_dm_rd_en_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_xor_dm_rd_en_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_xor_dm_rd_en_SHIFT 2
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_xor_dm_rd_en_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: DATAPATH_LOOPBACK :: use_addr_ctl [01:01] */
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_use_addr_ctl_MASK 0x00000002
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_use_addr_ctl_ALIGN 0
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_use_addr_ctl_BITS 1
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_use_addr_ctl_SHIFT 1
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_use_addr_ctl_DEFAULT 0

/* DDR40_CORE_PHY_CONTROL_REGS :: DATAPATH_LOOPBACK :: enable [00:00] */
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_enable_MASK       0x00000001
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_enable_ALIGN      0
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_enable_BITS       1
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_enable_SHIFT      0
#define DDR40_CORE_PHY_CONTROL_REGS_DATAPATH_LOOPBACK_enable_DEFAULT    0

/***************************************************************************
 *VDL_OVRIDE_BYTE_RD_EN - Read Enable Byte VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE_RD_EN :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_busy_MASK      0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_busy_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_busy_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_busy_SHIFT     31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE_RD_EN :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE_RD_EN :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE_RD_EN :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_ovr_en_MASK    0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_ovr_en_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_ovr_en_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_ovr_en_SHIFT   16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE_RD_EN :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE_RD_EN :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_byte_sel_MASK  0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_byte_sel_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE_RD_EN :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE_RD_EN :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_ovr_step_MASK  0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_ovr_step_BITS  6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE_RD_EN_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_W - Write Byte VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_busy_MASK         0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_busy_ALIGN        0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_busy_BITS         1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_busy_SHIFT        31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_reserved0_MASK    0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_reserved0_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_reserved0_BITS    13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_reserved0_SHIFT   18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_ovr_force_MASK    0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_ovr_force_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_ovr_force_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_ovr_force_SHIFT   17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_ovr_en_MASK       0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_ovr_en_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_ovr_en_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_ovr_en_SHIFT      16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_reserved1_MASK    0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_reserved1_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_reserved1_BITS    7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_reserved1_SHIFT   9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_byte_sel_MASK     0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_byte_sel_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_byte_sel_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_byte_sel_SHIFT    8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_reserved2_MASK    0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_reserved2_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_reserved2_BITS    2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_reserved2_SHIFT   6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_ovr_step_MASK     0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_ovr_step_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_ovr_step_BITS     6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_ovr_step_SHIFT    0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_R_P - Read Byte DQSP VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_busy_MASK       0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_busy_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_busy_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_busy_SHIFT      31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_reserved0_MASK  0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_reserved0_BITS  13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_ovr_force_MASK  0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_ovr_force_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_ovr_en_MASK     0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_ovr_en_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_ovr_en_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_ovr_en_SHIFT    16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_reserved1_MASK  0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_reserved1_BITS  7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_byte_sel_MASK   0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_byte_sel_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_byte_sel_BITS   1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_byte_sel_SHIFT  8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_reserved2_MASK  0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_reserved2_BITS  2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_ovr_step_MASK   0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_ovr_step_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_ovr_step_BITS   6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_ovr_step_SHIFT  0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_R_N - Read Byte DQSN VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_busy_MASK       0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_busy_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_busy_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_busy_SHIFT      31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_reserved0_MASK  0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_reserved0_BITS  13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_ovr_force_MASK  0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_ovr_force_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_ovr_en_MASK     0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_ovr_en_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_ovr_en_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_ovr_en_SHIFT    16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_reserved1_MASK  0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_reserved1_BITS  7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_byte_sel_MASK   0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_byte_sel_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_byte_sel_BITS   1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_byte_sel_SHIFT  8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_reserved2_MASK  0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_reserved2_BITS  2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_ovr_step_MASK   0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_ovr_step_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_ovr_step_BITS   6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_ovr_step_SHIFT  0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT0_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT1_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT2_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT3_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT4_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT5_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT6_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT7_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_DM_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_DM_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_busy_MASK      0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_busy_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_busy_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_busy_SHIFT     31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_DM_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_DM_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_DM_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_ovr_en_MASK    0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_ovr_en_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_ovr_en_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_ovr_en_SHIFT   16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_DM_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_DM_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_byte_sel_MASK  0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_byte_sel_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_DM_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_DM_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_ovr_step_MASK  0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_ovr_step_BITS  6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_DM_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT0_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT0_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT0_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT1_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT1_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT1_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT2_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT2_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT2_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT3_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT3_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT3_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT4_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT4_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT4_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT5_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT5_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT5_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT6_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT6_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT6_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT7_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT7_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT7_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT_RD_EN - Read Enable Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT_RD_EN :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_busy_MASK 0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_busy_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT_RD_EN :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT_RD_EN :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT_RD_EN :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT_RD_EN :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT_RD_EN :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT_RD_EN :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE0_BIT_RD_EN :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_W - Write Byte VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_busy_MASK         0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_busy_ALIGN        0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_busy_BITS         1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_busy_SHIFT        31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_reserved0_MASK    0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_reserved0_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_reserved0_BITS    13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_reserved0_SHIFT   18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_ovr_force_MASK    0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_ovr_force_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_ovr_force_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_ovr_force_SHIFT   17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_ovr_en_MASK       0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_ovr_en_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_ovr_en_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_ovr_en_SHIFT      16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_reserved1_MASK    0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_reserved1_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_reserved1_BITS    7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_reserved1_SHIFT   9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_byte_sel_MASK     0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_byte_sel_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_byte_sel_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_byte_sel_SHIFT    8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_reserved2_MASK    0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_reserved2_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_reserved2_BITS    2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_reserved2_SHIFT   6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_ovr_step_MASK     0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_ovr_step_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_ovr_step_BITS     6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_ovr_step_SHIFT    0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_R_P - Read Byte DQSP VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_busy_MASK       0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_busy_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_busy_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_busy_SHIFT      31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_reserved0_MASK  0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_reserved0_BITS  13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_ovr_force_MASK  0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_ovr_force_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_ovr_en_MASK     0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_ovr_en_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_ovr_en_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_ovr_en_SHIFT    16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_reserved1_MASK  0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_reserved1_BITS  7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_byte_sel_MASK   0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_byte_sel_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_byte_sel_BITS   1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_byte_sel_SHIFT  8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_reserved2_MASK  0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_reserved2_BITS  2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_ovr_step_MASK   0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_ovr_step_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_ovr_step_BITS   6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_ovr_step_SHIFT  0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_R_N - Read Byte DQSN VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_busy_MASK       0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_busy_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_busy_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_busy_SHIFT      31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_reserved0_MASK  0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_reserved0_BITS  13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_ovr_force_MASK  0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_ovr_force_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_ovr_en_MASK     0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_ovr_en_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_ovr_en_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_ovr_en_SHIFT    16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_reserved1_MASK  0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_reserved1_BITS  7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_byte_sel_MASK   0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_byte_sel_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_byte_sel_BITS   1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_byte_sel_SHIFT  8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_reserved2_MASK  0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_reserved2_BITS  2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_ovr_step_MASK   0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_ovr_step_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_ovr_step_BITS   6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_ovr_step_SHIFT  0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT0_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT1_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT2_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT3_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT4_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT5_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT6_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT7_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_DM_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_DM_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_busy_MASK      0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_busy_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_busy_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_busy_SHIFT     31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_DM_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_DM_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_DM_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_ovr_en_MASK    0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_ovr_en_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_ovr_en_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_ovr_en_SHIFT   16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_DM_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_DM_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_byte_sel_MASK  0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_byte_sel_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_DM_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_DM_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_ovr_step_MASK  0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_ovr_step_BITS  6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_DM_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT0_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT0_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT0_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT1_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT1_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT1_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT2_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT2_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT2_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT3_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT3_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT3_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT4_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT4_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT4_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT5_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT5_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT5_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT6_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT6_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT6_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT7_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT7_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT7_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT_RD_EN - Read Enable Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT_RD_EN :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_busy_MASK 0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_busy_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT_RD_EN :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT_RD_EN :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT_RD_EN :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT_RD_EN :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT_RD_EN :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT_RD_EN :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: VDL_OVRIDE_BYTE1_BIT_RD_EN :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE0_R_P - Read DQSP VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_R_P :: reserved0 [31:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_reserved0_MASK 0xfffe0000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_reserved0_BITS 15
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_reserved0_SHIFT 17

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE0_R_N - Read DQSN VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_R_N :: reserved0 [31:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_reserved0_MASK 0xfffe0000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_reserved0_BITS 15
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_reserved0_SHIFT 17

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE0_BIT_R_P - Read DQ-P VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_P :: reserved0 [31:25] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved0_MASK 0xfe000000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved0_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved0_SHIFT 25

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_P :: dm_ovr_en [24:24] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_dm_ovr_en_MASK 0x01000000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_dm_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_dm_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_dm_ovr_en_SHIFT 24
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_dm_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_P :: ovr_en [23:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_en_MASK 0x00ff0000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_en_BITS 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE0_BIT_R_N - Read DQ-N VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_N :: reserved0 [31:25] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved0_MASK 0xfe000000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved0_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved0_SHIFT 25

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_N :: dm_ovr_en [24:24] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_dm_ovr_en_MASK 0x01000000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_dm_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_dm_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_dm_ovr_en_SHIFT 24
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_dm_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_N :: ovr_en [23:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_en_MASK 0x00ff0000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_en_BITS 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE0_W - Write DQ Byte VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_W :: reserved0 [31:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_reserved0_MASK 0xfffe0000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_reserved0_BITS 15
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_reserved0_SHIFT 17

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_ovr_en_MASK   0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_ovr_en_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_ovr_en_BITS   1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_ovr_en_SHIFT  16
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_W_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE0_BIT_W - Write DQ Bit VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_W :: reserved0 [31:25] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved0_MASK 0xfe000000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved0_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved0_SHIFT 25

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_W :: dm_ovr_en [24:24] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_dm_ovr_en_MASK 0x01000000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_dm_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_dm_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_dm_ovr_en_SHIFT 24
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_dm_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_W :: ovr_en [23:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_en_MASK 0x00ff0000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_en_BITS 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE0_BIT_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE1_R_P - Read DQSP VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_R_P :: reserved0 [31:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_reserved0_MASK 0xfffe0000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_reserved0_BITS 15
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_reserved0_SHIFT 17

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE1_R_N - Read DQSN VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_R_N :: reserved0 [31:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_reserved0_MASK 0xfffe0000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_reserved0_BITS 15
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_reserved0_SHIFT 17

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE1_BIT_R_P - Read DQ-P VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_P :: reserved0 [31:25] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved0_MASK 0xfe000000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved0_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved0_SHIFT 25

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_P :: dm_ovr_en [24:24] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_dm_ovr_en_MASK 0x01000000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_dm_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_dm_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_dm_ovr_en_SHIFT 24
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_dm_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_P :: ovr_en [23:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_en_MASK 0x00ff0000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_en_BITS 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE1_BIT_R_N - Read DQ-N VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_N :: reserved0 [31:25] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved0_MASK 0xfe000000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved0_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved0_SHIFT 25

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_N :: dm_ovr_en [24:24] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_dm_ovr_en_MASK 0x01000000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_dm_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_dm_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_dm_ovr_en_SHIFT 24
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_dm_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_N :: ovr_en [23:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_en_MASK 0x00ff0000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_en_BITS 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE1_W - Write DQ Byte VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_W :: reserved0 [31:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_reserved0_MASK 0xfffe0000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_reserved0_BITS 15
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_reserved0_SHIFT 17

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_ovr_en_MASK   0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_ovr_en_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_ovr_en_BITS   1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_ovr_en_SHIFT  16
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_W_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE1_BIT_W - Write DQ Bit VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_W :: reserved0 [31:25] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved0_MASK 0xfe000000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved0_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved0_SHIFT 25

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_W :: dm_ovr_en [24:24] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_dm_ovr_en_MASK 0x01000000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_dm_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_dm_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_dm_ovr_en_SHIFT 24
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_dm_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_W :: ovr_en [23:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_en_MASK 0x00ff0000
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_en_BITS 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_0 :: DYN_VDL_OVRIDE_BYTE1_BIT_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_step_DEFAULT 0

/***************************************************************************
 *READ_DATA_DLY - Word Lane read channel control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_DATA_DLY :: reserved0 [31:03] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_DATA_DLY_reserved0_MASK         0xfffffff8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_DATA_DLY_reserved0_ALIGN        0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_DATA_DLY_reserved0_BITS         29
#define DDR40_CORE_PHY_WORD_LANE_0_READ_DATA_DLY_reserved0_SHIFT        3

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_DATA_DLY :: rd_data_dly [02:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_DATA_DLY_rd_data_dly_MASK       0x00000007
#define DDR40_CORE_PHY_WORD_LANE_0_READ_DATA_DLY_rd_data_dly_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_DATA_DLY_rd_data_dly_BITS       3
#define DDR40_CORE_PHY_WORD_LANE_0_READ_DATA_DLY_rd_data_dly_SHIFT      0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_DATA_DLY_rd_data_dly_DEFAULT 1

/***************************************************************************
 *READ_CONTROL - Word Lane read channel control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_CONTROL :: reserved0 [31:03] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_reserved0_MASK          0xfffffff8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_reserved0_ALIGN         0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_reserved0_BITS          29
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_reserved0_SHIFT         3

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_CONTROL :: dq_odt_enable [02:02] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_dq_odt_enable_MASK      0x00000004
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_dq_odt_enable_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_dq_odt_enable_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_dq_odt_enable_SHIFT     2
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_dq_odt_enable_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_CONTROL :: dq_odt_te_adj [01:01] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_dq_odt_te_adj_MASK      0x00000002
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_dq_odt_te_adj_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_dq_odt_te_adj_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_dq_odt_te_adj_SHIFT     1
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_dq_odt_te_adj_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_CONTROL :: dq_odt_le_adj [00:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_dq_odt_le_adj_MASK      0x00000001
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_dq_odt_le_adj_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_dq_odt_le_adj_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_dq_odt_le_adj_SHIFT     0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_CONTROL_dq_odt_le_adj_DEFAULT 0

/***************************************************************************
 *READ_FIFO_DATA_BL0_0 - Read fifo data register, first data
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL0_0 :: reserved0 [31:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_0_reserved0_MASK  0xffff0000
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_0_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_0_reserved0_BITS  16
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_0_reserved0_SHIFT 16

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL0_0 :: data_p [15:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_0_data_p_MASK     0x0000ff00
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_0_data_p_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_0_data_p_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_0_data_p_SHIFT    8

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL0_0 :: data_n [07:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_0_data_n_MASK     0x000000ff
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_0_data_n_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_0_data_n_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_0_data_n_SHIFT    0

/***************************************************************************
 *READ_FIFO_DATA_BL0_1 - Read fifo data register, second data
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL0_1 :: reserved0 [31:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_1_reserved0_MASK  0xffff0000
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_1_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_1_reserved0_BITS  16
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_1_reserved0_SHIFT 16

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL0_1 :: data_p [15:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_1_data_p_MASK     0x0000ff00
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_1_data_p_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_1_data_p_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_1_data_p_SHIFT    8

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL0_1 :: data_n [07:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_1_data_n_MASK     0x000000ff
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_1_data_n_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_1_data_n_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_1_data_n_SHIFT    0

/***************************************************************************
 *READ_FIFO_DATA_BL0_2 - Read fifo data register, third data
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL0_2 :: reserved0 [31:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_2_reserved0_MASK  0xffff0000
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_2_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_2_reserved0_BITS  16
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_2_reserved0_SHIFT 16

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL0_2 :: data_p [15:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_2_data_p_MASK     0x0000ff00
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_2_data_p_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_2_data_p_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_2_data_p_SHIFT    8

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL0_2 :: data_n [07:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_2_data_n_MASK     0x000000ff
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_2_data_n_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_2_data_n_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_2_data_n_SHIFT    0

/***************************************************************************
 *READ_FIFO_DATA_BL0_3 - Read fifo data register, fourth data
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL0_3 :: reserved0 [31:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_3_reserved0_MASK  0xffff0000
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_3_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_3_reserved0_BITS  16
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_3_reserved0_SHIFT 16

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL0_3 :: data_p [15:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_3_data_p_MASK     0x0000ff00
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_3_data_p_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_3_data_p_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_3_data_p_SHIFT    8

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL0_3 :: data_n [07:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_3_data_n_MASK     0x000000ff
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_3_data_n_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_3_data_n_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL0_3_data_n_SHIFT    0

/***************************************************************************
 *READ_FIFO_DATA_BL1_0 - Read fifo data register, first data
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL1_0 :: reserved0 [31:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_0_reserved0_MASK  0xffff0000
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_0_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_0_reserved0_BITS  16
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_0_reserved0_SHIFT 16

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL1_0 :: data_p [15:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_0_data_p_MASK     0x0000ff00
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_0_data_p_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_0_data_p_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_0_data_p_SHIFT    8

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL1_0 :: data_n [07:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_0_data_n_MASK     0x000000ff
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_0_data_n_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_0_data_n_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_0_data_n_SHIFT    0

/***************************************************************************
 *READ_FIFO_DATA_BL1_1 - Read fifo data register, second data
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL1_1 :: reserved0 [31:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_1_reserved0_MASK  0xffff0000
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_1_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_1_reserved0_BITS  16
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_1_reserved0_SHIFT 16

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL1_1 :: data_p [15:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_1_data_p_MASK     0x0000ff00
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_1_data_p_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_1_data_p_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_1_data_p_SHIFT    8

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL1_1 :: data_n [07:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_1_data_n_MASK     0x000000ff
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_1_data_n_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_1_data_n_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_1_data_n_SHIFT    0

/***************************************************************************
 *READ_FIFO_DATA_BL1_2 - Read fifo data register, third data
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL1_2 :: reserved0 [31:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_2_reserved0_MASK  0xffff0000
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_2_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_2_reserved0_BITS  16
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_2_reserved0_SHIFT 16

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL1_2 :: data_p [15:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_2_data_p_MASK     0x0000ff00
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_2_data_p_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_2_data_p_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_2_data_p_SHIFT    8

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL1_2 :: data_n [07:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_2_data_n_MASK     0x000000ff
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_2_data_n_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_2_data_n_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_2_data_n_SHIFT    0

/***************************************************************************
 *READ_FIFO_DATA_BL1_3 - Read fifo data register, fourth data
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL1_3 :: reserved0 [31:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_3_reserved0_MASK  0xffff0000
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_3_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_3_reserved0_BITS  16
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_3_reserved0_SHIFT 16

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL1_3 :: data_p [15:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_3_data_p_MASK     0x0000ff00
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_3_data_p_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_3_data_p_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_3_data_p_SHIFT    8

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_DATA_BL1_3 :: data_n [07:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_3_data_n_MASK     0x000000ff
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_3_data_n_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_3_data_n_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_DATA_BL1_3_data_n_SHIFT    0

/***************************************************************************
 *READ_FIFO_STATUS - Read fifo status register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_STATUS :: reserved0 [31:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_STATUS_reserved0_MASK      0xffffff00
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_STATUS_reserved0_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_STATUS_reserved0_BITS      24
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_STATUS_reserved0_SHIFT     8

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_STATUS :: status1 [07:04] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_STATUS_status1_MASK        0x000000f0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_STATUS_status1_ALIGN       0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_STATUS_status1_BITS        4
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_STATUS_status1_SHIFT       4
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_STATUS_status1_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_STATUS :: status0 [03:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_STATUS_status0_MASK        0x0000000f
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_STATUS_status0_ALIGN       0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_STATUS_status0_BITS        4
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_STATUS_status0_SHIFT       0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_STATUS_status0_DEFAULT 0

/***************************************************************************
 *READ_FIFO_CLEAR - Read fifo status clear register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_CLEAR :: reserved0 [31:01] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_CLEAR_reserved0_MASK       0xfffffffe
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_CLEAR_reserved0_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_CLEAR_reserved0_BITS       31
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_CLEAR_reserved0_SHIFT      1

/* DDR40_CORE_PHY_WORD_LANE_0 :: READ_FIFO_CLEAR :: clear [00:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_CLEAR_clear_MASK           0x00000001
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_CLEAR_clear_ALIGN          0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_CLEAR_clear_BITS           1
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_CLEAR_clear_SHIFT          0
#define DDR40_CORE_PHY_WORD_LANE_0_READ_FIFO_CLEAR_clear_DEFAULT   0

/***************************************************************************
 *IDLE_PAD_CONTROL - Idle mode SSTL pad control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: idle [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_idle_MASK           0x80000000
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_idle_ALIGN          0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_idle_BITS           1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_idle_SHIFT          31
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_idle_DEFAULT   0

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: reserved0 [30:24] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_reserved0_MASK      0x7f000000
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_reserved0_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_reserved0_BITS      7
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_reserved0_SHIFT     24

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: auto_dq_rxenb_mode [23:22] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_auto_dq_rxenb_mode_MASK 0x00c00000
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_auto_dq_rxenb_mode_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_auto_dq_rxenb_mode_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_auto_dq_rxenb_mode_SHIFT 22
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_auto_dq_rxenb_mode_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: auto_dq_iddq_mode [21:20] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_auto_dq_iddq_mode_MASK 0x00300000
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_auto_dq_iddq_mode_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_auto_dq_iddq_mode_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_auto_dq_iddq_mode_SHIFT 20
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_auto_dq_iddq_mode_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: dq_rxenb [19:19] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_rxenb_MASK       0x00080000
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_rxenb_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_rxenb_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_rxenb_SHIFT      19
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_rxenb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: dq_iddq [18:18] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_iddq_MASK        0x00040000
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_iddq_ALIGN       0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_iddq_BITS        1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_iddq_SHIFT       18
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_iddq_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: dq_reb [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_reb_MASK         0x00020000
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_reb_ALIGN        0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_reb_BITS         1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_reb_SHIFT        17
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_reb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: dq_oeb [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_oeb_MASK         0x00010000
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_oeb_ALIGN        0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_oeb_BITS         1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_oeb_SHIFT        16
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dq_oeb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: read_enb_rxenb [15:15] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_rxenb_MASK 0x00008000
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_rxenb_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_rxenb_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_rxenb_SHIFT 15
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_rxenb_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: read_enb_iddq [14:14] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_iddq_MASK  0x00004000
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_iddq_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_iddq_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_iddq_SHIFT 14
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_iddq_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: read_enb_reb [13:13] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_reb_MASK   0x00002000
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_reb_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_reb_BITS   1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_reb_SHIFT  13
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_reb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: read_enb_oeb [12:12] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_oeb_MASK   0x00001000
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_oeb_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_oeb_BITS   1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_oeb_SHIFT  12
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_read_enb_oeb_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: dqs_rxenb [11:11] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_rxenb_MASK      0x00000800
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_rxenb_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_rxenb_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_rxenb_SHIFT     11
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_rxenb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: dqs_iddq [10:10] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_iddq_MASK       0x00000400
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_iddq_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_iddq_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_iddq_SHIFT      10
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_iddq_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: dqs_reb [09:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_reb_MASK        0x00000200
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_reb_ALIGN       0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_reb_BITS        1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_reb_SHIFT       9
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_reb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: dqs_oeb [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_oeb_MASK        0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_oeb_ALIGN       0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_oeb_BITS        1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_oeb_SHIFT       8
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_dqs_oeb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: clk1_rxenb [07:07] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_rxenb_MASK     0x00000080
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_rxenb_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_rxenb_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_rxenb_SHIFT    7
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_rxenb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: clk1_iddq [06:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_iddq_MASK      0x00000040
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_iddq_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_iddq_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_iddq_SHIFT     6
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_iddq_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: clk1_reb [05:05] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_reb_MASK       0x00000020
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_reb_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_reb_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_reb_SHIFT      5
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_reb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: clk1_oeb [04:04] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_oeb_MASK       0x00000010
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_oeb_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_oeb_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_oeb_SHIFT      4
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk1_oeb_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: clk0_rxenb [03:03] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_rxenb_MASK     0x00000008
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_rxenb_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_rxenb_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_rxenb_SHIFT    3
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_rxenb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: clk0_iddq [02:02] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_iddq_MASK      0x00000004
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_iddq_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_iddq_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_iddq_SHIFT     2
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_iddq_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: clk0_reb [01:01] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_reb_MASK       0x00000002
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_reb_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_reb_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_reb_SHIFT      1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_reb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: IDLE_PAD_CONTROL :: clk0_oeb [00:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_oeb_MASK       0x00000001
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_oeb_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_oeb_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_oeb_SHIFT      0
#define DDR40_CORE_PHY_WORD_LANE_0_IDLE_PAD_CONTROL_clk0_oeb_DEFAULT 0

/***************************************************************************
 *DRIVE_PAD_CTL - SSTL pad drive characteristics control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: DRIVE_PAD_CTL :: reserved0 [31:12] */
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_reserved0_MASK         0xfffff000
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_reserved0_ALIGN        0
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_reserved0_BITS         20
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_reserved0_SHIFT        12

/* DDR40_CORE_PHY_WORD_LANE_0 :: DRIVE_PAD_CTL :: no_dqs_rd [11:11] */
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_no_dqs_rd_MASK         0x00000800
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_no_dqs_rd_ALIGN        0
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_no_dqs_rd_BITS         1
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_no_dqs_rd_SHIFT        11
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_no_dqs_rd_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DRIVE_PAD_CTL :: dqs_always_on [10:10] */
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_dqs_always_on_MASK     0x00000400
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_dqs_always_on_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_dqs_always_on_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_dqs_always_on_SHIFT    10
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_dqs_always_on_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_0 :: DRIVE_PAD_CTL :: dqs_tx_dis [09:09] */
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_dqs_tx_dis_MASK        0x00000200
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_dqs_tx_dis_ALIGN       0
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_dqs_tx_dis_BITS        1
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_dqs_tx_dis_SHIFT       9
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_dqs_tx_dis_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DRIVE_PAD_CTL :: half_strength_ck [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_half_strength_ck_MASK  0x00000100
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_half_strength_ck_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_half_strength_ck_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_half_strength_ck_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_half_strength_ck_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DRIVE_PAD_CTL :: half_strength [07:07] */
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_half_strength_MASK     0x00000080
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_half_strength_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_half_strength_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_half_strength_SHIFT    7
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_half_strength_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DRIVE_PAD_CTL :: rdqs_en [06:06] */
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_rdqs_en_MASK           0x00000040
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_rdqs_en_ALIGN          0
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_rdqs_en_BITS           1
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_rdqs_en_SHIFT          6
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_rdqs_en_DEFAULT   0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DRIVE_PAD_CTL :: gddr_symmetry [05:05] */
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_gddr_symmetry_MASK     0x00000020
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_gddr_symmetry_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_gddr_symmetry_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_gddr_symmetry_SHIFT    5
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_gddr_symmetry_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DRIVE_PAD_CTL :: vddo_volts [04:03] */
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_vddo_volts_MASK        0x00000018
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_vddo_volts_ALIGN       0
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_vddo_volts_BITS        2
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_vddo_volts_SHIFT       3
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_vddo_volts_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DRIVE_PAD_CTL :: rt60b [02:02] */
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_rt60b_MASK             0x00000004
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_rt60b_ALIGN            0
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_rt60b_BITS             1
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_rt60b_SHIFT            2
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_rt60b_DEFAULT     0

/* DDR40_CORE_PHY_WORD_LANE_0 :: DRIVE_PAD_CTL :: rt120b_g [01:01] */
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_rt120b_g_MASK          0x00000002
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_rt120b_g_ALIGN         0
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_rt120b_g_BITS          1
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_rt120b_g_SHIFT         1
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_rt120b_g_DEFAULT  1

/* DDR40_CORE_PHY_WORD_LANE_0 :: DRIVE_PAD_CTL :: g_ddr [00:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_g_ddr_MASK             0x00000001
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_g_ddr_ALIGN            0
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_g_ddr_BITS             1
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_g_ddr_SHIFT            0
#define DDR40_CORE_PHY_WORD_LANE_0_DRIVE_PAD_CTL_g_ddr_DEFAULT     0

/***************************************************************************
 *CLOCK_PAD_DISABLE - Clock pad disable register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: CLOCK_PAD_DISABLE :: reserved0 [31:03] */
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_reserved0_MASK     0xfffffff8
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_reserved0_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_reserved0_BITS     29
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_reserved0_SHIFT    3

/* DDR40_CORE_PHY_WORD_LANE_0 :: CLOCK_PAD_DISABLE :: dm_pad_dis [02:02] */
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_dm_pad_dis_MASK    0x00000004
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_dm_pad_dis_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_dm_pad_dis_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_dm_pad_dis_SHIFT   2
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_dm_pad_dis_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: CLOCK_PAD_DISABLE :: clk1_pad_dis [01:01] */
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_clk1_pad_dis_MASK  0x00000002
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_clk1_pad_dis_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_clk1_pad_dis_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_clk1_pad_dis_SHIFT 1
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_clk1_pad_dis_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: CLOCK_PAD_DISABLE :: clk0_pad_dis [00:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_clk0_pad_dis_MASK  0x00000001
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_clk0_pad_dis_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_clk0_pad_dis_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_clk0_pad_dis_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_0_CLOCK_PAD_DISABLE_clk0_pad_dis_DEFAULT 0

/***************************************************************************
 *WR_PREAMBLE_MODE - Write cycle preamble control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: WR_PREAMBLE_MODE :: reserved0 [31:02] */
#define DDR40_CORE_PHY_WORD_LANE_0_WR_PREAMBLE_MODE_reserved0_MASK      0xfffffffc
#define DDR40_CORE_PHY_WORD_LANE_0_WR_PREAMBLE_MODE_reserved0_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_0_WR_PREAMBLE_MODE_reserved0_BITS      30
#define DDR40_CORE_PHY_WORD_LANE_0_WR_PREAMBLE_MODE_reserved0_SHIFT     2

/* DDR40_CORE_PHY_WORD_LANE_0 :: WR_PREAMBLE_MODE :: long [01:01] */
#define DDR40_CORE_PHY_WORD_LANE_0_WR_PREAMBLE_MODE_long_MASK           0x00000002
#define DDR40_CORE_PHY_WORD_LANE_0_WR_PREAMBLE_MODE_long_ALIGN          0
#define DDR40_CORE_PHY_WORD_LANE_0_WR_PREAMBLE_MODE_long_BITS           1
#define DDR40_CORE_PHY_WORD_LANE_0_WR_PREAMBLE_MODE_long_SHIFT          1
#define DDR40_CORE_PHY_WORD_LANE_0_WR_PREAMBLE_MODE_long_DEFAULT   0

/* DDR40_CORE_PHY_WORD_LANE_0 :: WR_PREAMBLE_MODE :: mode [00:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_WR_PREAMBLE_MODE_mode_MASK           0x00000001
#define DDR40_CORE_PHY_WORD_LANE_0_WR_PREAMBLE_MODE_mode_ALIGN          0
#define DDR40_CORE_PHY_WORD_LANE_0_WR_PREAMBLE_MODE_mode_BITS           1
#define DDR40_CORE_PHY_WORD_LANE_0_WR_PREAMBLE_MODE_mode_SHIFT          0

/***************************************************************************
 *PHYBIST_VDL_ADJ - PHYBIST mode VDL step select adjustment register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_0 :: PHYBIST_VDL_ADJ :: reserved0 [31:29] */
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_reserved0_MASK       0xe0000000
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_reserved0_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_reserved0_BITS       3
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_reserved0_SHIFT      29

/* DDR40_CORE_PHY_WORD_LANE_0 :: PHYBIST_VDL_ADJ :: dq1_vdl_adj [28:24] */
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dq1_vdl_adj_MASK     0x1f000000
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dq1_vdl_adj_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dq1_vdl_adj_BITS     5
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dq1_vdl_adj_SHIFT    24
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dq1_vdl_adj_DEFAULT  0

/* DDR40_CORE_PHY_WORD_LANE_0 :: PHYBIST_VDL_ADJ :: reserved1 [23:21] */
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_reserved1_MASK       0x00e00000
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_reserved1_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_reserved1_BITS       3
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_reserved1_SHIFT      21

/* DDR40_CORE_PHY_WORD_LANE_0 :: PHYBIST_VDL_ADJ :: dq0_vdl_adj [20:16] */
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dq0_vdl_adj_MASK     0x001f0000
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dq0_vdl_adj_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dq0_vdl_adj_BITS     5
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dq0_vdl_adj_SHIFT    16
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dq0_vdl_adj_DEFAULT  0

/* DDR40_CORE_PHY_WORD_LANE_0 :: PHYBIST_VDL_ADJ :: reserved2 [15:13] */
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_reserved2_MASK       0x0000e000
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_reserved2_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_reserved2_BITS       3
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_reserved2_SHIFT      13

/* DDR40_CORE_PHY_WORD_LANE_0 :: PHYBIST_VDL_ADJ :: dqs1_vdl_adj [12:08] */
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dqs1_vdl_adj_MASK    0x00001f00
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dqs1_vdl_adj_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dqs1_vdl_adj_BITS    5
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dqs1_vdl_adj_SHIFT   8
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dqs1_vdl_adj_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_0 :: PHYBIST_VDL_ADJ :: reserved3 [07:05] */
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_reserved3_MASK       0x000000e0
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_reserved3_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_reserved3_BITS       3
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_reserved3_SHIFT      5

/* DDR40_CORE_PHY_WORD_LANE_0 :: PHYBIST_VDL_ADJ :: dqs0_vdl_adj [04:00] */
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dqs0_vdl_adj_MASK    0x0000001f
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dqs0_vdl_adj_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dqs0_vdl_adj_BITS    5
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dqs0_vdl_adj_SHIFT   0
#define DDR40_CORE_PHY_WORD_LANE_0_PHYBIST_VDL_ADJ_dqs0_vdl_adj_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE_RD_EN - Read Enable Byte VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE_RD_EN :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_busy_MASK      0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_busy_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_busy_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_busy_SHIFT     31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE_RD_EN :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE_RD_EN :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE_RD_EN :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_ovr_en_MASK    0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_ovr_en_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_ovr_en_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_ovr_en_SHIFT   16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE_RD_EN :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE_RD_EN :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_byte_sel_MASK  0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_byte_sel_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE_RD_EN :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE_RD_EN :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_ovr_step_MASK  0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_ovr_step_BITS  6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE_RD_EN_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_W - Write Byte VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_busy_MASK         0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_busy_ALIGN        0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_busy_BITS         1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_busy_SHIFT        31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_reserved0_MASK    0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_reserved0_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_reserved0_BITS    13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_reserved0_SHIFT   18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_ovr_force_MASK    0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_ovr_force_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_ovr_force_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_ovr_force_SHIFT   17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_ovr_en_MASK       0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_ovr_en_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_ovr_en_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_ovr_en_SHIFT      16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_reserved1_MASK    0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_reserved1_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_reserved1_BITS    7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_reserved1_SHIFT   9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_byte_sel_MASK     0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_byte_sel_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_byte_sel_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_byte_sel_SHIFT    8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_reserved2_MASK    0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_reserved2_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_reserved2_BITS    2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_reserved2_SHIFT   6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_ovr_step_MASK     0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_ovr_step_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_ovr_step_BITS     6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_ovr_step_SHIFT    0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_R_P - Read Byte DQSP VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_busy_MASK       0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_busy_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_busy_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_busy_SHIFT      31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_reserved0_MASK  0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_reserved0_BITS  13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_ovr_force_MASK  0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_ovr_force_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_ovr_en_MASK     0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_ovr_en_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_ovr_en_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_ovr_en_SHIFT    16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_reserved1_MASK  0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_reserved1_BITS  7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_byte_sel_MASK   0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_byte_sel_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_byte_sel_BITS   1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_byte_sel_SHIFT  8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_reserved2_MASK  0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_reserved2_BITS  2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_ovr_step_MASK   0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_ovr_step_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_ovr_step_BITS   6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_ovr_step_SHIFT  0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_R_N - Read Byte DQSN VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_busy_MASK       0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_busy_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_busy_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_busy_SHIFT      31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_reserved0_MASK  0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_reserved0_BITS  13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_ovr_force_MASK  0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_ovr_force_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_ovr_en_MASK     0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_ovr_en_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_ovr_en_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_ovr_en_SHIFT    16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_reserved1_MASK  0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_reserved1_BITS  7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_byte_sel_MASK   0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_byte_sel_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_byte_sel_BITS   1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_byte_sel_SHIFT  8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_reserved2_MASK  0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_reserved2_BITS  2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_ovr_step_MASK   0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_ovr_step_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_ovr_step_BITS   6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_ovr_step_SHIFT  0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT0_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT1_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT2_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT3_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT4_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT5_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT6_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT7_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_DM_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_DM_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_busy_MASK      0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_busy_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_busy_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_busy_SHIFT     31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_DM_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_DM_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_DM_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_ovr_en_MASK    0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_ovr_en_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_ovr_en_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_ovr_en_SHIFT   16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_DM_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_DM_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_byte_sel_MASK  0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_byte_sel_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_DM_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_DM_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_ovr_step_MASK  0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_ovr_step_BITS  6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_DM_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT0_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT0_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT0_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT0_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT1_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT1_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT1_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT1_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT2_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT2_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT2_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT2_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT3_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT3_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT3_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT3_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT4_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT4_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT4_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT4_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT5_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT5_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT5_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT5_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT6_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT6_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT6_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT6_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT7_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT7_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT7_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT7_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE0_BIT_RD_EN - Read Enable Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT_RD_EN :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_busy_MASK 0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_busy_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT_RD_EN :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT_RD_EN :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT_RD_EN :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT_RD_EN :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT_RD_EN :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT_RD_EN :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE0_BIT_RD_EN :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE0_BIT_RD_EN_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_W - Write Byte VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_busy_MASK         0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_busy_ALIGN        0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_busy_BITS         1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_busy_SHIFT        31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_reserved0_MASK    0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_reserved0_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_reserved0_BITS    13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_reserved0_SHIFT   18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_ovr_force_MASK    0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_ovr_force_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_ovr_force_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_ovr_force_SHIFT   17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_ovr_en_MASK       0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_ovr_en_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_ovr_en_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_ovr_en_SHIFT      16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_reserved1_MASK    0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_reserved1_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_reserved1_BITS    7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_reserved1_SHIFT   9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_byte_sel_MASK     0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_byte_sel_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_byte_sel_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_byte_sel_SHIFT    8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_reserved2_MASK    0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_reserved2_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_reserved2_BITS    2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_reserved2_SHIFT   6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_ovr_step_MASK     0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_ovr_step_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_ovr_step_BITS     6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_ovr_step_SHIFT    0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_R_P - Read Byte DQSP VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_busy_MASK       0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_busy_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_busy_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_busy_SHIFT      31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_reserved0_MASK  0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_reserved0_BITS  13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_ovr_force_MASK  0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_ovr_force_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_ovr_en_MASK     0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_ovr_en_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_ovr_en_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_ovr_en_SHIFT    16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_reserved1_MASK  0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_reserved1_BITS  7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_byte_sel_MASK   0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_byte_sel_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_byte_sel_BITS   1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_byte_sel_SHIFT  8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_reserved2_MASK  0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_reserved2_BITS  2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_ovr_step_MASK   0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_ovr_step_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_ovr_step_BITS   6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_ovr_step_SHIFT  0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_R_N - Read Byte DQSN VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_busy_MASK       0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_busy_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_busy_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_busy_SHIFT      31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_reserved0_MASK  0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_reserved0_BITS  13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_ovr_force_MASK  0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_ovr_force_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_ovr_en_MASK     0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_ovr_en_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_ovr_en_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_ovr_en_SHIFT    16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_reserved1_MASK  0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_reserved1_BITS  7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_byte_sel_MASK   0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_byte_sel_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_byte_sel_BITS   1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_byte_sel_SHIFT  8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_reserved2_MASK  0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_reserved2_BITS  2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_ovr_step_MASK   0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_ovr_step_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_ovr_step_BITS   6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_ovr_step_SHIFT  0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT0_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT1_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT2_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT3_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT4_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT5_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT6_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT7_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_busy_MASK    0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_busy_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_busy_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_busy_SHIFT   31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_ovr_en_MASK  0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_ovr_en_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_DM_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_DM_W :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_busy_MASK      0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_busy_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_busy_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_busy_SHIFT     31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_DM_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_DM_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_DM_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_ovr_en_MASK    0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_ovr_en_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_ovr_en_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_ovr_en_SHIFT   16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_DM_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_DM_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_byte_sel_MASK  0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_byte_sel_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_DM_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_DM_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_ovr_step_MASK  0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_ovr_step_BITS  6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_DM_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT0_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT0_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT0_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT0_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT1_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT1_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT1_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT1_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT2_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT2_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT2_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT2_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT3_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT3_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT3_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT3_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT4_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT4_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT4_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT4_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT5_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT5_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT5_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT5_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT6_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT6_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT6_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT6_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT7_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT7_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_busy_MASK  0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_busy_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT7_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT7_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE1_BIT_RD_EN - Read Enable Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT_RD_EN :: busy [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_busy_MASK 0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_busy_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_busy_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_busy_SHIFT 31
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_busy_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT_RD_EN :: reserved0 [30:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved0_BITS 13
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved0_SHIFT 18

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT_RD_EN :: ovr_force [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_force_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT_RD_EN :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT_RD_EN :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT_RD_EN :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT_RD_EN :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: VDL_OVRIDE_BYTE1_BIT_RD_EN :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_VDL_OVRIDE_BYTE1_BIT_RD_EN_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE0_R_P - Read DQSP VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_R_P :: reserved0 [31:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_reserved0_MASK 0xfffe0000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_reserved0_BITS 15
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_reserved0_SHIFT 17

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE0_R_N - Read DQSN VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_R_N :: reserved0 [31:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_reserved0_MASK 0xfffe0000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_reserved0_BITS 15
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_reserved0_SHIFT 17

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE0_BIT_R_P - Read DQ-P VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_P :: reserved0 [31:25] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved0_MASK 0xfe000000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved0_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved0_SHIFT 25

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_P :: dm_ovr_en [24:24] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_dm_ovr_en_MASK 0x01000000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_dm_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_dm_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_dm_ovr_en_SHIFT 24
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_dm_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_P :: ovr_en [23:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_en_MASK 0x00ff0000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_en_BITS 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE0_BIT_R_N - Read DQ-N VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_N :: reserved0 [31:25] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved0_MASK 0xfe000000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved0_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved0_SHIFT 25

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_N :: dm_ovr_en [24:24] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_dm_ovr_en_MASK 0x01000000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_dm_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_dm_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_dm_ovr_en_SHIFT 24
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_dm_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_N :: ovr_en [23:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_en_MASK 0x00ff0000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_en_BITS 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE0_W - Write DQ Byte VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_W :: reserved0 [31:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_reserved0_MASK 0xfffe0000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_reserved0_BITS 15
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_reserved0_SHIFT 17

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_ovr_en_MASK   0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_ovr_en_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_ovr_en_BITS   1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_ovr_en_SHIFT  16
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_W_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE0_BIT_W - Write DQ Bit VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_W :: reserved0 [31:25] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved0_MASK 0xfe000000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved0_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved0_SHIFT 25

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_W :: dm_ovr_en [24:24] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_dm_ovr_en_MASK 0x01000000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_dm_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_dm_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_dm_ovr_en_SHIFT 24
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_dm_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_W :: ovr_en [23:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_en_MASK 0x00ff0000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_en_BITS 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE0_BIT_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE0_BIT_W_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE1_R_P - Read DQSP VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_R_P :: reserved0 [31:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_reserved0_MASK 0xfffe0000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_reserved0_BITS 15
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_reserved0_SHIFT 17

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE1_R_N - Read DQSN VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_R_N :: reserved0 [31:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_reserved0_MASK 0xfffe0000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_reserved0_BITS 15
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_reserved0_SHIFT 17

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_en_MASK 0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE1_BIT_R_P - Read DQ-P VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_P :: reserved0 [31:25] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved0_MASK 0xfe000000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved0_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved0_SHIFT 25

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_P :: dm_ovr_en [24:24] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_dm_ovr_en_MASK 0x01000000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_dm_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_dm_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_dm_ovr_en_SHIFT 24
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_dm_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_P :: ovr_en [23:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_en_MASK 0x00ff0000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_en_BITS 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE1_BIT_R_N - Read DQ-N VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_N :: reserved0 [31:25] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved0_MASK 0xfe000000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved0_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved0_SHIFT 25

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_N :: dm_ovr_en [24:24] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_dm_ovr_en_MASK 0x01000000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_dm_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_dm_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_dm_ovr_en_SHIFT 24
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_dm_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_N :: ovr_en [23:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_en_MASK 0x00ff0000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_en_BITS 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE1_W - Write DQ Byte VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_W :: reserved0 [31:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_reserved0_MASK 0xfffe0000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_reserved0_BITS 15
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_reserved0_SHIFT 17

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_ovr_en_MASK   0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_ovr_en_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_ovr_en_BITS   1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_ovr_en_SHIFT  16
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_W_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE1_BIT_W - Write DQ Bit VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_W :: reserved0 [31:25] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved0_MASK 0xfe000000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved0_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved0_SHIFT 25

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_W :: dm_ovr_en [24:24] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_dm_ovr_en_MASK 0x01000000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_dm_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_dm_ovr_en_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_dm_ovr_en_SHIFT 24
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_dm_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_W :: ovr_en [23:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_en_MASK 0x00ff0000
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_en_BITS 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved1_BITS 7
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved1_SHIFT 9

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved2_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_reserved2_SHIFT 6

/* DDR40_CORE_PHY_WORD_LANE_1 :: DYN_VDL_OVRIDE_BYTE1_BIT_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_DYN_VDL_OVRIDE_BYTE1_BIT_W_ovr_step_DEFAULT 0

/***************************************************************************
 *READ_DATA_DLY - Word Lane read channel control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_DATA_DLY :: reserved0 [31:03] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_DATA_DLY_reserved0_MASK         0xfffffff8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_DATA_DLY_reserved0_ALIGN        0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_DATA_DLY_reserved0_BITS         29
#define DDR40_CORE_PHY_WORD_LANE_1_READ_DATA_DLY_reserved0_SHIFT        3

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_DATA_DLY :: rd_data_dly [02:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_DATA_DLY_rd_data_dly_MASK       0x00000007
#define DDR40_CORE_PHY_WORD_LANE_1_READ_DATA_DLY_rd_data_dly_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_DATA_DLY_rd_data_dly_BITS       3
#define DDR40_CORE_PHY_WORD_LANE_1_READ_DATA_DLY_rd_data_dly_SHIFT      0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_DATA_DLY_rd_data_dly_DEFAULT 1

/***************************************************************************
 *READ_CONTROL - Word Lane read channel control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_CONTROL :: reserved0 [31:03] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_reserved0_MASK          0xfffffff8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_reserved0_ALIGN         0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_reserved0_BITS          29
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_reserved0_SHIFT         3

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_CONTROL :: dq_odt_enable [02:02] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_dq_odt_enable_MASK      0x00000004
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_dq_odt_enable_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_dq_odt_enable_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_dq_odt_enable_SHIFT     2
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_dq_odt_enable_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_CONTROL :: dq_odt_te_adj [01:01] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_dq_odt_te_adj_MASK      0x00000002
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_dq_odt_te_adj_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_dq_odt_te_adj_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_dq_odt_te_adj_SHIFT     1
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_dq_odt_te_adj_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_CONTROL :: dq_odt_le_adj [00:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_dq_odt_le_adj_MASK      0x00000001
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_dq_odt_le_adj_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_dq_odt_le_adj_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_dq_odt_le_adj_SHIFT     0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_CONTROL_dq_odt_le_adj_DEFAULT 0

/***************************************************************************
 *READ_FIFO_DATA_BL0_0 - Read fifo data register, first data
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL0_0 :: reserved0 [31:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_0_reserved0_MASK  0xffff0000
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_0_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_0_reserved0_BITS  16
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_0_reserved0_SHIFT 16

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL0_0 :: data_p [15:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_0_data_p_MASK     0x0000ff00
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_0_data_p_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_0_data_p_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_0_data_p_SHIFT    8

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL0_0 :: data_n [07:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_0_data_n_MASK     0x000000ff
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_0_data_n_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_0_data_n_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_0_data_n_SHIFT    0

/***************************************************************************
 *READ_FIFO_DATA_BL0_1 - Read fifo data register, second data
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL0_1 :: reserved0 [31:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_1_reserved0_MASK  0xffff0000
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_1_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_1_reserved0_BITS  16
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_1_reserved0_SHIFT 16

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL0_1 :: data_p [15:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_1_data_p_MASK     0x0000ff00
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_1_data_p_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_1_data_p_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_1_data_p_SHIFT    8

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL0_1 :: data_n [07:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_1_data_n_MASK     0x000000ff
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_1_data_n_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_1_data_n_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_1_data_n_SHIFT    0

/***************************************************************************
 *READ_FIFO_DATA_BL0_2 - Read fifo data register, third data
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL0_2 :: reserved0 [31:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_2_reserved0_MASK  0xffff0000
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_2_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_2_reserved0_BITS  16
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_2_reserved0_SHIFT 16

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL0_2 :: data_p [15:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_2_data_p_MASK     0x0000ff00
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_2_data_p_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_2_data_p_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_2_data_p_SHIFT    8

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL0_2 :: data_n [07:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_2_data_n_MASK     0x000000ff
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_2_data_n_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_2_data_n_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_2_data_n_SHIFT    0

/***************************************************************************
 *READ_FIFO_DATA_BL0_3 - Read fifo data register, fourth data
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL0_3 :: reserved0 [31:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_3_reserved0_MASK  0xffff0000
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_3_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_3_reserved0_BITS  16
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_3_reserved0_SHIFT 16

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL0_3 :: data_p [15:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_3_data_p_MASK     0x0000ff00
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_3_data_p_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_3_data_p_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_3_data_p_SHIFT    8

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL0_3 :: data_n [07:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_3_data_n_MASK     0x000000ff
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_3_data_n_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_3_data_n_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL0_3_data_n_SHIFT    0

/***************************************************************************
 *READ_FIFO_DATA_BL1_0 - Read fifo data register, first data
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL1_0 :: reserved0 [31:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_0_reserved0_MASK  0xffff0000
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_0_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_0_reserved0_BITS  16
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_0_reserved0_SHIFT 16

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL1_0 :: data_p [15:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_0_data_p_MASK     0x0000ff00
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_0_data_p_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_0_data_p_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_0_data_p_SHIFT    8

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL1_0 :: data_n [07:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_0_data_n_MASK     0x000000ff
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_0_data_n_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_0_data_n_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_0_data_n_SHIFT    0

/***************************************************************************
 *READ_FIFO_DATA_BL1_1 - Read fifo data register, second data
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL1_1 :: reserved0 [31:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_1_reserved0_MASK  0xffff0000
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_1_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_1_reserved0_BITS  16
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_1_reserved0_SHIFT 16

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL1_1 :: data_p [15:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_1_data_p_MASK     0x0000ff00
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_1_data_p_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_1_data_p_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_1_data_p_SHIFT    8

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL1_1 :: data_n [07:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_1_data_n_MASK     0x000000ff
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_1_data_n_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_1_data_n_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_1_data_n_SHIFT    0

/***************************************************************************
 *READ_FIFO_DATA_BL1_2 - Read fifo data register, third data
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL1_2 :: reserved0 [31:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_2_reserved0_MASK  0xffff0000
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_2_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_2_reserved0_BITS  16
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_2_reserved0_SHIFT 16

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL1_2 :: data_p [15:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_2_data_p_MASK     0x0000ff00
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_2_data_p_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_2_data_p_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_2_data_p_SHIFT    8

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL1_2 :: data_n [07:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_2_data_n_MASK     0x000000ff
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_2_data_n_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_2_data_n_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_2_data_n_SHIFT    0

/***************************************************************************
 *READ_FIFO_DATA_BL1_3 - Read fifo data register, fourth data
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL1_3 :: reserved0 [31:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_3_reserved0_MASK  0xffff0000
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_3_reserved0_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_3_reserved0_BITS  16
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_3_reserved0_SHIFT 16

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL1_3 :: data_p [15:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_3_data_p_MASK     0x0000ff00
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_3_data_p_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_3_data_p_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_3_data_p_SHIFT    8

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_DATA_BL1_3 :: data_n [07:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_3_data_n_MASK     0x000000ff
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_3_data_n_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_3_data_n_BITS     8
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_DATA_BL1_3_data_n_SHIFT    0

/***************************************************************************
 *READ_FIFO_STATUS - Read fifo status register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_STATUS :: reserved0 [31:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_STATUS_reserved0_MASK      0xffffff00
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_STATUS_reserved0_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_STATUS_reserved0_BITS      24
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_STATUS_reserved0_SHIFT     8

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_STATUS :: status1 [07:04] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_STATUS_status1_MASK        0x000000f0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_STATUS_status1_ALIGN       0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_STATUS_status1_BITS        4
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_STATUS_status1_SHIFT       4
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_STATUS_status1_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_STATUS :: status0 [03:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_STATUS_status0_MASK        0x0000000f
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_STATUS_status0_ALIGN       0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_STATUS_status0_BITS        4
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_STATUS_status0_SHIFT       0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_STATUS_status0_DEFAULT 0

/***************************************************************************
 *READ_FIFO_CLEAR - Read fifo status clear register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_CLEAR :: reserved0 [31:01] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_CLEAR_reserved0_MASK       0xfffffffe
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_CLEAR_reserved0_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_CLEAR_reserved0_BITS       31
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_CLEAR_reserved0_SHIFT      1

/* DDR40_CORE_PHY_WORD_LANE_1 :: READ_FIFO_CLEAR :: clear [00:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_CLEAR_clear_MASK           0x00000001
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_CLEAR_clear_ALIGN          0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_CLEAR_clear_BITS           1
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_CLEAR_clear_SHIFT          0
#define DDR40_CORE_PHY_WORD_LANE_1_READ_FIFO_CLEAR_clear_DEFAULT   0

/***************************************************************************
 *IDLE_PAD_CONTROL - Idle mode SSTL pad control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: idle [31:31] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_idle_MASK           0x80000000
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_idle_ALIGN          0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_idle_BITS           1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_idle_SHIFT          31
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_idle_DEFAULT   0

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: reserved0 [30:24] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_reserved0_MASK      0x7f000000
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_reserved0_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_reserved0_BITS      7
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_reserved0_SHIFT     24

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: auto_dq_rxenb_mode [23:22] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_auto_dq_rxenb_mode_MASK 0x00c00000
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_auto_dq_rxenb_mode_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_auto_dq_rxenb_mode_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_auto_dq_rxenb_mode_SHIFT 22
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_auto_dq_rxenb_mode_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: auto_dq_iddq_mode [21:20] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_auto_dq_iddq_mode_MASK 0x00300000
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_auto_dq_iddq_mode_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_auto_dq_iddq_mode_BITS 2
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_auto_dq_iddq_mode_SHIFT 20
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_auto_dq_iddq_mode_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: dq_rxenb [19:19] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_rxenb_MASK       0x00080000
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_rxenb_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_rxenb_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_rxenb_SHIFT      19
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_rxenb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: dq_iddq [18:18] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_iddq_MASK        0x00040000
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_iddq_ALIGN       0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_iddq_BITS        1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_iddq_SHIFT       18
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_iddq_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: dq_reb [17:17] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_reb_MASK         0x00020000
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_reb_ALIGN        0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_reb_BITS         1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_reb_SHIFT        17
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_reb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: dq_oeb [16:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_oeb_MASK         0x00010000
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_oeb_ALIGN        0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_oeb_BITS         1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_oeb_SHIFT        16
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dq_oeb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: read_enb_rxenb [15:15] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_rxenb_MASK 0x00008000
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_rxenb_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_rxenb_BITS 1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_rxenb_SHIFT 15
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_rxenb_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: read_enb_iddq [14:14] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_iddq_MASK  0x00004000
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_iddq_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_iddq_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_iddq_SHIFT 14
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_iddq_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: read_enb_reb [13:13] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_reb_MASK   0x00002000
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_reb_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_reb_BITS   1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_reb_SHIFT  13
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_reb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: read_enb_oeb [12:12] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_oeb_MASK   0x00001000
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_oeb_ALIGN  0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_oeb_BITS   1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_oeb_SHIFT  12
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_read_enb_oeb_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: dqs_rxenb [11:11] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_rxenb_MASK      0x00000800
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_rxenb_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_rxenb_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_rxenb_SHIFT     11
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_rxenb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: dqs_iddq [10:10] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_iddq_MASK       0x00000400
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_iddq_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_iddq_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_iddq_SHIFT      10
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_iddq_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: dqs_reb [09:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_reb_MASK        0x00000200
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_reb_ALIGN       0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_reb_BITS        1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_reb_SHIFT       9
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_reb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: dqs_oeb [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_oeb_MASK        0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_oeb_ALIGN       0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_oeb_BITS        1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_oeb_SHIFT       8
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_dqs_oeb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: clk1_rxenb [07:07] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_rxenb_MASK     0x00000080
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_rxenb_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_rxenb_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_rxenb_SHIFT    7
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_rxenb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: clk1_iddq [06:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_iddq_MASK      0x00000040
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_iddq_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_iddq_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_iddq_SHIFT     6
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_iddq_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: clk1_reb [05:05] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_reb_MASK       0x00000020
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_reb_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_reb_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_reb_SHIFT      5
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_reb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: clk1_oeb [04:04] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_oeb_MASK       0x00000010
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_oeb_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_oeb_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_oeb_SHIFT      4
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk1_oeb_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: clk0_rxenb [03:03] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_rxenb_MASK     0x00000008
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_rxenb_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_rxenb_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_rxenb_SHIFT    3
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_rxenb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: clk0_iddq [02:02] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_iddq_MASK      0x00000004
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_iddq_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_iddq_BITS      1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_iddq_SHIFT     2
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_iddq_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: clk0_reb [01:01] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_reb_MASK       0x00000002
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_reb_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_reb_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_reb_SHIFT      1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_reb_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: IDLE_PAD_CONTROL :: clk0_oeb [00:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_oeb_MASK       0x00000001
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_oeb_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_oeb_BITS       1
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_oeb_SHIFT      0
#define DDR40_CORE_PHY_WORD_LANE_1_IDLE_PAD_CONTROL_clk0_oeb_DEFAULT 0

/***************************************************************************
 *DRIVE_PAD_CTL - SSTL pad drive characteristics control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: DRIVE_PAD_CTL :: reserved0 [31:12] */
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_reserved0_MASK         0xfffff000
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_reserved0_ALIGN        0
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_reserved0_BITS         20
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_reserved0_SHIFT        12

/* DDR40_CORE_PHY_WORD_LANE_1 :: DRIVE_PAD_CTL :: no_dqs_rd [11:11] */
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_no_dqs_rd_MASK         0x00000800
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_no_dqs_rd_ALIGN        0
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_no_dqs_rd_BITS         1
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_no_dqs_rd_SHIFT        11
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_no_dqs_rd_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DRIVE_PAD_CTL :: dqs_always_on [10:10] */
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_dqs_always_on_MASK     0x00000400
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_dqs_always_on_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_dqs_always_on_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_dqs_always_on_SHIFT    10
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_dqs_always_on_DEFAULT 1

/* DDR40_CORE_PHY_WORD_LANE_1 :: DRIVE_PAD_CTL :: dqs_tx_dis [09:09] */
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_dqs_tx_dis_MASK        0x00000200
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_dqs_tx_dis_ALIGN       0
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_dqs_tx_dis_BITS        1
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_dqs_tx_dis_SHIFT       9
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_dqs_tx_dis_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DRIVE_PAD_CTL :: half_strength_ck [08:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_half_strength_ck_MASK  0x00000100
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_half_strength_ck_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_half_strength_ck_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_half_strength_ck_SHIFT 8
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_half_strength_ck_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DRIVE_PAD_CTL :: half_strength [07:07] */
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_half_strength_MASK     0x00000080
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_half_strength_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_half_strength_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_half_strength_SHIFT    7
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_half_strength_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DRIVE_PAD_CTL :: rdqs_en [06:06] */
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_rdqs_en_MASK           0x00000040
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_rdqs_en_ALIGN          0
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_rdqs_en_BITS           1
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_rdqs_en_SHIFT          6
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_rdqs_en_DEFAULT   0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DRIVE_PAD_CTL :: gddr_symmetry [05:05] */
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_gddr_symmetry_MASK     0x00000020
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_gddr_symmetry_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_gddr_symmetry_BITS     1
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_gddr_symmetry_SHIFT    5
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_gddr_symmetry_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DRIVE_PAD_CTL :: vddo_volts [04:03] */
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_vddo_volts_MASK        0x00000018
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_vddo_volts_ALIGN       0
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_vddo_volts_BITS        2
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_vddo_volts_SHIFT       3
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_vddo_volts_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DRIVE_PAD_CTL :: rt60b [02:02] */
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_rt60b_MASK             0x00000004
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_rt60b_ALIGN            0
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_rt60b_BITS             1
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_rt60b_SHIFT            2
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_rt60b_DEFAULT     0

/* DDR40_CORE_PHY_WORD_LANE_1 :: DRIVE_PAD_CTL :: rt120b_g [01:01] */
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_rt120b_g_MASK          0x00000002
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_rt120b_g_ALIGN         0
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_rt120b_g_BITS          1
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_rt120b_g_SHIFT         1
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_rt120b_g_DEFAULT  1

/* DDR40_CORE_PHY_WORD_LANE_1 :: DRIVE_PAD_CTL :: g_ddr [00:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_g_ddr_MASK             0x00000001
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_g_ddr_ALIGN            0
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_g_ddr_BITS             1
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_g_ddr_SHIFT            0
#define DDR40_CORE_PHY_WORD_LANE_1_DRIVE_PAD_CTL_g_ddr_DEFAULT     0

/***************************************************************************
 *CLOCK_PAD_DISABLE - Clock pad disable register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: CLOCK_PAD_DISABLE :: reserved0 [31:03] */
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_reserved0_MASK     0xfffffff8
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_reserved0_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_reserved0_BITS     29
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_reserved0_SHIFT    3

/* DDR40_CORE_PHY_WORD_LANE_1 :: CLOCK_PAD_DISABLE :: dm_pad_dis [02:02] */
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_dm_pad_dis_MASK    0x00000004
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_dm_pad_dis_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_dm_pad_dis_BITS    1
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_dm_pad_dis_SHIFT   2
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_dm_pad_dis_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: CLOCK_PAD_DISABLE :: clk1_pad_dis [01:01] */
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_clk1_pad_dis_MASK  0x00000002
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_clk1_pad_dis_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_clk1_pad_dis_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_clk1_pad_dis_SHIFT 1
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_clk1_pad_dis_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: CLOCK_PAD_DISABLE :: clk0_pad_dis [00:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_clk0_pad_dis_MASK  0x00000001
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_clk0_pad_dis_ALIGN 0
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_clk0_pad_dis_BITS  1
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_clk0_pad_dis_SHIFT 0
#define DDR40_CORE_PHY_WORD_LANE_1_CLOCK_PAD_DISABLE_clk0_pad_dis_DEFAULT 0

/***************************************************************************
 *WR_PREAMBLE_MODE - Write cycle preamble control register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: WR_PREAMBLE_MODE :: reserved0 [31:02] */
#define DDR40_CORE_PHY_WORD_LANE_1_WR_PREAMBLE_MODE_reserved0_MASK      0xfffffffc
#define DDR40_CORE_PHY_WORD_LANE_1_WR_PREAMBLE_MODE_reserved0_ALIGN     0
#define DDR40_CORE_PHY_WORD_LANE_1_WR_PREAMBLE_MODE_reserved0_BITS      30
#define DDR40_CORE_PHY_WORD_LANE_1_WR_PREAMBLE_MODE_reserved0_SHIFT     2

/* DDR40_CORE_PHY_WORD_LANE_1 :: WR_PREAMBLE_MODE :: long [01:01] */
#define DDR40_CORE_PHY_WORD_LANE_1_WR_PREAMBLE_MODE_long_MASK           0x00000002
#define DDR40_CORE_PHY_WORD_LANE_1_WR_PREAMBLE_MODE_long_ALIGN          0
#define DDR40_CORE_PHY_WORD_LANE_1_WR_PREAMBLE_MODE_long_BITS           1
#define DDR40_CORE_PHY_WORD_LANE_1_WR_PREAMBLE_MODE_long_SHIFT          1
#define DDR40_CORE_PHY_WORD_LANE_1_WR_PREAMBLE_MODE_long_DEFAULT   0

/* DDR40_CORE_PHY_WORD_LANE_1 :: WR_PREAMBLE_MODE :: mode [00:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_WR_PREAMBLE_MODE_mode_MASK           0x00000001
#define DDR40_CORE_PHY_WORD_LANE_1_WR_PREAMBLE_MODE_mode_ALIGN          0
#define DDR40_CORE_PHY_WORD_LANE_1_WR_PREAMBLE_MODE_mode_BITS           1
#define DDR40_CORE_PHY_WORD_LANE_1_WR_PREAMBLE_MODE_mode_SHIFT          0
#define DDR40_CORE_PHY_WORD_LANE_1_WR_PREAMBLE_MODE_mode_DEFAULT   0

/***************************************************************************
 *PHYBIST_VDL_ADJ - PHYBIST mode VDL step select adjustment register
 ***************************************************************************/
/* DDR40_CORE_PHY_WORD_LANE_1 :: PHYBIST_VDL_ADJ :: reserved0 [31:29] */
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_reserved0_MASK       0xe0000000
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_reserved0_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_reserved0_BITS       3
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_reserved0_SHIFT      29

/* DDR40_CORE_PHY_WORD_LANE_1 :: PHYBIST_VDL_ADJ :: dq1_vdl_adj [28:24] */
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dq1_vdl_adj_MASK     0x1f000000
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dq1_vdl_adj_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dq1_vdl_adj_BITS     5
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dq1_vdl_adj_SHIFT    24
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dq1_vdl_adj_DEFAULT  0

/* DDR40_CORE_PHY_WORD_LANE_1 :: PHYBIST_VDL_ADJ :: reserved1 [23:21] */
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_reserved1_MASK       0x00e00000
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_reserved1_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_reserved1_BITS       3
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_reserved1_SHIFT      21

/* DDR40_CORE_PHY_WORD_LANE_1 :: PHYBIST_VDL_ADJ :: dq0_vdl_adj [20:16] */
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dq0_vdl_adj_MASK     0x001f0000
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dq0_vdl_adj_ALIGN    0
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dq0_vdl_adj_BITS     5
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dq0_vdl_adj_SHIFT    16
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dq0_vdl_adj_DEFAULT  0

/* DDR40_CORE_PHY_WORD_LANE_1 :: PHYBIST_VDL_ADJ :: reserved2 [15:13] */
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_reserved2_MASK       0x0000e000
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_reserved2_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_reserved2_BITS       3
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_reserved2_SHIFT      13

/* DDR40_CORE_PHY_WORD_LANE_1 :: PHYBIST_VDL_ADJ :: dqs1_vdl_adj [12:08] */
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dqs1_vdl_adj_MASK    0x00001f00
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dqs1_vdl_adj_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dqs1_vdl_adj_BITS    5
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dqs1_vdl_adj_SHIFT   8
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dqs1_vdl_adj_DEFAULT 0

/* DDR40_CORE_PHY_WORD_LANE_1 :: PHYBIST_VDL_ADJ :: reserved3 [07:05] */
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_reserved3_MASK       0x000000e0
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_reserved3_ALIGN      0
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_reserved3_BITS       3
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_reserved3_SHIFT      5

/* DDR40_CORE_PHY_WORD_LANE_1 :: PHYBIST_VDL_ADJ :: dqs0_vdl_adj [04:00] */
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dqs0_vdl_adj_MASK    0x0000001f
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dqs0_vdl_adj_ALIGN   0
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dqs0_vdl_adj_BITS    5
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dqs0_vdl_adj_SHIFT   0
#define DDR40_CORE_PHY_WORD_LANE_1_PHYBIST_VDL_ADJ_dqs0_vdl_adj_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE_RD_EN - Read Enable Byte VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_RD_EN :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_busy_MASK         0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_busy_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_busy_BITS         1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_busy_SHIFT        31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_busy_DEFAULT      0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_RD_EN :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_reserved0_MASK    0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_reserved0_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_reserved0_BITS    13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_reserved0_SHIFT   18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_RD_EN :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_ovr_force_MASK    0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_ovr_force_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_ovr_force_BITS    1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_ovr_force_SHIFT   17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_RD_EN :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_ovr_en_MASK       0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_ovr_en_ALIGN      0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_ovr_en_BITS       1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_ovr_en_SHIFT      16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_ovr_en_DEFAULT    0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_RD_EN :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_reserved1_MASK    0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_reserved1_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_reserved1_BITS    7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_reserved1_SHIFT   9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_RD_EN :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_byte_sel_MASK     0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_byte_sel_ALIGN    0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_byte_sel_BITS     1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_byte_sel_SHIFT    8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_byte_sel_DEFAULT  0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_RD_EN :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_reserved2_MASK    0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_reserved2_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_reserved2_BITS    2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_reserved2_SHIFT   6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_RD_EN :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_ovr_step_MASK     0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_ovr_step_ALIGN    0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_ovr_step_BITS     6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_ovr_step_SHIFT    0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_RD_EN_ovr_step_DEFAULT  0

/***************************************************************************
 *VDL_OVRIDE_BYTE_W - Write Byte VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_W :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_busy_MASK             0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_busy_ALIGN            0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_busy_BITS             1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_busy_SHIFT            31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_busy_DEFAULT          0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_reserved0_MASK        0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_reserved0_ALIGN       0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_reserved0_BITS        13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_reserved0_SHIFT       18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_ovr_force_MASK        0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_ovr_force_ALIGN       0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_ovr_force_BITS        1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_ovr_force_SHIFT       17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_ovr_force_DEFAULT     0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_ovr_en_MASK           0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_ovr_en_ALIGN          0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_ovr_en_BITS           1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_ovr_en_SHIFT          16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_ovr_en_DEFAULT        0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_reserved1_MASK        0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_reserved1_ALIGN       0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_reserved1_BITS        7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_reserved1_SHIFT       9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_byte_sel_MASK         0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_byte_sel_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_byte_sel_BITS         1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_byte_sel_SHIFT        8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_byte_sel_DEFAULT      0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_reserved2_MASK        0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_reserved2_ALIGN       0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_reserved2_BITS        2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_reserved2_SHIFT       6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_ovr_step_MASK         0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_ovr_step_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_ovr_step_BITS         6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_ovr_step_SHIFT        0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_W_ovr_step_DEFAULT      0

/***************************************************************************
 *VDL_OVRIDE_BYTE_R_P - Read Byte DQSP VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_busy_MASK           0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_busy_ALIGN          0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_busy_BITS           1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_busy_SHIFT          31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_busy_DEFAULT        0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_reserved0_MASK      0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_reserved0_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_reserved0_BITS      13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_reserved0_SHIFT     18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_ovr_force_MASK      0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_ovr_force_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_ovr_force_BITS      1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_ovr_force_SHIFT     17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_ovr_force_DEFAULT   0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_ovr_en_MASK         0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_ovr_en_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_ovr_en_BITS         1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_ovr_en_SHIFT        16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_ovr_en_DEFAULT      0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_reserved1_MASK      0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_reserved1_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_reserved1_BITS      7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_reserved1_SHIFT     9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_byte_sel_MASK       0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_byte_sel_ALIGN      0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_byte_sel_BITS       1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_byte_sel_SHIFT      8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_byte_sel_DEFAULT    0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_reserved2_MASK      0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_reserved2_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_reserved2_BITS      2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_reserved2_SHIFT     6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_ovr_step_MASK       0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_ovr_step_ALIGN      0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_ovr_step_BITS       6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_ovr_step_SHIFT      0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_P_ovr_step_DEFAULT        0

/***************************************************************************
 *VDL_OVRIDE_BYTE_R_N - Read Byte DQSN VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_busy_MASK           0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_busy_ALIGN          0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_busy_BITS           1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_busy_SHIFT          31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_busy_DEFAULT        0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_reserved0_MASK      0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_reserved0_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_reserved0_BITS      13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_reserved0_SHIFT     18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_ovr_force_MASK      0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_ovr_force_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_ovr_force_BITS      1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_ovr_force_SHIFT     17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_ovr_force_DEFAULT   0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_ovr_en_MASK         0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_ovr_en_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_ovr_en_BITS         1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_ovr_en_SHIFT        16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_ovr_en_DEFAULT      0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_reserved1_MASK      0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_reserved1_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_reserved1_BITS      7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_reserved1_SHIFT     9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_byte_sel_MASK       0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_byte_sel_ALIGN      0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_byte_sel_BITS       1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_byte_sel_SHIFT      8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_byte_sel_DEFAULT    0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_reserved2_MASK      0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_reserved2_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_reserved2_BITS      2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_reserved2_SHIFT     6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_ovr_step_MASK       0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_ovr_step_ALIGN      0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_ovr_step_BITS       6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_ovr_step_SHIFT      0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_R_N_ovr_step_DEFAULT    0

/***************************************************************************
 *VDL_OVRIDE_BYTE_BIT0_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_W :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_busy_MASK        0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_busy_ALIGN       0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_busy_BITS        1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_busy_SHIFT       31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_busy_DEFAULT     0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_reserved0_MASK   0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_reserved0_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_reserved0_BITS   13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_reserved0_SHIFT  18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_ovr_force_MASK   0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_ovr_force_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_ovr_force_BITS   1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_ovr_force_SHIFT  17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_ovr_en_MASK      0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_ovr_en_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_ovr_en_BITS      1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_ovr_en_SHIFT     16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_ovr_en_DEFAULT   0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_reserved1_MASK   0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_reserved1_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_reserved1_BITS   7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_reserved1_SHIFT  9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_byte_sel_MASK    0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_byte_sel_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_byte_sel_BITS    1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_byte_sel_SHIFT   8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_reserved2_MASK   0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_reserved2_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_reserved2_BITS   2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_reserved2_SHIFT  6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_ovr_step_MASK    0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_ovr_step_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_ovr_step_BITS    6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_ovr_step_SHIFT   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE_BIT1_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_W :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_busy_MASK        0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_busy_ALIGN       0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_busy_BITS        1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_busy_SHIFT       31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_busy_DEFAULT     0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_reserved0_MASK   0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_reserved0_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_reserved0_BITS   13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_reserved0_SHIFT  18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_ovr_force_MASK   0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_ovr_force_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_ovr_force_BITS   1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_ovr_force_SHIFT  17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_ovr_en_MASK      0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_ovr_en_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_ovr_en_BITS      1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_ovr_en_SHIFT     16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_ovr_en_DEFAULT   0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_reserved1_MASK   0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_reserved1_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_reserved1_BITS   7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_reserved1_SHIFT  9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_byte_sel_MASK    0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_byte_sel_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_byte_sel_BITS    1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_byte_sel_SHIFT   8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_reserved2_MASK   0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_reserved2_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_reserved2_BITS   2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_reserved2_SHIFT  6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_ovr_step_MASK    0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_ovr_step_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_ovr_step_BITS    6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_ovr_step_SHIFT   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE_BIT2_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_W :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_busy_MASK        0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_busy_ALIGN       0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_busy_BITS        1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_busy_SHIFT       31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_busy_DEFAULT     0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_reserved0_MASK   0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_reserved0_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_reserved0_BITS   13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_reserved0_SHIFT  18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_ovr_force_MASK   0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_ovr_force_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_ovr_force_BITS   1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_ovr_force_SHIFT  17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_ovr_en_MASK      0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_ovr_en_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_ovr_en_BITS      1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_ovr_en_SHIFT     16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_ovr_en_DEFAULT   0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_reserved1_MASK   0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_reserved1_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_reserved1_BITS   7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_reserved1_SHIFT  9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_byte_sel_MASK    0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_byte_sel_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_byte_sel_BITS    1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_byte_sel_SHIFT   8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_reserved2_MASK   0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_reserved2_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_reserved2_BITS   2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_reserved2_SHIFT  6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_ovr_step_MASK    0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_ovr_step_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_ovr_step_BITS    6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_ovr_step_SHIFT   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE_BIT3_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_W :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_busy_MASK        0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_busy_ALIGN       0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_busy_BITS        1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_busy_SHIFT       31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_busy_DEFAULT     0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_reserved0_MASK   0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_reserved0_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_reserved0_BITS   13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_reserved0_SHIFT  18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_ovr_force_MASK   0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_ovr_force_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_ovr_force_BITS   1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_ovr_force_SHIFT  17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_ovr_en_MASK      0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_ovr_en_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_ovr_en_BITS      1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_ovr_en_SHIFT     16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_ovr_en_DEFAULT   0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_reserved1_MASK   0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_reserved1_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_reserved1_BITS   7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_reserved1_SHIFT  9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_byte_sel_MASK    0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_byte_sel_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_byte_sel_BITS    1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_byte_sel_SHIFT   8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_reserved2_MASK   0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_reserved2_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_reserved2_BITS   2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_reserved2_SHIFT  6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_ovr_step_MASK    0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_ovr_step_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_ovr_step_BITS    6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_ovr_step_SHIFT   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_W_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE_DM_W - Write Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_DM_W :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_busy_MASK          0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_busy_ALIGN         0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_busy_BITS          1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_busy_SHIFT         31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_busy_DEFAULT       0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_DM_W :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_reserved0_MASK     0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_reserved0_ALIGN    0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_reserved0_BITS     13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_reserved0_SHIFT    18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_DM_W :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_ovr_force_MASK     0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_ovr_force_ALIGN    0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_ovr_force_BITS     1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_ovr_force_SHIFT    17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_ovr_force_DEFAULT  0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_DM_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_ovr_en_MASK        0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_ovr_en_ALIGN       0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_ovr_en_BITS        1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_ovr_en_SHIFT       16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_ovr_en_DEFAULT     0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_DM_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_reserved1_MASK     0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_reserved1_ALIGN    0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_reserved1_BITS     7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_reserved1_SHIFT    9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_DM_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_byte_sel_MASK      0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_byte_sel_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_byte_sel_BITS      1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_byte_sel_SHIFT     8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_byte_sel_DEFAULT   0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_DM_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_reserved2_MASK     0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_reserved2_ALIGN    0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_reserved2_BITS     2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_reserved2_SHIFT    6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_DM_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_ovr_step_MASK      0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_ovr_step_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_ovr_step_BITS      6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_ovr_step_SHIFT     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_DM_W_ovr_step_DEFAULT   0

/***************************************************************************
 *VDL_OVRIDE_BYTE_BIT0_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_busy_MASK      0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_busy_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_busy_BITS      1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_busy_SHIFT     31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_busy_DEFAULT   0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_ovr_en_MASK    0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_ovr_en_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_ovr_en_BITS    1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_ovr_en_SHIFT   16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_byte_sel_MASK  0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_byte_sel_BITS  1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_ovr_step_MASK  0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_ovr_step_BITS  6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE_BIT0_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_busy_MASK      0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_busy_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_busy_BITS      1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_busy_SHIFT     31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_busy_DEFAULT   0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_ovr_en_MASK    0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_ovr_en_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_ovr_en_BITS    1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_ovr_en_SHIFT   16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_byte_sel_MASK  0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_byte_sel_BITS  1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT0_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_ovr_step_MASK  0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_ovr_step_BITS  6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT0_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE_BIT1_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_busy_MASK      0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_busy_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_busy_BITS      1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_busy_SHIFT     31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_busy_DEFAULT   0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_ovr_en_MASK    0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_ovr_en_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_ovr_en_BITS    1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_ovr_en_SHIFT   16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_byte_sel_MASK  0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_byte_sel_BITS  1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_ovr_step_MASK  0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_ovr_step_BITS  6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE_BIT1_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_busy_MASK      0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_busy_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_busy_BITS      1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_busy_SHIFT     31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_busy_DEFAULT   0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_ovr_en_MASK    0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_ovr_en_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_ovr_en_BITS    1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_ovr_en_SHIFT   16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_byte_sel_MASK  0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_byte_sel_BITS  1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT1_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_ovr_step_MASK  0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_ovr_step_BITS  6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT1_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE_BIT2_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_busy_MASK      0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_busy_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_busy_BITS      1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_busy_SHIFT     31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_busy_DEFAULT   0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_ovr_en_MASK    0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_ovr_en_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_ovr_en_BITS    1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_ovr_en_SHIFT   16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_byte_sel_MASK  0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_byte_sel_BITS  1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_ovr_step_MASK  0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_ovr_step_BITS  6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE_BIT2_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_busy_MASK      0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_busy_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_busy_BITS      1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_busy_SHIFT     31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_busy_DEFAULT   0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_ovr_en_MASK    0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_ovr_en_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_ovr_en_BITS    1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_ovr_en_SHIFT   16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_byte_sel_MASK  0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_byte_sel_BITS  1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT2_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_ovr_step_MASK  0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_ovr_step_BITS  6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT2_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE_BIT3_R_P - Read DQSP Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_R_P :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_busy_MASK      0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_busy_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_busy_BITS      1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_busy_SHIFT     31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_busy_DEFAULT   0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_R_P :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_reserved0_BITS 13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_reserved0_SHIFT 18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_R_P :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_ovr_force_BITS 1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_ovr_en_MASK    0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_ovr_en_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_ovr_en_BITS    1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_ovr_en_SHIFT   16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_reserved1_BITS 7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_byte_sel_MASK  0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_byte_sel_BITS  1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_reserved2_BITS 2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_ovr_step_MASK  0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_ovr_step_BITS  6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE_BIT3_R_N - Read DQSN Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_R_N :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_busy_MASK      0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_busy_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_busy_BITS      1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_busy_SHIFT     31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_busy_DEFAULT   0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_R_N :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_reserved0_BITS 13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_reserved0_SHIFT 18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_R_N :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_ovr_force_BITS 1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_ovr_en_MASK    0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_ovr_en_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_ovr_en_BITS    1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_ovr_en_SHIFT   16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_reserved1_BITS 7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_byte_sel_MASK  0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_byte_sel_BITS  1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_reserved2_BITS 2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT3_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_ovr_step_MASK  0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_ovr_step_BITS  6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT3_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *VDL_OVRIDE_BYTE_BIT_RD_EN - Read Enable Bit VDL static override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT_RD_EN :: busy [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_busy_MASK     0x80000000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_busy_ALIGN    0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_busy_BITS     1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_busy_SHIFT    31
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_busy_DEFAULT  0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT_RD_EN :: reserved0 [30:18] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_reserved0_MASK 0x7ffc0000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_reserved0_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_reserved0_BITS 13
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_reserved0_SHIFT 18

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT_RD_EN :: ovr_force [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_ovr_force_MASK 0x00020000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_ovr_force_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_ovr_force_BITS 1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_ovr_force_SHIFT 17
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_ovr_force_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT_RD_EN :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_ovr_en_MASK   0x00010000
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_ovr_en_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_ovr_en_BITS   1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_ovr_en_SHIFT  16
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT_RD_EN :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_reserved1_MASK 0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_reserved1_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_reserved1_BITS 7
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_reserved1_SHIFT 9

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT_RD_EN :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_byte_sel_BITS 1
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT_RD_EN :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_reserved2_MASK 0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_reserved2_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_reserved2_BITS 2
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_reserved2_SHIFT 6

/* DDR40_CORE_PHY_ECC_LANE :: VDL_OVRIDE_BYTE_BIT_RD_EN :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_ovr_step_BITS 6
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_ECC_LANE_VDL_OVRIDE_BYTE_BIT_RD_EN_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE_R_P - Read DQSP VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_R_P :: reserved0 [31:17] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_reserved0_MASK  0xfffe0000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_reserved0_BITS  15
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_reserved0_SHIFT 17

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_R_P :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_ovr_en_MASK     0x00010000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_ovr_en_ALIGN    0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_ovr_en_BITS     1
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_ovr_en_SHIFT    16
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_ovr_en_DEFAULT  0

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_R_P :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_reserved1_MASK  0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_reserved1_BITS  7
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_reserved1_SHIFT 9

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_byte_sel_MASK   0x00000100
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_byte_sel_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_byte_sel_BITS   1
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_byte_sel_SHIFT  8
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_R_P :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_reserved2_MASK  0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_reserved2_BITS  2
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_reserved2_SHIFT 6

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_ovr_step_MASK   0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_ovr_step_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_ovr_step_BITS   6
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_ovr_step_SHIFT  0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE_R_N - Read DQSN VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_R_N :: reserved0 [31:17] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_reserved0_MASK  0xfffe0000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_reserved0_BITS  15
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_reserved0_SHIFT 17

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_R_N :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_ovr_en_MASK     0x00010000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_ovr_en_ALIGN    0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_ovr_en_BITS     1
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_ovr_en_SHIFT    16
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_ovr_en_DEFAULT  0

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_R_N :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_reserved1_MASK  0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_reserved1_BITS  7
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_reserved1_SHIFT 9

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_byte_sel_MASK   0x00000100
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_byte_sel_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_byte_sel_BITS   1
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_byte_sel_SHIFT  8
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_R_N :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_reserved2_MASK  0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_reserved2_BITS  2
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_reserved2_SHIFT 6

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_ovr_step_MASK   0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_ovr_step_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_ovr_step_BITS   6
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_ovr_step_SHIFT  0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE_BIT_R_P - Read DQ-P VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_R_P :: reserved0 [31:25] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_reserved0_MASK 0xfe000000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_reserved0_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_reserved0_BITS 7
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_reserved0_SHIFT 25

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_R_P :: dm_ovr_en [24:24] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_dm_ovr_en_MASK 0x01000000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_dm_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_dm_ovr_en_BITS 1
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_dm_ovr_en_SHIFT 24
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_dm_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_R_P :: reserved1 [23:20] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_reserved1_MASK 0x00f00000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_reserved1_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_reserved1_BITS 4
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_reserved1_SHIFT 20

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_R_P :: ovr_en [19:16] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_ovr_en_MASK 0x000f0000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_ovr_en_BITS 4
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_R_P :: reserved2 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_reserved2_MASK 0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_reserved2_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_reserved2_BITS 7
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_reserved2_SHIFT 9

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_R_P :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_byte_sel_BITS 1
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_R_P :: reserved3 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_reserved3_MASK 0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_reserved3_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_reserved3_BITS 2
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_reserved3_SHIFT 6

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_R_P :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_ovr_step_BITS 6
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_P_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE_BIT_R_N - Read DQ-N VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_R_N :: reserved0 [31:25] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_reserved0_MASK 0xfe000000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_reserved0_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_reserved0_BITS 7
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_reserved0_SHIFT 25

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_R_N :: dm_ovr_en [24:24] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_dm_ovr_en_MASK 0x01000000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_dm_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_dm_ovr_en_BITS 1
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_dm_ovr_en_SHIFT 24
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_dm_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_R_N :: reserved1 [23:20] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_reserved1_MASK 0x00f00000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_reserved1_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_reserved1_BITS 4
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_reserved1_SHIFT 20

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_R_N :: ovr_en [19:16] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_ovr_en_MASK 0x000f0000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_ovr_en_BITS 4
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_ovr_en_SHIFT 16
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_R_N :: reserved2 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_reserved2_MASK 0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_reserved2_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_reserved2_BITS 7
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_reserved2_SHIFT 9

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_R_N :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_byte_sel_BITS 1
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_R_N :: reserved3 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_reserved3_MASK 0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_reserved3_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_reserved3_BITS 2
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_reserved3_SHIFT 6

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_R_N :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_ovr_step_BITS 6
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_R_N_ovr_step_DEFAULT 0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE_W - Write DQ Byte VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_W :: reserved0 [31:17] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_reserved0_MASK    0xfffe0000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_reserved0_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_reserved0_BITS    15
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_reserved0_SHIFT   17

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_W :: ovr_en [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_ovr_en_MASK       0x00010000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_ovr_en_ALIGN      0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_ovr_en_BITS       1
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_ovr_en_SHIFT      16
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_ovr_en_DEFAULT    0

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_W :: reserved1 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_reserved1_MASK    0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_reserved1_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_reserved1_BITS    7
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_reserved1_SHIFT   9

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_byte_sel_MASK     0x00000100
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_byte_sel_ALIGN    0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_byte_sel_BITS     1
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_byte_sel_SHIFT    8
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_byte_sel_DEFAULT  0

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_W :: reserved2 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_reserved2_MASK    0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_reserved2_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_reserved2_BITS    2
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_reserved2_SHIFT   6

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_ovr_step_MASK     0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_ovr_step_ALIGN    0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_ovr_step_BITS     6
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_ovr_step_SHIFT    0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_W_ovr_step_DEFAULT  0

/***************************************************************************
 *DYN_VDL_OVRIDE_BYTE_BIT_W - Write DQ Bit VDL dynamic override control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_W :: reserved0 [31:25] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_reserved0_MASK 0xfe000000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_reserved0_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_reserved0_BITS 7
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_reserved0_SHIFT 25

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_W :: dm_ovr_en [24:24] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_dm_ovr_en_MASK 0x01000000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_dm_ovr_en_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_dm_ovr_en_BITS 1
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_dm_ovr_en_SHIFT 24
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_dm_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_W :: reserved1 [23:20] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_reserved1_MASK 0x00f00000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_reserved1_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_reserved1_BITS 4
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_reserved1_SHIFT 20

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_W :: ovr_en [19:16] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_ovr_en_MASK   0x000f0000
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_ovr_en_ALIGN  0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_ovr_en_BITS   4
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_ovr_en_SHIFT  16
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_ovr_en_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_W :: reserved2 [15:09] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_reserved2_MASK 0x0000fe00
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_reserved2_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_reserved2_BITS 7
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_reserved2_SHIFT 9

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_W :: byte_sel [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_byte_sel_MASK 0x00000100
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_byte_sel_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_byte_sel_BITS 1
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_byte_sel_SHIFT 8
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_byte_sel_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_W :: reserved3 [07:06] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_reserved3_MASK 0x000000c0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_reserved3_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_reserved3_BITS 2
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_reserved3_SHIFT 6

/* DDR40_CORE_PHY_ECC_LANE :: DYN_VDL_OVRIDE_BYTE_BIT_W :: ovr_step [05:00] */
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_ovr_step_MASK 0x0000003f
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_ovr_step_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_ovr_step_BITS 6
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_ovr_step_SHIFT 0
#define DDR40_CORE_PHY_ECC_LANE_DYN_VDL_OVRIDE_BYTE_BIT_W_ovr_step_DEFAULT 0

/***************************************************************************
 *READ_DATA_DLY - Word Lane read channel control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: READ_DATA_DLY :: reserved0 [31:03] */
#define DDR40_CORE_PHY_ECC_LANE_READ_DATA_DLY_reserved0_MASK            0xfffffff8
#define DDR40_CORE_PHY_ECC_LANE_READ_DATA_DLY_reserved0_ALIGN           0
#define DDR40_CORE_PHY_ECC_LANE_READ_DATA_DLY_reserved0_BITS            29
#define DDR40_CORE_PHY_ECC_LANE_READ_DATA_DLY_reserved0_SHIFT           3

/* DDR40_CORE_PHY_ECC_LANE :: READ_DATA_DLY :: rd_data_dly [02:00] */
#define DDR40_CORE_PHY_ECC_LANE_READ_DATA_DLY_rd_data_dly_MASK          0x00000007
#define DDR40_CORE_PHY_ECC_LANE_READ_DATA_DLY_rd_data_dly_ALIGN         0
#define DDR40_CORE_PHY_ECC_LANE_READ_DATA_DLY_rd_data_dly_BITS          3
#define DDR40_CORE_PHY_ECC_LANE_READ_DATA_DLY_rd_data_dly_SHIFT         0
#define DDR40_CORE_PHY_ECC_LANE_READ_DATA_DLY_rd_data_dly_DEFAULT       1

/***************************************************************************
 *READ_CONTROL - Word Lane read channel control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: READ_CONTROL :: reserved0 [31:03] */
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_reserved0_MASK             0xfffffff8
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_reserved0_ALIGN            0
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_reserved0_BITS             29
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_reserved0_SHIFT            3

/* DDR40_CORE_PHY_ECC_LANE :: READ_CONTROL :: dq_odt_enable [02:02] */
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_dq_odt_enable_MASK         0x00000004
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_dq_odt_enable_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_dq_odt_enable_BITS         1
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_dq_odt_enable_SHIFT        2
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_dq_odt_enable_DEFAULT      1

/* DDR40_CORE_PHY_ECC_LANE :: READ_CONTROL :: dq_odt_te_adj [01:01] */
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_dq_odt_te_adj_MASK         0x00000002
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_dq_odt_te_adj_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_dq_odt_te_adj_BITS         1
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_dq_odt_te_adj_SHIFT        1
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_dq_odt_te_adj_DEFAULT      1

/* DDR40_CORE_PHY_ECC_LANE :: READ_CONTROL :: dq_odt_le_adj [00:00] */
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_dq_odt_le_adj_MASK         0x00000001
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_dq_odt_le_adj_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_dq_odt_le_adj_BITS         1
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_dq_odt_le_adj_SHIFT        0
#define DDR40_CORE_PHY_ECC_LANE_READ_CONTROL_dq_odt_le_adj_DEFAULT      0

/***************************************************************************
 *READ_FIFO_DATA_0 - Read fifo data register, first data
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_DATA_0 :: reserved0 [31:12] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_0_reserved0_MASK         0xfffff000
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_0_reserved0_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_0_reserved0_BITS         20
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_0_reserved0_SHIFT        12

/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_DATA_0 :: data_p [11:08] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_0_data_p_MASK            0x00000f00
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_0_data_p_ALIGN           0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_0_data_p_BITS            4
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_0_data_p_SHIFT           8

/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_DATA_0 :: reserved1 [07:04] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_0_reserved1_MASK         0x000000f0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_0_reserved1_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_0_reserved1_BITS         4
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_0_reserved1_SHIFT        4

/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_DATA_0 :: data_n [03:00] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_0_data_n_MASK            0x0000000f
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_0_data_n_ALIGN           0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_0_data_n_BITS            4
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_0_data_n_SHIFT           0

/***************************************************************************
 *READ_FIFO_DATA_1 - Read fifo data register, second data
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_DATA_1 :: reserved0 [31:12] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_1_reserved0_MASK         0xfffff000
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_1_reserved0_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_1_reserved0_BITS         20
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_1_reserved0_SHIFT        12

/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_DATA_1 :: data_p [11:08] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_1_data_p_MASK            0x00000f00
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_1_data_p_ALIGN           0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_1_data_p_BITS            4
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_1_data_p_SHIFT           8

/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_DATA_1 :: reserved1 [07:04] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_1_reserved1_MASK         0x000000f0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_1_reserved1_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_1_reserved1_BITS         4
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_1_reserved1_SHIFT        4

/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_DATA_1 :: data_n [03:00] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_1_data_n_MASK            0x0000000f
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_1_data_n_ALIGN           0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_1_data_n_BITS            4
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_1_data_n_SHIFT           0

/***************************************************************************
 *READ_FIFO_DATA_2 - Read fifo data register, third data
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_DATA_2 :: reserved0 [31:12] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_2_reserved0_MASK         0xfffff000
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_2_reserved0_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_2_reserved0_BITS         20
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_2_reserved0_SHIFT        12

/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_DATA_2 :: data_p [11:08] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_2_data_p_MASK            0x00000f00
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_2_data_p_ALIGN           0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_2_data_p_BITS            4
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_2_data_p_SHIFT           8

/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_DATA_2 :: reserved1 [07:04] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_2_reserved1_MASK         0x000000f0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_2_reserved1_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_2_reserved1_BITS         4
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_2_reserved1_SHIFT        4

/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_DATA_2 :: data_n [03:00] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_2_data_n_MASK            0x0000000f
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_2_data_n_ALIGN           0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_2_data_n_BITS            4
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_2_data_n_SHIFT           0

/***************************************************************************
 *READ_FIFO_DATA_3 - Read fifo data register, fourth data
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_DATA_3 :: reserved0 [31:12] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_3_reserved0_MASK         0xfffff000
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_3_reserved0_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_3_reserved0_BITS         20
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_3_reserved0_SHIFT        12

/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_DATA_3 :: data_p [11:08] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_3_data_p_MASK            0x00000f00
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_3_data_p_ALIGN           0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_3_data_p_BITS            4
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_3_data_p_SHIFT           8

/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_DATA_3 :: reserved1 [07:04] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_3_reserved1_MASK         0x000000f0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_3_reserved1_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_3_reserved1_BITS         4
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_3_reserved1_SHIFT        4

/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_DATA_3 :: data_n [03:00] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_3_data_n_MASK            0x0000000f
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_3_data_n_ALIGN           0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_3_data_n_BITS            4
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_DATA_3_data_n_SHIFT           0

/***************************************************************************
 *READ_FIFO_STATUS - Read fifo status register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_STATUS :: reserved0 [31:04] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_STATUS_reserved0_MASK         0xfffffff0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_STATUS_reserved0_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_STATUS_reserved0_BITS         28
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_STATUS_reserved0_SHIFT        4

/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_STATUS :: status0 [03:00] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_STATUS_status0_MASK           0x0000000f
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_STATUS_status0_ALIGN          0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_STATUS_status0_BITS           4
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_STATUS_status0_SHIFT          0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_STATUS_status0_DEFAULT        0

/***************************************************************************
 *READ_FIFO_CLEAR - Read fifo status clear register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_CLEAR :: reserved0 [31:01] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_CLEAR_reserved0_MASK          0xfffffffe
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_CLEAR_reserved0_ALIGN         0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_CLEAR_reserved0_BITS          31
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_CLEAR_reserved0_SHIFT         1

/* DDR40_CORE_PHY_ECC_LANE :: READ_FIFO_CLEAR :: clear [00:00] */
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_CLEAR_clear_MASK              0x00000001
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_CLEAR_clear_ALIGN             0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_CLEAR_clear_BITS              1
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_CLEAR_clear_SHIFT             0
#define DDR40_CORE_PHY_ECC_LANE_READ_FIFO_CLEAR_clear_DEFAULT           0

/***************************************************************************
 *IDLE_PAD_CONTROL - Idle mode SSTL pad control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: IDLE_PAD_CONTROL :: idle [31:31] */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_idle_MASK              0x80000000
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_idle_ALIGN             0
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_idle_BITS              1
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_idle_SHIFT             31
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_idle_DEFAULT           0

/* DDR40_CORE_PHY_ECC_LANE :: IDLE_PAD_CONTROL :: reserved0 [30:24] */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_reserved0_MASK         0x7f000000
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_reserved0_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_reserved0_BITS         7
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_reserved0_SHIFT        24

/* DDR40_CORE_PHY_ECC_LANE :: IDLE_PAD_CONTROL :: auto_dq_rxenb_mode [23:22] */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_auto_dq_rxenb_mode_MASK 0x00c00000
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_auto_dq_rxenb_mode_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_auto_dq_rxenb_mode_BITS 2
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_auto_dq_rxenb_mode_SHIFT 22
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_auto_dq_rxenb_mode_DEFAULT 1

/* DDR40_CORE_PHY_ECC_LANE :: IDLE_PAD_CONTROL :: auto_dq_iddq_mode [21:20] */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_auto_dq_iddq_mode_MASK 0x00300000
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_auto_dq_iddq_mode_ALIGN 0
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_auto_dq_iddq_mode_BITS 2
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_auto_dq_iddq_mode_SHIFT 20
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_auto_dq_iddq_mode_DEFAULT 1

/* DDR40_CORE_PHY_ECC_LANE :: IDLE_PAD_CONTROL :: dq_rxenb [19:19] */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_rxenb_MASK          0x00080000
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_rxenb_ALIGN         0
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_rxenb_BITS          1
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_rxenb_SHIFT         19
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_rxenb_DEFAULT       1

/* DDR40_CORE_PHY_ECC_LANE :: IDLE_PAD_CONTROL :: dq_iddq [18:18] */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_iddq_MASK           0x00040000
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_iddq_ALIGN          0
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_iddq_BITS           1
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_iddq_SHIFT          18
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_iddq_DEFAULT        1

/* DDR40_CORE_PHY_ECC_LANE :: IDLE_PAD_CONTROL :: dq_reb [17:17] */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_reb_MASK            0x00020000
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_reb_ALIGN           0
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_reb_BITS            1
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_reb_SHIFT           17
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_reb_DEFAULT         1

/* DDR40_CORE_PHY_ECC_LANE :: IDLE_PAD_CONTROL :: dq_oeb [16:16] */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_oeb_MASK            0x00010000
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_oeb_ALIGN           0
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_oeb_BITS            1
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_oeb_SHIFT           16
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dq_oeb_DEFAULT         1

/* DDR40_CORE_PHY_ECC_LANE :: IDLE_PAD_CONTROL :: read_enb_rxenb [15:15] */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_rxenb_MASK    0x00008000
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_rxenb_ALIGN   0
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_rxenb_BITS    1
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_rxenb_SHIFT   15
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_rxenb_DEFAULT 0

/* DDR40_CORE_PHY_ECC_LANE :: IDLE_PAD_CONTROL :: read_enb_iddq [14:14] */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_iddq_MASK     0x00004000
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_iddq_ALIGN    0
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_iddq_BITS     1
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_iddq_SHIFT    14
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_iddq_DEFAULT  0

/* DDR40_CORE_PHY_ECC_LANE :: IDLE_PAD_CONTROL :: read_enb_reb [13:13] */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_reb_MASK      0x00002000
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_reb_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_reb_BITS      1
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_reb_SHIFT     13
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_reb_DEFAULT   1

/* DDR40_CORE_PHY_ECC_LANE :: IDLE_PAD_CONTROL :: read_enb_oeb [12:12] */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_oeb_MASK      0x00001000
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_oeb_ALIGN     0
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_oeb_BITS      1
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_oeb_SHIFT     12
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_read_enb_oeb_DEFAULT   0

/* DDR40_CORE_PHY_ECC_LANE :: IDLE_PAD_CONTROL :: dqs_rxenb [11:11] */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_rxenb_MASK         0x00000800
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_rxenb_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_rxenb_BITS         1
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_rxenb_SHIFT        11
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_rxenb_DEFAULT      1

/* DDR40_CORE_PHY_ECC_LANE :: IDLE_PAD_CONTROL :: dqs_iddq [10:10] */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_iddq_MASK          0x00000400
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_iddq_ALIGN         0
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_iddq_BITS          1
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_iddq_SHIFT         10
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_iddq_DEFAULT       1

/* DDR40_CORE_PHY_ECC_LANE :: IDLE_PAD_CONTROL :: dqs_reb [09:09] */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_reb_MASK           0x00000200
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_reb_ALIGN          0
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_reb_BITS           1
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_reb_SHIFT          9
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_reb_DEFAULT        1

/* DDR40_CORE_PHY_ECC_LANE :: IDLE_PAD_CONTROL :: dqs_oeb [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_oeb_MASK           0x00000100
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_oeb_ALIGN          0
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_oeb_BITS           1
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_oeb_SHIFT          8
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_dqs_oeb_DEFAULT        1

/* DDR40_CORE_PHY_ECC_LANE :: IDLE_PAD_CONTROL :: reserved1 [07:00] */
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_reserved1_MASK         0x000000ff
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_reserved1_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_reserved1_BITS         8
#define DDR40_CORE_PHY_ECC_LANE_IDLE_PAD_CONTROL_reserved1_SHIFT        0

/***************************************************************************
 *DRIVE_PAD_CTL - SSTL pad drive characteristics control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: DRIVE_PAD_CTL :: reserved0 [31:12] */
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_reserved0_MASK            0xfffff000
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_reserved0_ALIGN           0
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_reserved0_BITS            20
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_reserved0_SHIFT           12

/* DDR40_CORE_PHY_ECC_LANE :: DRIVE_PAD_CTL :: no_dqs_rd [11:11] */
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_no_dqs_rd_MASK            0x00000800
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_no_dqs_rd_ALIGN           0
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_no_dqs_rd_BITS            1
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_no_dqs_rd_SHIFT           11
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_no_dqs_rd_DEFAULT         0

/* DDR40_CORE_PHY_ECC_LANE :: DRIVE_PAD_CTL :: dqs_always_on [10:10] */
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_dqs_always_on_MASK        0x00000400
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_dqs_always_on_ALIGN       0
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_dqs_always_on_BITS        1
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_dqs_always_on_SHIFT       10
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_dqs_always_on_DEFAULT     1

/* DDR40_CORE_PHY_ECC_LANE :: DRIVE_PAD_CTL :: dqs_tx_dis [09:09] */
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_dqs_tx_dis_MASK           0x00000200
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_dqs_tx_dis_ALIGN          0
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_dqs_tx_dis_BITS           1
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_dqs_tx_dis_SHIFT          9
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_dqs_tx_dis_DEFAULT        0

/* DDR40_CORE_PHY_ECC_LANE :: DRIVE_PAD_CTL :: half_strength_ck [08:08] */
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_half_strength_ck_MASK     0x00000100
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_half_strength_ck_ALIGN    0
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_half_strength_ck_BITS     1
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_half_strength_ck_SHIFT    8
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_half_strength_ck_DEFAULT  0

/* DDR40_CORE_PHY_ECC_LANE :: DRIVE_PAD_CTL :: half_strength [07:07] */
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_half_strength_MASK        0x00000080
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_half_strength_ALIGN       0
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_half_strength_BITS        1
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_half_strength_SHIFT       7
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_half_strength_DEFAULT     0

/* DDR40_CORE_PHY_ECC_LANE :: DRIVE_PAD_CTL :: rdqs_en [06:06] */
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_rdqs_en_MASK              0x00000040
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_rdqs_en_ALIGN             0
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_rdqs_en_BITS              1
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_rdqs_en_SHIFT             6
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_rdqs_en_DEFAULT           0

/* DDR40_CORE_PHY_ECC_LANE :: DRIVE_PAD_CTL :: gddr_symmetry [05:05] */
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_gddr_symmetry_MASK        0x00000020
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_gddr_symmetry_ALIGN       0
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_gddr_symmetry_BITS        1
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_gddr_symmetry_SHIFT       5
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_gddr_symmetry_DEFAULT     0

/* DDR40_CORE_PHY_ECC_LANE :: DRIVE_PAD_CTL :: vddo_volts [04:03] */
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_vddo_volts_MASK           0x00000018
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_vddo_volts_ALIGN          0
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_vddo_volts_BITS           2
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_vddo_volts_SHIFT          3
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_vddo_volts_DEFAULT        0

/* DDR40_CORE_PHY_ECC_LANE :: DRIVE_PAD_CTL :: rt60b [02:02] */
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_rt60b_MASK                0x00000004
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_rt60b_ALIGN               0
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_rt60b_BITS                1
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_rt60b_SHIFT               2
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_rt60b_DEFAULT             0

/* DDR40_CORE_PHY_ECC_LANE :: DRIVE_PAD_CTL :: rt120b_g [01:01] */
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_rt120b_g_MASK             0x00000002
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_rt120b_g_ALIGN            0
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_rt120b_g_BITS             1
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_rt120b_g_SHIFT            1
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_rt120b_g_DEFAULT          1

/* DDR40_CORE_PHY_ECC_LANE :: DRIVE_PAD_CTL :: g_ddr [00:00] */
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_g_ddr_MASK                0x00000001
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_g_ddr_ALIGN               0
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_g_ddr_BITS                1
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_g_ddr_SHIFT               0
#define DDR40_CORE_PHY_ECC_LANE_DRIVE_PAD_CTL_g_ddr_DEFAULT             0

/***************************************************************************
 *CLOCK_PAD_DISABLE - Clock pad disable register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: CLOCK_PAD_DISABLE :: reserved0 [31:03] */
#define DDR40_CORE_PHY_ECC_LANE_CLOCK_PAD_DISABLE_reserved0_MASK        0xfffffff8
#define DDR40_CORE_PHY_ECC_LANE_CLOCK_PAD_DISABLE_reserved0_ALIGN       0
#define DDR40_CORE_PHY_ECC_LANE_CLOCK_PAD_DISABLE_reserved0_BITS        29
#define DDR40_CORE_PHY_ECC_LANE_CLOCK_PAD_DISABLE_reserved0_SHIFT       3

/* DDR40_CORE_PHY_ECC_LANE :: CLOCK_PAD_DISABLE :: dm_pad_dis [02:02] */
#define DDR40_CORE_PHY_ECC_LANE_CLOCK_PAD_DISABLE_dm_pad_dis_MASK       0x00000004
#define DDR40_CORE_PHY_ECC_LANE_CLOCK_PAD_DISABLE_dm_pad_dis_ALIGN      0
#define DDR40_CORE_PHY_ECC_LANE_CLOCK_PAD_DISABLE_dm_pad_dis_BITS       1
#define DDR40_CORE_PHY_ECC_LANE_CLOCK_PAD_DISABLE_dm_pad_dis_SHIFT      2
#define DDR40_CORE_PHY_ECC_LANE_CLOCK_PAD_DISABLE_dm_pad_dis_DEFAULT    0

/* DDR40_CORE_PHY_ECC_LANE :: CLOCK_PAD_DISABLE :: reserved1 [01:00] */
#define DDR40_CORE_PHY_ECC_LANE_CLOCK_PAD_DISABLE_reserved1_MASK        0x00000003
#define DDR40_CORE_PHY_ECC_LANE_CLOCK_PAD_DISABLE_reserved1_ALIGN       0
#define DDR40_CORE_PHY_ECC_LANE_CLOCK_PAD_DISABLE_reserved1_BITS        2
#define DDR40_CORE_PHY_ECC_LANE_CLOCK_PAD_DISABLE_reserved1_SHIFT       0

/***************************************************************************
 *WR_PREAMBLE_MODE - Write cycle preamble control register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: WR_PREAMBLE_MODE :: reserved0 [31:02] */
#define DDR40_CORE_PHY_ECC_LANE_WR_PREAMBLE_MODE_reserved0_MASK         0xfffffffc
#define DDR40_CORE_PHY_ECC_LANE_WR_PREAMBLE_MODE_reserved0_ALIGN        0
#define DDR40_CORE_PHY_ECC_LANE_WR_PREAMBLE_MODE_reserved0_BITS         30
#define DDR40_CORE_PHY_ECC_LANE_WR_PREAMBLE_MODE_reserved0_SHIFT        2

/* DDR40_CORE_PHY_ECC_LANE :: WR_PREAMBLE_MODE :: long [01:01] */
#define DDR40_CORE_PHY_ECC_LANE_WR_PREAMBLE_MODE_long_MASK              0x00000002
#define DDR40_CORE_PHY_ECC_LANE_WR_PREAMBLE_MODE_long_ALIGN             0
#define DDR40_CORE_PHY_ECC_LANE_WR_PREAMBLE_MODE_long_BITS              1
#define DDR40_CORE_PHY_ECC_LANE_WR_PREAMBLE_MODE_long_SHIFT             1
#define DDR40_CORE_PHY_ECC_LANE_WR_PREAMBLE_MODE_long_DEFAULT           0

/* DDR40_CORE_PHY_ECC_LANE :: WR_PREAMBLE_MODE :: mode [00:00] */
#define DDR40_CORE_PHY_ECC_LANE_WR_PREAMBLE_MODE_mode_MASK              0x00000001
#define DDR40_CORE_PHY_ECC_LANE_WR_PREAMBLE_MODE_mode_ALIGN             0
#define DDR40_CORE_PHY_ECC_LANE_WR_PREAMBLE_MODE_mode_BITS              1
#define DDR40_CORE_PHY_ECC_LANE_WR_PREAMBLE_MODE_mode_SHIFT             0
#define DDR40_CORE_PHY_ECC_LANE_WR_PREAMBLE_MODE_mode_DEFAULT           0

/***************************************************************************
 *PHYBIST_VDL_ADJ - PHYBIST mode VDL step select adjustment register
 ***************************************************************************/
/* DDR40_CORE_PHY_ECC_LANE :: PHYBIST_VDL_ADJ :: reserved0 [31:29] */
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_reserved0_MASK          0xe0000000
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_reserved0_ALIGN         0
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_reserved0_BITS          3
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_reserved0_SHIFT         29

/* DDR40_CORE_PHY_ECC_LANE :: PHYBIST_VDL_ADJ :: dq1_vdl_adj [28:24] */
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dq1_vdl_adj_MASK        0x1f000000
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dq1_vdl_adj_ALIGN       0
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dq1_vdl_adj_BITS        5
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dq1_vdl_adj_SHIFT       24
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dq1_vdl_adj_DEFAULT     0

/* DDR40_CORE_PHY_ECC_LANE :: PHYBIST_VDL_ADJ :: reserved1 [23:21] */
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_reserved1_MASK          0x00e00000
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_reserved1_ALIGN         0
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_reserved1_BITS          3
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_reserved1_SHIFT         21

/* DDR40_CORE_PHY_ECC_LANE :: PHYBIST_VDL_ADJ :: dq0_vdl_adj [20:16] */
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dq0_vdl_adj_MASK        0x001f0000
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dq0_vdl_adj_ALIGN       0
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dq0_vdl_adj_BITS        5
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dq0_vdl_adj_SHIFT       16
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dq0_vdl_adj_DEFAULT     0

/* DDR40_CORE_PHY_ECC_LANE :: PHYBIST_VDL_ADJ :: reserved2 [15:13] */
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_reserved2_MASK          0x0000e000
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_reserved2_ALIGN         0
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_reserved2_BITS          3
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_reserved2_SHIFT         13

/* DDR40_CORE_PHY_ECC_LANE :: PHYBIST_VDL_ADJ :: dqs1_vdl_adj [12:08] */
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dqs1_vdl_adj_MASK       0x00001f00
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dqs1_vdl_adj_ALIGN      0
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dqs1_vdl_adj_BITS       5
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dqs1_vdl_adj_SHIFT      8
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dqs1_vdl_adj_DEFAULT    0

/* DDR40_CORE_PHY_ECC_LANE :: PHYBIST_VDL_ADJ :: reserved3 [07:05] */
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_reserved3_MASK          0x000000e0
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_reserved3_ALIGN         0
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_reserved3_BITS          3
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_reserved3_SHIFT         5

/* DDR40_CORE_PHY_ECC_LANE :: PHYBIST_VDL_ADJ :: dqs0_vdl_adj [04:00] */
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dqs0_vdl_adj_MASK       0x0000001f
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dqs0_vdl_adj_ALIGN      0
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dqs0_vdl_adj_BITS       5
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dqs0_vdl_adj_SHIFT      0
#define DDR40_CORE_PHY_ECC_LANE_PHYBIST_VDL_ADJ_dqs0_vdl_adj_DEFAULT    0

#endif /* #ifndef DDR40_CORE_PHY_REGISTERS_H__ */

/* End of File */
