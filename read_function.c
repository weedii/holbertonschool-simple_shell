#include "main.h"

/***/

char *read_line(void)
{
    int buffsize = 1024;
    char *buffer = malloc(sizeof(char) * buffsize);
    size_t i = 0;

    getline(&buffer, &i, stdin);

    return (buffer);
}