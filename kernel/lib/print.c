#include "include/lib/print.h"

int cursor_pos = 0;

int cursor_visible = 1;
int blink_counter = 0;

// Белый цвет
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

// Очистка экрана
void clear_screen()
{
    unsigned short *VGA = (unsigned short*)0xB8000;

    for (int i = 0; i < 80 * 25; i++)
        VGA[i] = (0x07 << 8) | ' ';

    cursor_pos = 0;
}

// Backspace
void backspace()
{
    unsigned short *VGA = (unsigned short*)0xB8000;

    if (cursor_pos > 0)
    {
        cursor_pos--;
        VGA[cursor_pos] = (0x07 << 8) | ' ';
    }
}

// Blinking Cursor
void update_cursor_blink()
{
    unsigned short *vga = (unsigned short *)0xB8000;

    blink_counter++;

    if (blink_counter > 50000)
    {
        blink_counter = 0;
        cursor_visible = !cursor_visible;

        int pos = cursor_pos;

        if (cursor_visible)
            vga[pos] = (0x07 << 8) | '_';
        else
            vga[pos] = (0x07 << 8) | ' ';
    }
}