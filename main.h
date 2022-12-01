#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define TOK_DELIM " \t\r\n"

void loop(void);
char *read_line(void);
char **split_line(char *);
int dash_execute(char **args);

#endif