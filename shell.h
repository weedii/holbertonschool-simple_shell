#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

char **str_split(char *line, char *delim);
void free_array(char **array);
void loop(int input);
void get_path(char **cmd);
void exec_command(char **cmd);

#endif
