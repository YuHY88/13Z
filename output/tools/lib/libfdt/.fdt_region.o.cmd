cmd_tools/lib/libfdt/fdt_region.o := cc -Wp,-MD,tools/lib/libfdt/.fdt_region.o.d -Itools -Wall -Wstrict-prototypes -O2 -fomit-frame-pointer -include ../include/libfdt_env.h -idirafterinclude -idirafter../include -idirafter../arch/arm/include  -I../../lib/libfdt -I../lib/libfdt  -I../../tools -I../tools -DCONFIG_SYS_TEXT_BASE=0x1E000000 -DUSE_HOSTCC -D__KERNEL_STRICT_NAMES -D_GNU_SOURCE -c -o tools/lib/libfdt/fdt_region.o tools/lib/libfdt/fdt_region.c

source_tools/lib/libfdt/fdt_region.o := tools/lib/libfdt/fdt_region.c

deps_tools/lib/libfdt/fdt_region.o := \
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
  ../tools/../lib/libfdt/fdt_region.c \
  ../include/libfdt_env.h \
  ../tools/fdt_host.h \
  ../tools/../include/libfdt.h \
  ../include/fdt.h \
  ../tools/../include/fdt_support.h \
    $(wildcard include/config/of/libfdt.h) \
    $(wildcard include/config/has/fsl/dr/usb.h) \
    $(wildcard include/config/has/fsl/mph/usb.h) \
    $(wildcard include/config/sys/fsl/sec/compat.h) \
    $(wildcard include/config/pci.h) \
    $(wildcard include/config/sys/fdt/pad.h) \
    $(wildcard include/config/of/board/setup.h) \
    $(wildcard include/config/of/system/setup.h) \
  ../tools/../lib/libfdt/libfdt_internal.h \

tools/lib/libfdt/fdt_region.o: $(deps_tools/lib/libfdt/fdt_region.o)

$(deps_tools/lib/libfdt/fdt_region.o):
