#include "shell.h"


pid_t pid;


void execute_prog(char **args) {
    if (args[0] == NULL)
    return;
    pid =fork();

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Forking error
        perror("shell");
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}