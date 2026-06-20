#include "include/componentsOS/RESTART/restart.h"
#include "include/lib/io.h"

void reboot()
{
    __asm__ volatile("cli");

    while (inb(0x64) & 0x02)
    {

    }

    outb(0x64, 0xFE);

    for (;;)
    {
        __asm__ volatile("hlt");
    }
}