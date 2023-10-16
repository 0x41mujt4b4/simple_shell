#include "main.h"

/**
 * main - function that checks if our shell is called
 *
 * Return: 0 on success
 */
int main(void)
{
	/* check interactive or none interactive mode */
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
			/* avoid memory leaks */
			free(line);
			free(args);
			/* exit with status */
			if (status >= 0)
			{
				exit(status);
			}
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
			/* avoid memory leaks */
			free(line);
			free(args);
			/* exit with status */
			if (status >= 0)
			{
				exit(status);
			}
		} while (status == -1);
	}
	return (0);
}
