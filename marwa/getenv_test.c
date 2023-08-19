#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


/**
  *print_path_dir - Function to print path dirs.
  *
  *Return: 0, if successful, and -1 otherwise
  */

int print_path_dir(void)
{
	char *value = _getenv("PATH");
	char *token;
	
	if (value == NULL)
		return (-1);
	printf("%s\n", value);
	token = strtok(value, ":");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
	free(value);
	return (0);
}

/**
  *main - function to print the env variable obrained.
  *
  *Return: 0 if successful
  */

int main(void)
{
	int r;
	char *env_variable;
	char *env_variable2;

	env_variable = _getenv("DBUS_SESSION_BUS_ADDRESS");
	if (env_variable != NULL)
	{
		printf("%s\n", env_variable);
		free(env_variable);
	}

	env_variable2 = _getenv("PATH");
	if (env_variable2 != NULL)
	{
		printf("%s\n", env_variable2);
		free(env_variable2);
	}

	r = print_path_dir();
	if (r == -1)
		printf("-1\n");
	return (0);
}
