#include "shell.h"

/**
 * _getenv - Finds an environment variable  without using the lib function
 * @name: Name of the variable to find
 * Return: Pointer to the start of the value or NULL
 */
char *_getenv(const char *name)
{
	char **env;
	size_t name_len = strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (*env + name_len + 1);
		}
	}
	return (NULL);
}

/**
 * find_path - Localize the exe of a command in the PATH
 * @cmd: Name of a command (ex: "ls")
 * Return: Full path allocated dynamically or NULL
 */
char *find_path(char *cmd)
{
	char *path = _getenv("PATH");
	char *path_copy, *dir, *full_path;
	struct stat st;
	size_t path_len;

	if (strchr(cmd, '/') && stat(cmd, &st) == 0)
		return (strdup(cmd));

	if (!path || !*path)
		return (NULL);

	path_copy = strdup(path);
	dir = strtok(path_copy, ":");

	while (dir)
	{
		path_len = strlen(dir) + strlen(cmd) + 2;
		full_path = malloc(path_len);
		if (!full_path)
			break;

		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, cmd);

		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
