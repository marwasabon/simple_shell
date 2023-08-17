#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
  *_exec - Function to serve as a wrapper for execve function
  *@argv: array of strings if there are strings
  *@env: array of environment variables passed into execve
  *
  *Return: Exits
  */

int _exec(char **argv, char **env)
{
	int ret;

	if (argv == NULL)
		exit(EXIT_SUCCESS);
	else
	{
		ret = execve(argv[0], argv, env);
	}
	return (ret);
}
