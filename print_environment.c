#include "shell.h"

/**
 * print_environment - function that print environment
 */

void print_environment(void)
{
	char **s = environ;

	for (; *s; s++)
	{
		printf("%s\n", *s);
	}
}
