cmd_examples/standalone/hello_world := /opt/arm/usr/bin/arm-linux-ld.bfd   -g -Ttext 0xc100000 -o examples/standalone/hello_world -e hello_world examples/standalone/hello_world.o examples/standalone/libstubs.o -L /opt/arm/usr/lib/gcc/arm-broadcom-linux-gnueabi/4.7.3 -lgcc