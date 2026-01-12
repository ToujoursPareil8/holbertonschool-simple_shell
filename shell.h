#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* Function Prototypes */
void split_line(char *line, char **args);
void execute_prog(char **args, int cnt);
char *find_path(char *cmd);
char *_getenv(const char *name);
int check_builtins(char **args, char *line);

#endif