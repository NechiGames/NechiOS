#include "include/lib/print.h"
#include "include/lib/string.h"

void execute_command(char *cmd)
{
    if (strcmp(cmd, "help") == 0)
    {
        print("\n====================\n");
        print(" HELP\n");
        print("====================\n");
        print("help  - commands\n");
        print("clear - clear screen\n");
        print("echo  - test\n");
    }
    else if (strcmp(cmd, "clear") == 0)
    {
        clear_screen();
        print("NechiOS\n");
    }
    else if (strcmp(cmd, "echo") == 0)
    {
        print("Hello from OS!\n");
    }
    else
    {
        print("Unknown command\n");
    }
}