build:
	i686-elf-as boot/boot.s -o boot.o
	i686-elf-gcc kernel/kernel.c drivers/vga.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -T linker.ld -o prostyos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc
	cp prostyos.bin build/boot
	cp ../boot/grub.cfg build/boot/grub
	grub-mkrescue -o prostyos.iso build

clean:
	rm -rf build
	rm prostyos.iso

run:
	qemu-system-i386 -cdrom prostyos.iso