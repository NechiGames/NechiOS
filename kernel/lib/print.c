#include "include/lib/print.h"

int cursor_pos = 0;

static inline void outb(unsigned short port, unsigned char val)
{
    __asm__ volatile("outb %0, %1"
                     :
                     : "a"(val), "Nd"(port));
}

// ---------------- CURSOR ----------------

void move_cursor(int pos)
{
    outb(0x3D4, 0x0F);
    outb(0x3D5, (unsigned char)(pos & 0xFF));

    outb(0x3D4, 0x0E);
    outb(0x3D5, (unsigned char)((pos >> 8) & 0xFF));
}

// ---------------- PRINT ----------------

void print_char(char c)
{
    unsigned short *vga = (unsigned short *)0xB8000;

    if (c == '\n')
    {
        cursor_pos = (cursor_pos / 80 + 1) * 80;
        move_cursor(cursor_pos);
        return;
    }

    vga[cursor_pos] = (0x07 << 8) | c;
    cursor_pos++;

    move_cursor(cursor_pos);
}

void print(const char *str)
{
    while (*str)
        print_char(*str++);
}

// ---------------- CLEAR ----------------

void clear_screen()
{
    unsigned short *vga = (unsigned short *)0xB8000;

    for (int i = 0; i < 80 * 25; i++)
        vga[i] = (0x07 << 8) | ' ';

    cursor_pos = 0;
    move_cursor(cursor_pos);
}

// ---------------- BACKSPACE ----------------

void backspace()
{
    unsigned short *vga = (unsigned short *)0xB8000;

    if (cursor_pos > 0)
    {
        cursor_pos--;
        vga[cursor_pos] = (0x07 << 8) | ' ';
        move_cursor(cursor_pos);
    }
}