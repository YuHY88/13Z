cmd_tools/common/env_embedded.o := cc -Wp,-MD,tools/common/.env_embedded.o.d -Itools -Wall -Wstrict-prototypes -O2 -fomit-frame-pointer -include ../include/libfdt_env.h -idirafterinclude -idirafter../include -idirafter../arch/arm/include  -I../../lib/libfdt -I../lib/libfdt  -I../../tools -I../tools -DCONFIG_SYS_TEXT_BASE=0x1E000000 -DUSE_HOSTCC -D__KERNEL_STRICT_NAMES -D_GNU_SOURCE -c -o tools/common/env_embedded.o tools/common/env_embedded.c

source_tools/common/env_embedded.o := tools/common/env_embedded.c

deps_tools/common/env_embedded.o := \
  ../include/libfdt_env.h \
  ../include/compiler.h \
    $(wildcard include/config/use/stdint.h) \
  /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
  /usr/lib/gcc/i686-linux-gnu/4.6/include/stdint.h \
  /usr/include/stdint.h \
  /usr/include/features.h \
  /usr/include/i386-linux-gnu/bits/predefs.h \
  /usr/include/i386-linux-gnu/sys/cdefs.h \
  /usr/include/i386-linux-gnu/bits/wordsize.h \
  /usr/include/i386-linux-gnu/gnu/stubs.h \
  /usr/include/i386-linux-gnu/gnu/stubs-32.h \
  /usr/include/i386-linux-gnu/bits/wchar.h \
  /usr/include/errno.h \
  /usr/include/i386-linux-gnu/bits/errno.h \
  /usr/include/linux/errno.h \
  /usr/include/i386-linux-gnu/asm/errno.h \
  /usr/include/asm-generic/errno.h \
  /usr/include/asm-generic/errno-base.h \
  /usr/include/stdlib.h \
  /usr/include/i386-linux-gnu/bits/waitflags.h \
  /usr/include/i386-linux-gnu/bits/waitstatus.h \
  /usr/include/endian.h \
  /usr/include/i386-linux-gnu/bits/endian.h \
  /usr/include/i386-linux-gnu/bits/byteswap.h \
  /usr/include/xlocale.h \
  /usr/include/i386-linux-gnu/sys/types.h \
  /usr/include/i386-linux-gnu/bits/types.h \
  /usr/include/i386-linux-gnu/bits/typesizes.h \
  /usr/include/time.h \
  /usr/include/i386-linux-gnu/sys/select.h \
  /usr/include/i386-linux-gnu/bits/select.h \
  /usr/include/i386-linux-gnu/bits/sigset.h \
  /usr/include/i386-linux-gnu/bits/time.h \
  /usr/include/i386-linux-gnu/bits/select2.h \
  /usr/include/i386-linux-gnu/sys/sysmacros.h \
  /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /usr/include/i386-linux-gnu/bits/stdlib.h \
  /usr/include/stdio.h \
  /usr/include/libio.h \
  /usr/include/_G_config.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
  /usr/include/i386-linux-gnu/bits/stdio_lim.h \
  /usr/include/i386-linux-gnu/bits/sys_errlist.h \
  /usr/include/i386-linux-gnu/bits/stdio.h \
  /usr/include/i386-linux-gnu/bits/stdio2.h \
  /usr/include/string.h \
  /usr/include/i386-linux-gnu/bits/string.h \
  /usr/include/i386-linux-gnu/bits/string2.h \
  /usr/include/i386-linux-gnu/bits/string3.h \
  /usr/include/i386-linux-gnu/sys/mman.h \
  /usr/include/i386-linux-gnu/bits/mman.h \
  /usr/include/fcntl.h \
  /usr/include/i386-linux-gnu/bits/fcntl.h \
  /usr/include/i386-linux-gnu/bits/uio.h \
  /usr/include/i386-linux-gnu/bits/stat.h \
  /usr/include/i386-linux-gnu/bits/fcntl2.h \
  /usr/include/byteswap.h \
  /usr/include/i386-linux-gnu/bits/timex.h \
  ../include/linux/types.h \
    $(wildcard include/config/uid16.h) \
  /usr/include/linux/posix_types.h \
  /usr/include/linux/stddef.h \
  /usr/include/i386-linux-gnu/asm/posix_types.h \
  /usr/include/i386-linux-gnu/asm/posix_types_32.h \
  /usr/include/i386-linux-gnu/asm/types.h \
  /usr/include/asm-generic/types.h \
  /usr/include/asm-generic/int-ll64.h \
  /usr/include/i386-linux-gnu/asm/bitsperlong.h \
  /usr/include/asm-generic/bitsperlong.h \
    $(wildcard include/config/64bit.h) \
  /usr/lib/gcc/i686-linux-gnu/4.6/include/stdbool.h \
  ../tools/../common/env_embedded.c \
    $(wildcard include/config/build/envcrc.h) \
    $(wildcard include/config/sys/use/ppcenv.h) \
    $(wildcard include/config/env/addr/redund.h) \
    $(wildcard include/config/env/offset.h) \
  include/config.h \
    $(wildcard include/config/boarddir.h) \
  ../include/config_defaults.h \
    $(wildcard include/config/defaults/h/.h) \
    $(wildcard include/config/bootm/linux.h) \
    $(wildcard include/config/bootm/netbsd.h) \
    $(wildcard include/config/bootm/plan9.h) \
    $(wildcard include/config/bootm/rtems.h) \
    $(wildcard include/config/bootm/vxworks.h) \
    $(wildcard include/config/gzip.h) \
    $(wildcard include/config/zlib.h) \
    $(wildcard include/config/partitions.h) \
  ../include/config_uncmd_spl.h \
    $(wildcard include/config/uncmd/spl/h//.h) \
    $(wildcard include/config/spl/build.h) \
    $(wildcard include/config/cmd/cdp.h) \
    $(wildcard include/config/cmd/dhcp.h) \
    $(wildcard include/config/cmd/dns.h) \
    $(wildcard include/config/cmd/link/local.h) \
    $(wildcard include/config/cmd/nfs.h) \
    $(wildcard include/config/cmd/ping.h) \
    $(wildcard include/config/cmd/rarp.h) \
    $(wildcard include/config/cmd/sntp.h) \
    $(wildcard include/config/cmd/tftpput.h) \
    $(wildcard include/config/cmd/tftpsrv.h) \
    $(wildcard include/config/spl/dm.h) \
    $(wildcard include/config/dm/serial.h) \
    $(wildcard include/config/dm/gpio.h) \
    $(wildcard include/config/dm/i2c.h) \
    $(wildcard include/config/dm/spi.h) \
    $(wildcard include/config/dm/warn.h) \
    $(wildcard include/config/dm/seq/alias.h) \
    $(wildcard include/config/dm/stdio.h) \
  ../include/configs/bcm_katana2.h \
    $(wildcard include/config/katana2.h) \
    $(wildcard include/config/run/ddr/shmoo2.h) \
    $(wildcard include/config/phys/sdram/0.h) \
    $(wildcard include/config/phys/sdram/1.h) \
    $(wildcard include/config/phys/sdram/1/size.h) \
    $(wildcard include/config/phys/sdram/rsvd/size.h) \
    $(wildcard include/config/sys/sdram/base.h) \
    $(wildcard include/config/sys/l2/pl310.h) \
    $(wildcard include/config/sys/pl310/base.h) \
    $(wildcard include/config/spl/max/footprint.h) \
    $(wildcard include/config/nand/iproc/boot.h) \
    $(wildcard include/config/spl/framework.h) \
    $(wildcard include/config/spl/text/base.h) \
    $(wildcard include/config/spl/stack.h) \
    $(wildcard include/config/sys/init/sp/addr.h) \
    $(wildcard include/config/sys/spl/malloc/start.h) \
    $(wildcard include/config/sys/spl/malloc/size.h) \
    $(wildcard include/config/spl/libcommon/support.h) \
    $(wildcard include/config/spl/nand/support.h) \
    $(wildcard include/config/spl/nand/simple.h) \
    $(wildcard include/config/spl/nand/base.h) \
    $(wildcard include/config/spl/nand/ecc.h) \
    $(wildcard include/config/spl/mtd/support.h) \
    $(wildcard include/config/sys/nand/u/boot/offs.h) \
    $(wildcard include/config/sys/nand/page/size.h) \
    $(wildcard include/config/spl/nand/simple/bbt.h) \
    $(wildcard include/config/spl/uboot/start.h) \
    $(wildcard include/config/spl/spi/support.h) \
    $(wildcard include/config/spl/spi/flash/support.h) \
    $(wildcard include/config/spl/spi/load.h) \
    $(wildcard include/config/spl/spi/bus.h) \
    $(wildcard include/config/spl/spi/cs.h) \
    $(wildcard include/config/sys/spi/u/boot/offs.h) \
    $(wildcard include/config/sys/spi/u/boot/size.h) \
    $(wildcard include/config/spl/uboot/end.h) \
    $(wildcard include/config/spl/libgeneric/support.h) \
    $(wildcard include/config/spl/serial/support.h) \
    $(wildcard include/config/sys/ref/clk.h) \
    $(wildcard include/config/sys/ref2/clk.h) \
    $(wildcard include/config/board/early/init/f.h) \
    $(wildcard include/config/board/late/init.h) \
    $(wildcard include/config/nr/dram/banks.h) \
    $(wildcard include/config/sys/malloc/len.h) \
    $(wildcard include/config/stacksize.h) \
    $(wildcard include/config/sys/load/addr.h) \
    $(wildcard include/config/mach/type.h) \
    $(wildcard include/config/sys/stack/size.h) \
    $(wildcard include/config/env/overwrite.h) \
    $(wildcard include/config/sys/ns16550/serial.h) \
    $(wildcard include/config/baudrate.h) \
    $(wildcard include/config/cmd/sf.h) \
    $(wildcard include/config/spi/flash.h) \
    $(wildcard include/config/spi/flash/bar.h) \
    $(wildcard include/config/spi/flash/stmicro.h) \
    $(wildcard include/config/spi/flash/macronix.h) \
    $(wildcard include/config/spi/flash/spansion.h) \
    $(wildcard include/config/spi/flash/sst.h) \
    $(wildcard include/config/spi/flash/winbond.h) \
    $(wildcard include/config/spi/flash/atmel.h) \
    $(wildcard include/config/iproc/qspi.h) \
    $(wildcard include/config/iproc/qspi/bus.h) \
    $(wildcard include/config/iproc/qspi/cs.h) \
    $(wildcard include/config/iproc/bspi/data/lanes.h) \
    $(wildcard include/config/iproc/bspi/addr/lanes.h) \
    $(wildcard include/config/iproc/bspi/read/cmd.h) \
    $(wildcard include/config/iproc/bspi/read/dummy/cycles.h) \
    $(wildcard include/config/sf/default/speed.h) \
    $(wildcard include/config/sf/default/mode.h) \
    $(wildcard include/config/cmd/nand.h) \
    $(wildcard include/config/iproc/nand.h) \
    $(wildcard include/config/sys/max/nand/device.h) \
    $(wildcard include/config/sys/nand/base.h) \
    $(wildcard include/config/sys/nand/onfi/detection.h) \
    $(wildcard include/config/cmd/pci.h) \
    $(wildcard include/config/cmd/pci/enum.h) \
    $(wildcard include/config/pci.h) \
    $(wildcard include/config/pci/scan/show.h) \
    $(wildcard include/config/iproc/pcie.h) \
    $(wildcard include/config/cmd/i2c.h) \
    $(wildcard include/config/sys/i2c.h) \
    $(wildcard include/config/sys/i2c/iproc.h) \
    $(wildcard include/config/sys/iproc/i2c/speed.h) \
    $(wildcard include/config/sys/iproc/i2c/slave.h) \
    $(wildcard include/config/i2c/multi/bus.h) \
    $(wildcard include/config/sys/no/flash.h) \
    $(wildcard include/config/cmd/usb.h) \
    $(wildcard include/config/usb/ehci.h) \
    $(wildcard include/config/usb/ehci/iproc.h) \
    $(wildcard include/config/usb/storage.h) \
    $(wildcard include/config/legacy/usb/init/seq.h) \
    $(wildcard include/config/env/is/in/nand.h) \
    $(wildcard include/config/env/range.h) \
    $(wildcard include/config/nor/iproc/boot.h) \
    $(wildcard include/config/env/is/in/flash.h) \
    $(wildcard include/config/env/addr.h) \
    $(wildcard include/config/sys/flash/base.h) \
    $(wildcard include/config/env/sect/size.h) \
    $(wildcard include/config/env/is/in/spi/flash.h) \
    $(wildcard include/config/env/spi/max/hz.h) \
    $(wildcard include/config/env/spi/mode.h) \
    $(wildcard include/config/env/spi/bus.h) \
    $(wildcard include/config/env/spi/cs.h) \
    $(wildcard include/config/env/is/nowhere.h) \
    $(wildcard include/config/env/size.h) \
    $(wildcard include/config/shmoo/reuse.h) \
    $(wildcard include/config/shmoo/reuse/ddr/32bit.h) \
    $(wildcard include/config/shmoo/reuse/qspi/offset.h) \
    $(wildcard include/config/shmoo/reuse/nand/offset.h) \
    $(wildcard include/config/shmoo/reuse/nand/range.h) \
    $(wildcard include/config/shmoo/reuse/delay/msecs.h) \
    $(wildcard include/config/shmoo/reuse/memtest/length.h) \
    $(wildcard include/config/shmoo/reuse/memtest/start.h) \
    $(wildcard include/config/sys/cbsize.h) \
    $(wildcard include/config/sys/pbsize.h) \
    $(wildcard include/config/sys/prompt.h) \
    $(wildcard include/config/sys/maxargs.h) \
    $(wildcard include/config/sys/bargsize.h) \
    $(wildcard include/config/dos/partition.h) \
    $(wildcard include/config/version/variable.h) \
    $(wildcard include/config/auto/complete.h) \
    $(wildcard include/config/sys/hush/parser.h) \
    $(wildcard include/config/cmdline/editing.h) \
    $(wildcard include/config/command/history.h) \
    $(wildcard include/config/sys/longhelp.h) \
    $(wildcard include/config/crc32/verify.h) \
    $(wildcard include/config/mx/cyclic.h) \
    $(wildcard include/config/cmd/fat.h) \
    $(wildcard include/config/cmd/ext2.h) \
    $(wildcard include/config/fat/write.h) \
    $(wildcard include/config/cmd/memtest.h) \
    $(wildcard include/config/sys/memtest/start.h) \
    $(wildcard include/config/sys/memtest/end.h) \
    $(wildcard include/config/of/libfdt.h) \
    $(wildcard include/config/fit.h) \
    $(wildcard include/config/extra/env/settings.h) \
    $(wildcard include/config/cmd/ubi.h) \
    $(wildcard include/config/cmd/ubifs.h) \
    $(wildcard include/config/rbtree.h) \
    $(wildcard include/config/mtd/partitions.h) \
    $(wildcard include/config/lzo.h) \
    $(wildcard include/config/mtd/debug.h) \
    $(wildcard include/config/mtd/debug/verbose.h) \
    $(wildcard include/config/cmd/hash.h) \
    $(wildcard include/config/hash/verify.h) \
    $(wildcard include/config/sha1.h) \
    $(wildcard include/config/sha256.h) \
    $(wildcard include/config/cmd/time.h) \
    $(wildcard include/config/cmd/bootz.h) \
    $(wildcard include/config/bounce/buffer.h) \
    $(wildcard include/config/bootdelay.h) \
    $(wildcard include/config/cmdline/tag.h) \
    $(wildcard include/config/setup/memory/tags.h) \
    $(wildcard include/config/cmd/mtdparts.h) \
    $(wildcard include/config/mtd/device.h) \
  include/asm/arch/configs.h \
    $(wildcard include/config/sys/ns16550/reg/size.h) \
    $(wildcard include/config/sys/ns16550/clk.h) \
    $(wildcard include/config/sys/ns16550/clk/div.h) \
    $(wildcard include/config/cons/index.h) \
    $(wildcard include/config/sys/ns16550/com1.h) \
    $(wildcard include/config/bcm/xgs/eth.h) \
    $(wildcard include/config/bcm/xgs/eth/gmac.h) \
    $(wildcard include/config/gmac/num.h) \
    $(wildcard include/config/ethprime.h) \
    $(wildcard include/config/phylib.h) \
    $(wildcard include/config/phy/broadcom.h) \
    $(wildcard include/config/phy/reset/delay.h) \
    $(wildcard include/config/cmd/mii.h) \
  ../arch/arm/include/asm/iproc-common/configs.h \
    $(wildcard include/config/iproc.h) \
    $(wildcard include/config/sys/arm/cache/writethrough.h) \
    $(wildcard include/config/sys/text/base.h) \
    $(wildcard include/config/sys/bootm/len.h) \
  ../include/linux/stringify.h \
  ../arch/arm/include/asm/config.h \
    $(wildcard include/config/h/.h) \
    $(wildcard include/config/lmb.h) \
    $(wildcard include/config/sys/boot/ramdisk/high.h) \
    $(wildcard include/config/arm64.h) \
    $(wildcard include/config/phys/64bit.h) \
    $(wildcard include/config/static/rela.h) \
    $(wildcard include/config/ls102xa.h) \
    $(wildcard include/config/cpu/pxa27x.h) \
    $(wildcard include/config/cpu/monahans.h) \
    $(wildcard include/config/cpu/pxa25x.h) \
    $(wildcard include/config/fsl/layerscape.h) \
  ../include/config_fallbacks.h \
    $(wildcard include/config/fallbacks/h.h) \
    $(wildcard include/config/spl.h) \
    $(wildcard include/config/spl/pad/to.h) \
    $(wildcard include/config/spl/max/size.h) \
    $(wildcard include/config/sys/baudrate/table.h) \
    $(wildcard include/config/fs/fat.h) \
    $(wildcard include/config/cmd/ext4.h) \
    $(wildcard include/config/fs/ext4.h) \
    $(wildcard include/config/cmd/ext4/write.h) \
    $(wildcard include/config/ext4/write.h) \
    $(wildcard include/config/cmd/ide.h) \
    $(wildcard include/config/cmd/sata.h) \
    $(wildcard include/config/cmd/scsi.h) \
    $(wildcard include/config/cmd/part.h) \
    $(wildcard include/config/cmd/gpt.h) \
    $(wildcard include/config/mmc.h) \
    $(wildcard include/config/systemace.h) \
    $(wildcard include/config/sandbox.h) \
    $(wildcard include/config/partition/uuids.h) \
    $(wildcard include/config/efi/partition.h) \
    $(wildcard include/config/random/uuid.h) \
    $(wildcard include/config/cmd/uuid.h) \
    $(wildcard include/config/bootp/pxe.h) \
    $(wildcard include/config/lib/uuid.h) \
    $(wildcard include/config/lib/rand.h) \
    $(wildcard include/config/lib/hw/rand.h) \
    $(wildcard include/config/api.h) \
    $(wildcard include/config/lcd.h) \
    $(wildcard include/config/cmd/bmp.h) \
    $(wildcard include/config/fit/signature.h) \
    $(wildcard include/config/image/format/legacy.h) \
    $(wildcard include/config/disable/image/legacy.h) \
  ../include/environment.h \
    $(wildcard include/config/env/offset/redund.h) \
    $(wildcard include/config/env/size/redund.h) \
    $(wildcard include/config/sys/monitor/base.h) \
    $(wildcard include/config/sys/monitor/len.h) \
    $(wildcard include/config/sys/redundand/environment.h) \
    $(wildcard include/config/env/is/embedded.h) \
    $(wildcard include/config/env/is/in/mmc.h) \
    $(wildcard include/config/env/offset/oob.h) \
    $(wildcard include/config/env/is/in/ubi.h) \
    $(wildcard include/config/env/ubi/part.h) \
    $(wildcard include/config/env/ubi/volume.h) \
    $(wildcard include/config/env/ubi/volume/redund.h) \
    $(wildcard include/config/env/is/in/onenand.h) \
    $(wildcard include/config/cmd/saveenv.h) \
    $(wildcard include/config/env/aes.h) \
    $(wildcard include/config/needs/manual/reloc.h) \
    $(wildcard include/config/sys/mmc/env/part.h) \
  ../include/compiler.h \
  ../include/env_attr.h \
  ../include/env_callback.h \
    $(wildcard include/config/env/callback/list/static.h) \
    $(wildcard include/config/silent/console.h) \
    $(wildcard include/config/splashimage/guard.h) \
    $(wildcard include/config/regex.h) \
    $(wildcard include/config/net.h) \
  ../include/env_flags.h \
    $(wildcard include/config/cmd/net.h) \
    $(wildcard include/config/env/flags/list/static.h) \
    $(wildcard include/config/overwrite/ethaddr/once.h) \
    $(wildcard include/config/cmd/env/flags.h) \
  ../include/linker_lists.h \
  ../include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
    $(wildcard include/config/kprobes.h) \
  /usr/include/search.h \

tools/common/env_embedded.o: $(deps_tools/common/env_embedded.o)

$(deps_tools/common/env_embedded.o):
