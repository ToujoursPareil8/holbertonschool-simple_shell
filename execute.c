#include "shell.h"

/**
 * execute_prog - Creates a child process to execute a command.
 * @args: An array of strings representing the command and its arguments.
 *
 * Description: This function forks a new process. The child process
 * attempts to execute the command, while the parent waits for its
 * completion.
 */

void execute_prog(char **args) {
    pid_t pid;
    int status;

    if (args == NULL || args[0] == NULL)
        return;

    pid = fork();
    if (pid == 0) 
    {
        /* Child process */
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } 
    else if (pid < 0) 
    {
        /* Forking error */
        perror("shell");
    } 
    else 
    {
        /* Parent process */
        waitpid(pid, &status, 0);
    }
}