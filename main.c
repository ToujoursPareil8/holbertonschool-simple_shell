#include "shell.h"

int main(void) 
{
	char *line = NULL;
	size_t len = 0;
	char *args[64] = {NULL};
	ssize_t nread;

	while (1)
	{
		/* Print prompt if running in interactive mode */
		if (isatty(STDIN_FILENO))
			printf("$ > ");

		nread = getline(&line, &len, stdin);

		/* Check for end-of-file (CTRL+D) or error */
		if (nread == -1) 
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		/* Remove trailing newline character */
		if (nread > 0 && line[nread - 1] == '\n') 
			line[nread - 1] = '\0';

		split_line(line, args);
		if (args[0] == NULL)
			continue;

		/* On vérifie les built-ins (exit, env) */
		if (check_builtins(args, line))
			continue;
		/* Exécution des commandes externes */
		execute_prog(args);
	}
	free(line);
	return (0);
}