#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

/**
  *main - Function to build super simple shell
  *@ac: argument count
  *@av: argument vector
  *@env: environment variables
  *Return: returns 0, on success, and 1 otherwise
  */

int main(int ac, char **av, char **env)
{
	ssize_t n_read;
	char *line = NULL;
	size_t n;
	int len, status, command_count = 1;
	char **argv;
	pid_t child_pid;

	(void) ac;/*change*/
	write(STDERR_FILENO, "$ ", 3);

	while ((n_read = getline(&line, &n, stdin)) != -1)
	{
		len = strlen(line); /*removing new line char - make function*/
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		argv = string_to_tokens(line);
		if (argv == NULL)
		{
			write(STDERR_FILENO, "$ ", 3);
			command_count++;
			continue;
		}  /*Test for PATH enters with argv[0]*/
		child_pid = fork();
		if (child_pid == -1)
		{
			free_all(line, argv);
		}
		if (child_pid == 0)
		{
			execve(argv[0], argv, env);
			_printerror(STDERR_FILENO, av[0], command_count);
			free_all(line, argv);
			return (1);
		}
		else
		{
			wait(&status);
			free_all(line, argv);
		}
		write(STDERR_FILENO, "$ ", 3);
		line = NULL;
		command_count++;
	}
	free(line);
	return (0);
}
