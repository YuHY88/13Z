cmd_board/broadcom/bcmkt2/ddr_init_table.o := /opt/arm/usr/bin/arm-linux-gcc -Wp,-MD,board/broadcom/bcmkt2/.ddr_init_table.o.d  -nostdinc -isystem /opt/arm/usr/lib/gcc/arm-broadcom-linux-gnueabi/4.7.3/include -Iinclude  -I../include  -I../arch/arm/include -include ../include/linux/kconfig.h  -I../board/broadcom/bcmkt2 -Iboard/broadcom/bcmkt2 -D__KERNEL__ -D__UBOOT__ -DCONFIG_SYS_TEXT_BASE=0x1E000000 -Wall -Wstrict-prototypes -Wno-format-security -fno-builtin -ffreestanding -Os -fno-stack-protector -fno-delete-null-pointer-checks -g -fstack-usage -Wno-format-nonliteral -D__ARM__ -marm -mno-thumb-interwork -mabi=aapcs-linux -mword-relocations -mno-unaligned-access -ffunction-sections -fdata-sections -fno-common -ffixed-r9 -msoft-float -pipe -march=armv7-a    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(ddr_init_table)"  -D"KBUILD_MODNAME=KBUILD_STR(ddr_init_table)" -c -o board/broadcom/bcmkt2/ddr_init_table.o ../board/broadcom/bcmkt2/ddr_init_table.c

source_board/broadcom/bcmkt2/ddr_init_table.o := ../board/broadcom/bcmkt2/ddr_init_table.c

deps_board/broadcom/bcmkt2/ddr_init_table.o := \
    $(wildcard include/config/ddr750.h) \

board/broadcom/bcmkt2/ddr_init_table.o: $(deps_board/broadcom/bcmkt2/ddr_init_table.o)

$(deps_board/broadcom/bcmkt2/ddr_init_table.o):
