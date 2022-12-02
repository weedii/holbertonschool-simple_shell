#include "shell.h"

/**
 * lsh_launch - function that lunch the other executable function
 * @args:  pointer to arguments
 * Return: 1
 */

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

/**
 * exit_function - function exit
 * Return: 0
 */

int exit_function(void)
{
	return (0);
}

/**
 * execute_function - function that execute function
 * @args:  pointer to arguments
 * Return: execute
 */

int execute_function(char **args)
{
	char *builtin_str[] = {"exit"};
	int i, size;

	int (*builtin_func[])(char **) = {&exit_function};

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
			return ((*builtin_func[i])(args));
		}
	}

	return (lsh_launch(args));
}
