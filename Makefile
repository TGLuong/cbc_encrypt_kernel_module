obj-m := cbc_encrypt.o

KDIR := /lib/modules/`uname -r`/build

all:
	make build
	make reload
	dmesg

build:
	make -C ${KDIR} M=`pwd`

clean:
	make -C ${KDIR} M=`pwd` clean

reload:
	sudo dmesg -C
	sudo insmod cbc_encrypt.ko choice=0 key=0123456789abcdef iv=0123456789abcdef data=0123456789abcdef
	sudo rmmod cbc_encrypt
