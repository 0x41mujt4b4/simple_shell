#include "main.h"

/**
 * execute_args - map if command is a builtin or a process
 * @args: command and its flags
 *
 * Return: 1 on sucess, 0 otherwise
 */
int execute_args(char **args)
{
	if (args[0] == NULL)
	{
		/* empty command was entered */
		return (-1);
	}
	/* find if the command is a builtin */
	else if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}

	/* create a new process */
	return (new_process(args));
}
