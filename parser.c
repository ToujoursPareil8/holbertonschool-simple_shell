#include "shell.h"

void split_line(char *line, char **args) {
    char *token;
    int position = 0;

    token = strtok(line, " \n");
    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " \n");
    }
    args[position] = NULL;
}