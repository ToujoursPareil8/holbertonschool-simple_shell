#include "shell.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: 0 on success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *args[64];
	ssize_t nread;
	int counter = 0;

	while (1)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			printf("$ ");

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(line);
			exit(0);
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		split_line(line, args);
		if (args[0] == NULL)
			continue;

		if (check_builtins(args, line))
			continue;

		execute_prog(args, counter);
	}
	free(line);
	return (0);
}