#/bin/sh

#gcc -nostartfiles -ggdb src/*.S src/*.c -o build/c
#exit

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
	-o build/c -ggdb



strip -R .comment build/c

