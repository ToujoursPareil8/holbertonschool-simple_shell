#include "shell.h"




int main(void) 
{
    char *line = NULL;
    size_t len = 0;
    char *args[64] = {NULL};
    ssize_t nread;

    while (1)
    {   
        /* Print prompt if running in interactive mode */
        if (isatty(STDIN_FILENO))
            printf("$ > ");
        
        nread = getline(&line, &len, stdin);

        /* Check for end-of-file (CTRL+D) or error */
        if (nread == -1) {
            free(line);
            exit(EXIT_SUCCESS);
        }

        /* Remove trailing newline character */
        if(line[nread - 1] == '\n') {
            line[nread - 1] = '\0';
        }
        
        split_line(line, args);
        if (check_builtins(args, line))
            continue;
        if (args[0] != NULL)
            execute_prog(args);
        
    }

    return (0);
}