#include "shell.h"


char *line = NULL;
size_t len = 0;
char *args[64];

int main() {
    while (1)
    {
        printf("$ > ");
        if (getline(&line, &len, stdin) == -1) {
            perror("getline");
            break;
        }
        split_line(line, args);
        execute_prog(args);
    }
}