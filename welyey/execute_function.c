#include "shell.h"

char *builtin_str[] = {"exit"};
int (*builtin_func[])(char **) = {&exit_function};

/***/

int lsh_launch(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        /*Child process*/
        if (execvp(args[0], args) == -1)
        {
            perror("lsh");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        /*Error forking*/
        perror("lsh");
    }
    else
    {
        /*Parent process*/
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return (1);
}

/***/

int exit_function()
{
    return (0);
}

/***/

int execute_function(char **args)
{
    int i, size;

    size = sizeof(builtin_str) / sizeof(char *);
    if (args[0] == NULL)
    {
        /*An empty command was entered*/
        return (1);
    }

    for (i = 0; i < size; i++)
    {
        if (strcmp(args[0], builtin_str[i]) == 0)
        {
            return (*builtin_func[i])(args);
        }
    }

    return (lsh_launch(args));
}