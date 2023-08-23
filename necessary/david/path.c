#include <stdio.h>
#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

/**
  *_print_path_error - function to print path error null or command path
  *@shell_name: shell name from av[0]
  *@wrong_cmd: cmd that is not correct
  *@command_count: count of cmmand
  *
  *Return: integer 0
  */

int _print_path_error(char *shell_name, char *wrong_cmd, int command_count)
{
	char *str;

	str = int_to_string(command_count);

	write(STDERR_FILENO, shell_name, (_strlen(shell_name) + 1));
	write(STDERR_FILENO, ": ", 3);
	if (str != NULL)
	{
		write(STDERR_FILENO, str, (_strlen(str) + 1));
		write(STDERR_FILENO, ": ", 3);
	}
	/*perror(NULL);*/
	write(STDERR_FILENO, wrong_cmd, (_strlen(wrong_cmd) + 1));
	write(STDERR_FILENO, ": ", 3);
	write(STDERR_FILENO, "not found\n", 11);

	free(str);
	return (0);
}

/**
  *_path - function to return null or command path
  *@argv: vector of arguments
  *@line: address of the line
  *@shell_name: name of the shell from av[0]
  *@cmd_count: count of command
  *@status: address of status.
  *
  *Return: character pointer
  */

char *_path(char **argv, char **line, char *shell_name,
		int cmd_count, int *status)
{
	char *full_path_name;

	if (argv == NULL)
	{
		if (*line)
		{
			free(*line);
			*line = NULL;
		}
		return (NULL);
	}
	full_path_name = get_cmd_path(argv[0]); /*SHOULD BE FREED*/
	if (full_path_name == NULL)
	{
		*status = 127;
		_print_path_error(shell_name, argv[0], cmd_count);
		free_all(*line, argv, full_path_name);
		return (NULL);
	}

	return (full_path_name);
}
