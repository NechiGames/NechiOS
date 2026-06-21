#include "include/lib/print.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

int cursor_pos = 0;
int cursor_visible = 1;
int blink_counter = 0;

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

// ---------------- SCROLL ----------------

void scroll()
{
    unsigned short *vga = (unsigned short *)0xB8000;

    for (int y = 1; y < VGA_HEIGHT; y++)
    {
        for (int x = 0; x < VGA_WIDTH; x++)
        {
            vga[(y - 1) * VGA_WIDTH + x] =
                vga[y * VGA_WIDTH + x];
        }
    }

    for (int x = 0; x < VGA_WIDTH; x++)
    {
        vga[(VGA_HEIGHT - 1) * VGA_WIDTH + x] =
            (0x07 << 8) | ' ';
    }
}

// ---------------- PRINT ----------------

void print_char(char c)
{
    unsigned short *vga = (unsigned short *)0xB8000;

    if (c == '\n')
    {
        cursor_pos = (cursor_pos / VGA_WIDTH + 1) * VGA_WIDTH;

        if (cursor_pos >= VGA_WIDTH * VGA_HEIGHT)
        {
            scroll();
            cursor_pos = (VGA_HEIGHT - 1) * VGA_WIDTH;
        }

        move_cursor(cursor_pos);
        return;
    }

    vga[cursor_pos] = (0x07 << 8) | c;
    cursor_pos++;

    if (cursor_pos >= VGA_WIDTH * VGA_HEIGHT)
    {
        scroll();
        cursor_pos = (VGA_HEIGHT - 1) * VGA_WIDTH;
    }

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

    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++)
    {
        vga[i] = (0x07 << 8) | ' ';
    }

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

// ---------------- PRINT INT ----------------

void print_int(int num)
{
    char buffer[12];
    int i = 0;

    if (num == 0)
    {
        print("0");
        return;
    }

    while (num > 0)
    {
        buffer[i++] = '0' + (num % 10);
        num /= 10;
    }

    while (i > 0)
    {
        print_char(buffer[--i]);
    }
}