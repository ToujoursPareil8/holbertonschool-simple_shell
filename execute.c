#include "shell.h"

/**
 * execute_prog - Creates a child process to execute a command
 * @args: An array of strings representing the command and its arguments
 *
 * Return: void
 */
void execute_prog(char **args)
{
	pid_t pid;
	int status;
	char *actual_command;
	extern char **environ;

	if (args == NULL || args[0] == NULL)
		return;

	/* find_path uses your _getenv to locate the binary in PATH */
	actual_command = find_path(args[0]);

	if (actual_command == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
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
		/* Child process: execute the command */
		if (execve(actual_command, args, environ) == -1)
		{
			perror(args[0]);
			free(actual_command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process: wait for child and then free memory */
		waitpid(pid, &status, 0);
		free(actual_command);
	}
}