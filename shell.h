#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

void loop_function(void);
char *read_line(void);
char **split_line(char *line);
int execute_function(char **args);
int exit_function(void);
int lsh_launch(char **args);

#endif
