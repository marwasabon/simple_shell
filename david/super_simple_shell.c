#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include <sys/wait.h>
#include <sys/types.h>

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
	char *line = NULL;
	size_t n;
	int status, command_count = 1;
	char **argv;
	pid_t child_pid;

	write(STDOUT_FILENO, "$ ", 3);
	while ((n_read = _getline(&line, &n)) != -1)
	{
		argv = string_to_tokens(line);
		child_pid = fork();
		if (child_pid == -1)
			free_all(line, argv);
		if (child_pid == 0)
		{
			_exec(argv, env);
			_printerror(STDERR_FILENO, av[0], command_count);
			free_all(line, argv);
			return (1);
		}
		else
		{
			wait(&status);
			free_all(line, argv);
		}
		write(STDOUT_FILENO, "$ ", 3);
		line = NULL;
		command_count++;
	}
	free(line);
	return (0);
}
