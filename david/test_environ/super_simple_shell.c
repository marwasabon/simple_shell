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

int main(__attribute__((unused)) int ac, char **av, char **env)
{
	ssize_t n_read;
	char *line = NULL;
	size_t n;
	int status;
	char **argv;
	pid_t child_pid;

	/*printf("#cisfun ");*/
	while ((n_read = _getline(&line, &n)) != -1)
	{
		argv = string_to_tokens(line);
		if (argv == NULL)
		{
			/*printf("#cisfun ");*/
			continue;
		}  /*Test for PATH enters with argv[0]*/
		child_pid = fork();
		if (child_pid == -1)
		{
			free(line);
			free_string_array(argv);
		}
		if (child_pid == 0)
		{
			execve(argv[0], argv, env);
			dprintf(STDERR_FILENO, "%s: ", av[0]); /*Rewrite function*/
			perror(NULL);
			free(line); /*free_line_string_array(line, argv)*/
			free_string_array(argv);
			return (1);
		}
		else
		{
			wait(&status);
			free(line);
			free_string_array(argv);
		}
		/*printf("#cisfun ");*/
		line = NULL;
	}
	free(line);
	return (0);
}
