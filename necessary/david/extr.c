#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * exit_shell - exits the shell
 * Return: nothing
 */
void exit_shell(char **argv)
{
	unsigned int i;
	char *exit_no;

	exit_no = argv[1];
	if (exit_no != NULL)
	{
		errno = 0;
		for (i = 0; exit_no[i] != '\0'; i++)
		{
			errno *= 10;
			errno += exit_no[i] - '0';
		}
	}
	if (errno > 255)
		errno %= 256;
	exit(errno);

}
/**
 * print_env - prints the environment variables
 * Return: nothing
 */
void print_env(void)
{
	int i, len;

	if (environ == NULL)
		return;
	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		if (len != 0)
		{
			write(STDOUT_FILENO, environ[i], len);
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	errno = 0;
}
/**
 * extra - handles extra shell commands like "exit" and "env"
 * @argv: array of arguments passed to the shell
 * @line: pointer to the input line
 * Return: 1 if the shell should execute the command, 0 otherwise
 */
int extra(char ***argv, char **line, int *status)
{
	int stat_no;

	if (*argv == NULL)
	{
		if (*line)
			free(*line);
		return (0);
	}
	if (_strcmp((*argv)[0], "exit") == 0)
	{
		free(*line);
		free_string_array(*argv);
		stat_no = *status % 255;
		/*We can't exit shell without freeing*/
		exit(stat_no);
	}
	if (_strcmp((*argv)[0], "env") == 0)
	{
		print_env();
		free(*line);
		free_string_array(*argv);
		*line = NULL;
		*argv = NULL;
		/*command_count++*/
		return (0);
	}
	return (1);
}
