#include "shell.h"

/**
 * _getenv - Trouve une variable d'environnement sans utiliser la fonction lib
 * @name: Nom de la variable à chercher
 * Return: Pointeur vers le début de la valeur, ou NULL
 */
char *_getenv(const char *name)
{
	char **env;
	size_t name_len = strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		/* On compare le nom ET on vérifie que le caractère suivant est '=' */
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (*env + name_len + 1);
		}
	}
	return (NULL);
}

/**
 * find_path - Localise l'exécutable d'une commande dans le PATH
 * @cmd: Nom de la commande (ex: "ls")
 * Return: Chemin complet alloué dynamiquement, ou NULL
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
