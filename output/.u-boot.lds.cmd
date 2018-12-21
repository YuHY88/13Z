cmd_u-boot.lds := /opt/arm/usr/bin/arm-linux-gcc -E -Wp,-MD,./.u-boot.lds.d -D__KERNEL__ -D__UBOOT__ -DCONFIG_SYS_TEXT_BASE=0x1E000000   -D__ARM__ -marm -mno-thumb-interwork  -mabi=aapcs-linux  -mword-relocations  -mno-unaligned-access  -ffunction-sections -fdata-sections -fno-common -ffixed-r9  -msoft-float  -pipe  -march=armv7-a   -Iinclude  -I../include  -I../arch/arm/include -include ../include/linux/kconfig.h  -nostdinc -isystem /opt/arm/usr/lib/gcc/arm-broadcom-linux-gnueabi/4.7.3/include -include ../include/u-boot/u-boot.lds.h -DCPUDIR=arch/arm/cpu/armv7  -ansi -D__ASSEMBLY__ -x assembler-with-cpp -P -o u-boot.lds ../board/broadcom/bcmkt2/../bcm_xgs/u-boot-l2c.lds

source_u-boot.lds := ../board/broadcom/bcmkt2/../bcm_xgs/u-boot-l2c.lds

deps_u-boot.lds := \
  ../include/u-boot/u-boot.lds.h \

u-boot.lds: $(deps_u-boot.lds)

$(deps_u-boot.lds):
