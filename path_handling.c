#include "shell.h"

/**
 * get_path - Finds the full path of a command.
 * @command: The command to find.
 * 
 * Return: Full path of the command if found, NULL otherwise.
 */

 char *get_path(char *command)
 {
    char *path = getenv("PATH");
    char *path_copy, * token ,*full_path;
    struct stat st;

    if (path == NULL)
    {
        return NULL;
    }

    /*Duplica path because strtok modifies str*/
    path_copy = strdup(path);
    token = strtok(path_copy, ":");

    while (token != NULL)
    {
        /* malloc : length of dir + '/' + command  + '\0' */
        full_path = malloc(strlen(token) + strlen(command) +2);
        if (full_path == NULL)
            break;

        /* Construct full path */
        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, command);

        /*Check if file exists and executable*/
        if (stat(full_path, &st) == 0)
        {
            free(path_copy);
            return full_path;
        }
        free(full_path);
        token = strtok(NULL, ":");
    }
    free(path_copy);
    return NULL;
}