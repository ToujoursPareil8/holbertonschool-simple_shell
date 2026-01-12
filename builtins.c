#include "shell.h"

/**
 * check_builtins - Checks if a command is a built-in and executes it.
 * @args: Array of arguments (the command and its parameters).
 * @line: The input line buffer (to free it if exiting).
 *
 * Return: 1 if a built-in was executed, 0 otherwise.
 */
int check_builtins(char **args, char *line)
{
	int i = 0;
	int status = 0;

	if (args == NULL || args[0] == NULL)
		return (0);

	/* Built-in: exit */
	if (strcmp(args[0], "exit") == 0)
	{
		/* If there is a second argument (e.g., exit 98) */
		if (args[1] != NULL)
		{
			status = atoi(args[1]);
		}
		free(line);
		exit(status);
	}

	/* Built-in: env */
	if (strcmp(args[0], "env") == 0)
	{
		while (environ[i])
		{
			printf("%s\n", environ[i]);
			i++;
		}
		return (1); /* Built-in executed */
	}

	return (0); /* No built-in found */
}
