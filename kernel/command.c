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
    else if (strncmp(cmd, "echo ",5) == 0)
    {
        print(&cmd[5]);
        print("\n");
    }else if(strcasecmp(cmd,"who are you")==0){
        print("Nechi\n");
    }
    else
    {
        print("Unknown command\n");
    }
}