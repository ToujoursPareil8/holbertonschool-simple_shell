#include "shell.h"

/**
 * execute_prog - Creates a child process to execute a command
 * @args: Array of strings representing the command and arguments
 * @cnt: The loop counter for error reporting
 *
 * Return: void
 */
void execute_prog(char **args, int cnt)
{
	pid_t pid;
	int status;
	char *actual_command;
	extern char **environ;

	actual_command = find_path(args[0]);
	if (!actual_command)
	{
		fprintf(stderr, "./hsh: %d: %s: not found\n", cnt, args[0]);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(actual_command);
		return;
	}

	if (pid == 0)
	{
		if (execve(actual_command, args, environ) == -1)
		{
			perror("execve");
			free(actual_command);
			exit(2);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free(actual_command);
	}
}
