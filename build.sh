#/bin/sh

gcc \
	-Wall -pedantic -lpthread \
	-nostdlib \
	-ffreestanding \
	-fno-stack-protector \
	-fdata-sections \
	-fno-unwind-tables \
	-fno-asynchronous-unwind-tables \
	-ffunction-sections \
	-Wl,-n \
	-s -Os \
	-no-pie \
	-Wl,--build-id=none \
	-nostartfiles \
	src/start.S src/*.c \
	-o build/ctactoe -ggdb

strip -R .comment build/ctactoe
#strip --strip-all build/c

