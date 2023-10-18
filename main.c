#include "main.h"

/**
 * main - The main function
 *
 * Return: 0 on success
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		char *line;
		char **args;
		int status = -1;

		do {
			printf("($) "); /* print prompt symbol */
			line = read_line(); /* read line from stdin */
			args = split_line(line); /* tokenize line */
			status = execute_args(args);
			free(line);
			free(args);
			if (status >= 0)
				exit(status);
		} while (status == -1);
	}
	else
	{
		char *line;
		char **args;
		int status = -1;

		do {
			line = read_stream();
			args = split_line(line); /* tokenize line */
			status = execute_args(args);
			free(line);
			free(args);
			if (status >= 0)
				exit(status);
		} while (status == -1);
	}
	return (0);
}
