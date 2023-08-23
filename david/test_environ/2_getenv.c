#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
  *_getenv - function to get a specific environment variable name
  *@name: name of variaable to retrieve from environment list
  *
  *Return: A pointer to characters.
  */

char *_getenv(char *name)
{
	char *env_copy, *token, *remnant;
	unsigned int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		env_copy = _strdup(environ[i]);
		if (env_copy == NULL)
			return (NULL);
		token = strtok(env_copy, "=");
		if (_strcmp(token, name) == 0)
		{
			remnant = _strdup(token + _strlen(token) + 1);
			if (remnant == NULL)
			{
				free(env_copy);
				return (NULL);
			}
			free(env_copy);
			return (remnant); /*Free remanant when not null*/
		}
		free(env_copy);
	}
	return (NULL);
}
