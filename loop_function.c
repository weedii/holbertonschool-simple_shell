#include "main.h"

/***/

void loop(void)
{
    char *line, **args = malloc(sizeof(char) * 1024);

    do
    {
        printf("$ ");

        line = read_line();
        args = split_line(line);
        dash_execute(args);

        if (strcmp(args[0], "exit") == 0)
            exit(EXIT_SUCCESS);

        free(line);
        free(args);
    } while (1);
}