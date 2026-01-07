#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>

extern char **environ;
void split_line(char *line, char **args);
void execute_prog(char **args);
char *get_path(char *command);

#endif /* SHELL_H */