#include <unistd.h>
#include <stdio.h>

/**
  *print_prompt - prints prompt if it is a terminal
  *@fd: STDIN_FILENO
  *
  *Return: 0
  */

int print_prompt(int fd)
{
	if (isatty(fd))
	{
		write(STDOUT_FILENO, "$ ", 3);
		fflush(stdout);
	}
	return (0);
}
