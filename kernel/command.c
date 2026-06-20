#include "include/lib/print.h"
#include "include/lib/string.h"
#include "include/componentsOS/RESTART/restart.h"

void execute_command(char *cmd)
{
    if (strcmp(cmd, "help") == 0)
    {
        print("====================\n");
        print("        HELP        \n");
        print("====================\n");
        print("help  - commands\n");
        print("clear - clear screen\n");
        print("echo  - like 'print'\n");
        print("whoami - who are you (beta test)\n");
        print("restart - resater system\n");
    }
    else if (strcmp(cmd, "clear") == 0)
    {
        clear_screen();
        print("NechiOS\n");
    }
    else if (strncmp(cmd, "echo ",5) == 0)
    {
        print(&cmd[5]);
        print("\n");
    }
    else if (strcasecmp(cmd, "whoami") == 0)
    {
        print("Nechi\n");
    }
    else if (strcmp(cmd, "restart") == 0)
    {
        reboot();
    }
    else
    {
        print("Unknown command\n");
    }
}