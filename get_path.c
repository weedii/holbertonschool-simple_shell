#include "shell.h"
/**
 * get_path - function that gets the path
 * @cmd: command
 */
void get_path(char **cmd)
{
	int i;
	char *path = strdup(getenv("PATH")), *bin = NULL, **path_split = NULL;

	if (path == NULL) /*if the path NULL we will create one*/
		path = strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
	/* if cmd isn't the path we will find it in the binary with env path*/
	if (cmd[0][0] != '/' && strncmp(cmd[0], "./", 2) != 0)
	{
		path_split = str_split(path, ":"); /*split path to verify if exist*/
		free(path);
		path = NULL;
		for (i = 0; path_split[i]; i++)
		{
			/* alloc len path + '//' + len  binaire + 1 for the '\0' */
			bin = calloc(sizeof(char),
						 (strlen(path_split[i]) + 1 + strlen(cmd[0]) + 1));
			if (bin == NULL)
				break;
			strcat(bin, path_split[i]); /* concatenate the path , the '//' and cmd */
			strcat(bin, "/");
			strcat(bin, cmd[0]);
			/* verify if the file exist and exit the loop if  access => 0 */
			if (access(bin, F_OK) == 0)
				break;
			/* free it */
			free(bin);
			bin = NULL;
		}
		free_array(path_split);
		/* replace cmd with path or NULL if cmd not found */
		free(cmd[0]);
		cmd[0] = bin;
	}
	else
	{
		free(path);
		path = NULL;
	}
}
