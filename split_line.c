#include "main.h"

/***/

char **split_line(char *line)
{
    int buffsize = 1024, position = 0;
    char **tokens = malloc(buffsize * sizeof(char *));
    char *token;

    token = strtok(line, TOK_DELIM);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;
        token = strtok(NULL, TOK_DELIM);
    }
    tokens[position] = NULL;

    return (tokens);
}