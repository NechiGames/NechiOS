#include "include/keyboard/keyboard_waiting.h"
#include "include/keyboard/keyboard.h"

// Ждем любую клавишу, типа: Press any key to continue...
char wait_any_key(void)
{
    return keyboard_get_char();
}