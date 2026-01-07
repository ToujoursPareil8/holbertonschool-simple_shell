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
    char *actual_command;
    extern char **environ;
    

    if (args == NULL || args[0] == NULL)
        return;
    /* Decide if using the command or search the PATH */
    if (args[0][0] == '/')
        actual_command = strdup(args[0]);
    else
        actual_command = get_path(args[0]);
    
    if (actual_command == NULL) 
    {
        perror("shell");
        return;
    }

    pid = fork();
    if (pid == 0) 
    {
        /* Child process */
        if (execve(actual_command, args, environ) == -1)
        {
            perror("shell");
        }
        free(actual_command);
        exit(EXIT_FAILURE);
    } 
    else if (pid < 0) 
    {
        waitpid(pid, &status, 0);
    } 
    free(actual_command);
}