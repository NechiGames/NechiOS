#include "include/lib/io.h"
#include "include/componentsOS/SHUTDOWN/shutdown.h"

void shutdown()
{
    outw(0x604, 0x2000);

    while (1)
    {
        __asm__ volatile("hlt");
    }
}