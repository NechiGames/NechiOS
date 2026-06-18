#include "include/keyboard/keyboard.h"

static char keymap[128] =
    {
        0,
        27, // ESC
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9',
        '0',
        '-',
        '=',
        '\b', // Backspace
        '\t', // Tab
        'q',
        'w',
        'e',
        'r',
        't',
        'y',
        'u',
        'i',
        'o',
        'p',
        '[',
        ']',
        '\n', // Enter
        0,    // Ctrl
        'a',
        's',
        'd',
        'f',
        'g',
        'h',
        'j',
        'k',
        'l',
        ';',
        '\'',
        '`',
        0, // Shift
        '\\',
        'z',
        'x',
        'c',
        'v',
        'b',
        'n',
        'm',
        ',',
        '.',
        '/',
        0, // Shift
        '*',
        0,   // Alt
        ' ', // Space
};

// inb
static inline unsigned char inb(unsigned short port)
{
    unsigned char ret;
    __asm__ volatile ("inb %1, %0"
                      : "=a"(ret)         
                      : "Nd"(port));

    return ret;
}

// Чтение scancode
unsigned char keyboard_get_key(void)
{
    unsigned char status;
    unsigned char keycode;

    while (1)
    {
        status = inb(0x64);

        if (status & 1)
        {
            keycode = inb(0x60);
            return keycode;
        }
    }
}

// Перевод в char
char keyboard_get_char(void)
{
    unsigned char scancode;

    while (1)
    {
        scancode = keyboard_get_key();     
        
        // Только key press
        if (!(scancode & 0x80))
        {
            char c = keymap[scancode];

            if (c)
                return c;
        }
    }
} 