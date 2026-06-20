#include "include/lib/print.h"
#include "include/keyboard/keyboard.h"
#include "include/lib/string.h"

void execute_command(char *cmd);

void terminal_init()
{
    clear_screen();

    print("NechiOS Terminal\n\n");

    char *cmd = "help";

    execute_command(cmd);
}