cmd_u-boot.bin := /opt/arm/usr/bin/arm-linux-objcopy --gap-fill=0xff  -j .text -j .secure_text -j .rodata -j .hash -j .data -j .got -j .got.plt -j .u_boot_list -j .rel.dyn -j .mmu_table -O binary  u-boot u-boot.bin