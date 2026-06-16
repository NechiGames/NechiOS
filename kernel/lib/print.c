#include "../../include/lib/print.h"

typedef unsigned char u8;
typedef unsigned short u16;

#define VGA_MEMORY 0xB8000

static u16* vga = (u16*)VGA_MEMORY;
static int x = 0;
static int y = 0;

void print_char(char c)
{
    if (c == '\n')
    {
        y++;
        x = 0;
        return;
    }

    vga[y * 80 + x] = (u16)c | (0x07 << 8);

    x++;

    if (x >= 80)
    {
        x = 0;
        y++;
    }
}

void print(const char* str)
{
    while (*str)
    {
        print_char(*str);
        str++;
    }
}