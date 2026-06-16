#include "include/lib/print.h"
#include "include/lib/string.h"

void execute_command(char *cmd)
{
    if (strcmp(cmd, "help") == 0)
    {
        print("\n\n============================\n");
        print("      HELP INFORMATION      \n");
        print("============================\n");
        print("help  - show commans\n");
        print("clear - clear screen\n");
        print("echo  - test command\n");
    }
    else if (strcmp(cmd, "clear") == 0)
    {
        clear_screen();
        print("NechiOS\n");
    }
    else if (strcmp(cmd, "echo") == 0)
    {
        print("Test command: HELLO BRO!\n");
    }
    else
    {
        print("Unknown command\n");
    }
}