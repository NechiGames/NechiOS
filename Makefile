AN = nasm
GCC = gcc
LD = ld

CFLAGS = -m32 -ffreestanding -c -I.
LDFLAGS = -m elf_i386 -T

clean:
	rm *.o *.bin *.iso

all:
	$(AN) -f elf32 multiboot/boot.asm -o boot.o
	$(GCC) $(CFLAGS) kernel/kernel.c -o kernel.o
	$(GCC) $(CFLAGS) kernel/lib/print.c -o print.o
	$(LD) $(LDFLAGS) linker.ld -o kernel.bin boot.o kernel.o print.o
	mkdir -p iso/boot
	cp kernel.bin iso/boot/kernel.bin
	grub-mkrescue -o NechiOS.iso iso

run:
	qemu-system-i386 -cdrom NechiOS.iso