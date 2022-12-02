#include "shell.h"

/**
 * split_line - function that Split a line into tokens
 * @line:  line to be parsed
 * Return: Null-terminated array of tokens
 */

char **split_line(char *line)
{
	int bufsize = LSH_TOK_BUFSIZE, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token, **tokens_backup;

	if (!tokens)
	{
		write(STDERR_FILENO, "lsh: allocation error\n", 23);
		free(tokens);
		exit(EXIT_FAILURE);
	}

	token = strtok(line, LSH_TOK_DELIM);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += LSH_TOK_BUFSIZE;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				free(tokens);
				free(tokens_backup);
				write(STDERR_FILENO, "lsh: allocation error\n", 23);
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * read_line - function that Read a line of input from stdin
 * Return: The line from stdin
 */

char *read_line(void)
{

	char *line = NULL;
	size_t bufsize = 0;
	int x;

	x = getline(&line, &bufsize, stdin);
	if (x == -1)
	{
		if (x == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS); /*We received an EOF*/
		}
		else
		{
			perror("lsh: getline\n");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}
