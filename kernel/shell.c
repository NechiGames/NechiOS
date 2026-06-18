#include "include/lib/print.h"
#include "include/keyboard/keyboard.h"
#include "include/lib/string.h"

void execute_command(char *cmd);

void shell_run()
{
    char command[256];

    while (1)
    {
        int pos = 0;

        print("> ");

        while (1)
        {
            char c = keyboard_get_char();

            if (c == '\n')
                break;

            if (c == '\b')
            {
                if (pos > 0)
                {
                    pos--;
                    backspace();
                }
                continue;
            }

            if (pos < 255 && c)
            {
                command[pos++] = c;
                print_char(c);
            }
        }

        if (pos == 0)
            continue;

        command[pos] = '\0';
        print_char('\n');

        execute_command(command);
    }
}