#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

/**
 *main - Function to build super simple shell
 *@ac: argument count
 *@av: argument vector
 *@env: environment variables
 *Return: returns 0, on success, and 1 otherwise
 */

int main(__attribute__((unused)) int ac, char **av, char **env)
{
	ssize_t n_read;
	char *line = NULL, *full_name;
	size_t n;
	int status = 0, command_count = 1;
	char **argv;
	pid_t child_pid;

	print_prompt(STDIN_FILENO);
	while ((n_read = _getline(&line, &n)) != -1)
	{
		argv = string_to_tokens(line);
		if (extra(argv, &line, &status) == 0)
		{
			print_prompt(STDIN_FILENO);
			continue;
		}
		full_name = _path(argv, &line, av[0], command_count);
		if (full_name != NULL)
		{
			child_pid = fork();
			if (child_pid == -1)
				free_all(line, argv, full_name);
			if (child_pid == 0)
			{
				_exec(&line, argv, env, full_name);
				_printerror(STDERR_FILENO, av[0], command_count, full_name);
				free_all(line, argv, full_name);
				return (0);
			}
			else
			{
				wait(&status);
				free_all(line, argv, full_name);
			}
		}
		print_prompt(STDIN_FILENO);
		line = NULL;
		command_count++;
	}
	free(line);
	return (0);
}
