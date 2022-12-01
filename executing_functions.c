#include "main.h"

/***/

int dash_execute(char **args)
{
    char *envp[] = {(char *)"PATH=/bin", 0}, cmd[100];

    if (fork() != 0)
        wait(NULL);
    else
    {
        strcpy(cmd, "/bin/");
        strcat(cmd, *args);
        execv(cmd, envp);
    }

    return (1);
}