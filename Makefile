AN = nasm
CC = gcc
LD = ld

CFLAGS = -m32 -ffreestanding -c -I.
LDFLAGS = -m elf_i386 -T linker.ld

ASM_SRC = \
	multiboot/boot.asm \
	multiboot/gdt.asm

C_SRC = \
	kernel/kernel.c \
	kernel/lib/print.c \
	kernel/drivers/keyboard/keyboard.c \
	kernel/lib/string.c \
	kernel/shell.c \
	kernel/terminal.c \
	kernel/command.c \
	kernel/componentsOS/RESTART/restart.c \
	kernel/componentsOS/SHUTDOWN/shutdown.c

OBJS = $(ASM_SRC:.asm=.o) $(C_SRC:.c=.o)

all: NechiOS.iso

NechiOS.iso: kernel.bin
	mkdir -p iso/boot
	cp kernel.bin iso/boot/kernel.bin
	grub-mkrescue -o $@ iso

kernel.bin: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.asm
	$(AN) -f elf32 $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

run: NechiOS.iso
	qemu-system-i386 -cdrom NechiOS.iso

clean:
	rm -f $(OBJS) kernel.bin NechiOS.iso

.PHONY: all run clean