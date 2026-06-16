#include "include/lib/print.h"

int cursor_pos = 0;

void print_char(char c)
{
    unsigned short *vga = (unsigned short *)0xB8000;

    if (c == '\n')
    {
        cursor_pos = (cursor_pos / 80 + 1) * 80;
        return;
    }

    vga[cursor_pos] = (0x07 << 8) | c;
    cursor_pos++;
}

void print(const char *str)
{
    while (*str)
    {
        print_char(*str);
        str++;
    }
}

void clear_screen()
{
    unsigned short *VGA = (unsigned short*)0xB8000;

    for (int i = 0; i < 80 * 25; i++)
        VGA[i] = (0x07 << 8) | ' ';

    cursor_pos = 0;
}

void backspace()
{
    unsigned short *VGA = (unsigned short*)0xB8000;

    if (cursor_pos > 0)
    {
        cursor_pos--;
        VGA[cursor_pos] = (0x07 << 8) | ' ';
    }
}