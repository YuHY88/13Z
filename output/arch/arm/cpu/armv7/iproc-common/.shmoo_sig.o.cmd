cmd_arch/arm/cpu/armv7/iproc-common/shmoo_sig.o := /opt/arm/usr/bin/arm-linux-gcc -Wp,-MD,arch/arm/cpu/armv7/iproc-common/.shmoo_sig.o.d  -nostdinc -isystem /opt/arm/usr/lib/gcc/arm-broadcom-linux-gnueabi/4.7.3/include -Iinclude  -I../include  -I../arch/arm/include -include ../include/linux/kconfig.h  -I../arch/arm/cpu/armv7/iproc-common -Iarch/arm/cpu/armv7/iproc-common -D__KERNEL__ -D__UBOOT__ -DCONFIG_SYS_TEXT_BASE=0x1E000000 -Wall -Wstrict-prototypes -Wno-format-security -fno-builtin -ffreestanding -Os -fno-stack-protector -fno-delete-null-pointer-checks -g -fstack-usage -Wno-format-nonliteral -D__ARM__ -marm -mno-thumb-interwork -mabi=aapcs-linux -mword-relocations -mno-unaligned-access -ffunction-sections -fdata-sections -fno-common -ffixed-r9 -msoft-float -pipe -march=armv7-a    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(shmoo_sig)"  -D"KBUILD_MODNAME=KBUILD_STR(shmoo_sig)" -c -o arch/arm/cpu/armv7/iproc-common/shmoo_sig.o ../arch/arm/cpu/armv7/iproc-common/shmoo_sig.c

source_arch/arm/cpu/armv7/iproc-common/shmoo_sig.o := ../arch/arm/cpu/armv7/iproc-common/shmoo_sig.c

deps_arch/arm/cpu/armv7/iproc-common/shmoo_sig.o := \
  /opt/arm/usr/lib/gcc/arm-broadcom-linux-gnueabi/4.7.3/include/stdint.h \
  /opt/arm/usr/lib/gcc/arm-broadcom-linux-gnueabi/4.7.3/include/stdint-gcc.h \
  ../arch/arm/cpu/armv7/iproc-common/shmoo_sig.h \

arch/arm/cpu/armv7/iproc-common/shmoo_sig.o: $(deps_arch/arm/cpu/armv7/iproc-common/shmoo_sig.o)

$(deps_arch/arm/cpu/armv7/iproc-common/shmoo_sig.o):
