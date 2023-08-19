#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
  *_exec - Function to serve as a wrapper for execve function
  *@argv: array of strings if there are strings
  *@env: array of environment variables passed into execve
  *@lineptr: The address of the lineptr
  *@cmd_name: command full name
  *Return: Exits
  */

int _exec(char **lineptr, char **argv, char **env, char *cmd_name)
{
	int ret;

	if (argv == NULL)
	{
		if (*lineptr)
		{
			free(*lineptr);
			*lineptr = NULL;
		}
		exit(EXIT_SUCCESS);
	}

	else
	{
		ret = execve(cmd_name, argv, env);
	}
	return (ret);
}
