AN = nasm
GCC = gcc
LD = ld

CFLAGS = -m32 -ffreestanding -c
LDFLAGS = -m elf_i386 -T

clean:
	rm *.o *.bin *.iso

all:
	$(AN) -f elf32 kernel/boot.asm -o boot.o
	$(GCC) $(CFLAGS) kernel/kernel.c -o kernel.o
	$(LD) $(LDFLAGS) kernel/linker.ld -o kernel.bin boot.o kernel.o
	grub-mkrescue -o NechiOS.iso iso

run:
	qemu-system-i386 -cdrom NechiOS.iso