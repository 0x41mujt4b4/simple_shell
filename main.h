#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/* Macros */
#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

/* PROTOTYPES */
void shell_interactive(void);
void shell_no_interactive(void);
char *read_line(void);
char **split_line(char *line);
int execute_args(char **args);
int new_process(char **args);
char *read_stream(void);

#endif
