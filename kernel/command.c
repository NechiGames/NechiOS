#include "include/lib/print.h"
#include "include/lib/string.h"

#include "include/componentsOS/RESTART/restart.h"
#include "include/componentsOS/SHUTDOWN/shutdown.h"

char username[32] = "Nechi";

void execute_command(char *cmd)
{
    if (strcmp(cmd, "help") == 0)
    {
        print("+---------------------------------------------+\n");
        print("|               NechiOS Help                  |\n");
        print("+---------------------------------------------+\n");
        print("| help               - show commands          |\n");
        print("| clear              - clear screen           |\n");
        print("| echo               - print text             |\n");
        print("| whoami             - who are you            |\n");
        print("| restart            - restart system         |\n");
        print("| shutdown           - power off PC           |\n");
        print("| -v                 - show OS version        |\n");
        print("| calc 'a' 'op' 'b'  - mini calculator        |\n");
        print("| login 'name'       - your name              |\n");
        print("| login return       - return to default name |\n");
        print("+---------------------------------------------+\n");
    }

    else if (strcmp(cmd, "clear") == 0)
    {
        clear_screen();
    }

    else if (strncmp(cmd, "echo ",5) == 0)
    {
        print(&cmd[5]);
        print("\n");
    }

    else if (strcasecmp(cmd, "whoami") == 0)
    {
        print(username);
        print("\n");
    }

    else if (strcmp(cmd, "restart") == 0)
    {
        reboot();
    }

    else if (strcmp(cmd, "shutdown") == 0)
    {
        shutdown();
    }

    else if (strcmp(cmd, "-v") == 0)
    {
        print("NechiOS --- 0.1v\n");
    }

    else if (strncmp(cmd, "calc ", 5) == 0)
    {
        char *p = cmd + 5;

        int a = atoi(p);

        while (*p && *p != ' ')
            p++;
        p++;

        char op = *p;
        p += 2;

        int b = atoi(p);

        int result;

        switch (op)
        {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0)
            {
                print("Division by zero\n");
                return;
            }
            result = a / b;
            break;
        default:
            print("Unknown operator\n");
            return;
        }

        print_int(result);
        print("\n");
    }

    else if (strncmp(cmd, "login ", 6) == 0)
    {
        strcpy(username, &cmd[6]);

        if (strcmp(&cmd[6], "return") == 0)
        {
            strcpy(username, "Nechi");
            print("Returned to default user name\n");
        }
        else
        {
            print("Logged in as ");
            print(username);
            print("\n");
        }
    }

    else
    {
        print("Unknown command\n");
    }
}