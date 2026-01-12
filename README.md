# holbertonschool-simple_shell

Description
This is a collaborative project for Holberton School that consists of writing a simple UNIX command line interpreter. This shell implements the basic core functionality of the standard shell.

Features

Interactive and Non-Interactive modes: The shell works both when taking commands from the terminal and when receiving piped input.

Command Execution: Finds and executes system commands located in the PATH.
Built-in Commands:

    exit: Terminates the shell process.

    env: Prints the current environment variables.

    Path Handling: Custom implementation to find executables without using execvp or execlp.

    Custom _getenv: Retrieves environment variables manually by parsing the environ global variable.

    Error Handling: Displays error messages in the exact format: ./hsh: [count]: [command]: not found.

File Structure
File	Description
shell.h	The header file containing all function prototypes and library includes.
main.c	The entry point of the shell, containing the main loop and signal handling.
split_line.c	Tokenizes the input string into an array of arguments using strtok.
execute_prog.c	Handles the fork, execve, and waitpid logic to run programs.
find_path.c	Logic to locate a command in the PATH directories.
_getenv.c	Custom function to find environment variables.
check_builtins.c	Checks if the user input matches an internal command like exit or env.

Technical Specifications
Betty Compliance

All files have been written following the Betty Style Guide (indentation with tabs, specific header comments, variable declarations at the start of blocks).
Process Management

The shell follows the standard UNIX process lifecycle:

    Parent process waits for user input.

    Parent forks to create a Child process.

    Child process calls execve() to replace its image with the command.

    Parent waits for the child to finish before prompting again.

Memory Management

The shell is designed to be leak-free. All dynamically allocated memory (from getline and malloc inside find_path) is freed before the program exits or loops.

Compile Commands

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Usage
Interactive Mode
Bash

$ ./hsh
$ ls -l
$ /bin/ls
$ exit

Non-Interactive Mode
Bash

$ echo "ls -l" | ./hsh
$ echo "env" | ./hsh

Man Page

.TH HSH 1 "JANUARY 2026" "ALX/Holberton" "Simple Shell Manual"
.SH NAME
hsh \- a simple UNIX command line interpreter
.SH SYNOPSIS
.B ./hsh
[batch_file]
.SH DESCRIPTION
.B hsh
is a command language interpreter that executes commands read from the standard input or from a file. It is a simplified version of the Bourne Shell (sh).
.PP
The shell can be used in both interactive and non-interactive modes:
.IP \(bu 2
In
.B interactive mode
, hsh displays a prompt ($ ) and waits for the user to type a command.
.IP \(bu 2
In
.B non-interactive mode
, hsh reads commands from a pipe or redirected file and executes them sequentially.

.SH FEATURES
.SS Command Execution
The shell searches for commands in the following order:
.IP 1. 4
If the command name contains a slash (/), the shell attempts to execute the file directly.
.IP 2. 4
If the command does not contain a slash, the shell searches each directory listed in the
.B PATH
environment variable for the executable.

.SS Environment
.B hsh
uses its own internal
.B _getenv
function to access environment variables like PATH, ensuring it operates independently of standard library environment functions.

.SH BUILT-IN COMMANDS
The following commands are built into the shell:
.TP
.B env
Prints the current environment variables to the standard output.
.TP
.B exit
Exits the shell.

.SH ERROR HANDLING
When a command is not found,
.B hsh
prints an error message to
.I stderr
in the following format:
.IP
\fB./hsh: [line_counter]: [command]: not found\fR

.SH EXIT STATUS
Returns 0 on success. If a command is not found, it returns the status of the last command executed or specific error codes (e.g., 127 for command not found).

.SH EXAMPLES
To start the shell in interactive mode:
.IP
.B ./hsh
.PP
To execute a command via pipe:
.IP
.B echo "ls -l" | ./hsh

.SH AUTHOR
Written by your name and Gemini AI for the ALX/Holberton Simple Shell project.

.SH BUGS
Does not currently support advanced shell features like pipes (|), redirections (>, <), or logical operators (&&, ||).

.SH SEE ALSO
sh(1), bash(1), execve(2), fork(2), wait(2)

Testing
<img width="1222" height="193" alt="test_simplehell" src="https://github.com/user-attachments/assets/77824b22-db22-4cd0-bd34-13eb106847a7" />
Flowchart
<img width="4670" height="8192" alt="Untitled diagram-2026-01-09-193902" src="https://github.com/user-attachments/assets/b0f92019-47aa-46b5-8de3-508a078be7bc" />

Authors
Jason JEAN-LOUIS <12315@holbertonstudents.com>
Farid GHAIB <12190@holbertonstudents.com>
