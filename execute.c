#include "shell.h"

/**
 * exec_command - function that executes a command
 * @cmd: the command to be executed
 */

void exec_command(char **cmd)
{
	pid_t pid = 0;
	int i = 0;

	pid = fork();
	if (pid == -1)
		printf("Error in Fork\n");
	else if (pid > 0)
		/* Block parent process until the child process terminate */
		waitpid(pid, &i, 0);

	else if (pid == 0)
	{
		/* Child process execute the command or exit if execve fail */
		if (execve(cmd[0], cmd, NULL) == -1)
			perror("shell");
		exit(EXIT_FAILURE);
	}
}
