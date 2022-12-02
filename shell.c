#include "shell.h"

/**
 * main - main function
 * Return: status code
 */

int main(void)
{
	char *line;
	char **args;
	int status;

	do
	{
		printf("$ ");
		line = read_line();
		args = split_line(line);
		status = execute_function(args);

		free(line);
		free(args);
	} while (status);

	return (EXIT_SUCCESS);
}
