#include "include/lib/print.h"
#include "include/keyboard/keyboard.h"
#include "include/lib/string.h"

void terminal_init()
{
    clear_screen();

    print("NechiOS Terminal\n");
}