cmd_examples/standalone/atmel_df_pow2 := /opt/arm/usr/bin/arm-linux-ld.bfd   -g -Ttext 0xc100000 -o examples/standalone/atmel_df_pow2 -e atmel_df_pow2 examples/standalone/atmel_df_pow2.o examples/standalone/libstubs.o -L /opt/arm/usr/lib/gcc/arm-broadcom-linux-gnueabi/4.7.3 -lgcc