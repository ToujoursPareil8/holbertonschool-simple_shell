#include "shell.h"


/**
 * split_line - Splits a string into tokens based on delimiters.
 * @line: The string to be tokenized.
 * @args: An array of strings where tokens will be stored.
 *
 * Description: This function takes a string and breaks it down into
 * individual words (tokens) using strtok. It handles spaces, tabs,
 * and newlines as delimiters.
 */
void split_line(char *line, char **args) {
	char *token;
	int position = 0;

	/* Get the first word while ignoring whitespace */
	token = strtok(line, " \t\r\n\a");

	while (token != NULL && position < 63) 
	{
		args[position++] = token;
		/* Move to next token */
		token = strtok(NULL, " \t\r\n\a");
	}

	/*Last element must always be NULL for execve */
	while (position < 64)
	{
		args[position++] = NULL;
	}
}