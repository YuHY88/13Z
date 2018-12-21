cmd_drivers/mtd/ubi/crc32.o := /opt/arm/usr/bin/arm-linux-gcc -Wp,-MD,drivers/mtd/ubi/.crc32.o.d  -nostdinc -isystem /opt/arm/usr/lib/gcc/arm-broadcom-linux-gnueabi/4.7.3/include -Iinclude  -I../include  -I../arch/arm/include -include ../include/linux/kconfig.h  -I../drivers/mtd/ubi -Idrivers/mtd/ubi -D__KERNEL__ -D__UBOOT__ -DCONFIG_SYS_TEXT_BASE=0x1E000000 -Wall -Wstrict-prototypes -Wno-format-security -fno-builtin -ffreestanding -Os -fno-stack-protector -fno-delete-null-pointer-checks -g -fstack-usage -Wno-format-nonliteral -D__ARM__ -marm -mno-thumb-interwork -mabi=aapcs-linux -mword-relocations -mno-unaligned-access -ffunction-sections -fdata-sections -fno-common -ffixed-r9 -msoft-float -pipe -march=armv7-a    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(crc32)"  -D"KBUILD_MODNAME=KBUILD_STR(crc32)" -c -o drivers/mtd/ubi/crc32.o ../drivers/mtd/ubi/crc32.c

source_drivers/mtd/ubi/crc32.o := ../drivers/mtd/ubi/crc32.c

deps_drivers/mtd/ubi/crc32.o := \
  ../include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/use/stdint.h) \
  ../include/linux/posix_types.h \
  ../include/linux/stddef.h \
  ../arch/arm/include/asm/posix_types.h \
  ../arch/arm/include/asm/types.h \
    $(wildcard include/config/arm64.h) \
    $(wildcard include/config/phys/64bit.h) \
  /opt/arm/usr/lib/gcc/arm-broadcom-linux-gnueabi/4.7.3/include/stdbool.h \
  ../arch/arm/include/asm/byteorder.h \
  ../include/linux/byteorder/little_endian.h \
  ../include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
    $(wildcard include/config/kprobes.h) \
  ../include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  ../include/linux/compiler-gcc4.h \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  ../include/linux/byteorder/swab.h \
  ../include/linux/byteorder/generic.h \
  ../drivers/mtd/ubi/crc32defs.h \
  ../drivers/mtd/ubi/crc32table.h \

drivers/mtd/ubi/crc32.o: $(deps_drivers/mtd/ubi/crc32.o)

$(deps_drivers/mtd/ubi/crc32.o):
