#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
  *dir_or_not - checks if the pathname includes a directory or not
  *@pathname: pathname to the file system object
  *
  *Return: 0 if true, -1 if not
  */

int dir_or_not(char *pathname)
{
	unsigned int i = 0;

	while (pathname[i] != '\0')
	{
		if (pathname[i] == '/')
		{
			return (0);
		}
		i++;
	}
	return (-1);
}

/**
  *cmd_or_not - checks if a given pathname is an execuatable or not
  *@pathname: pathname to fs object
  *
  *Return: 0 if true, -1 otherwise.
  */

int cmd_or_not(char *pathname)
{
	struct stat buf;

	if (stat(pathname, &buf) == 0)
	{
		return (0);
	}
	return (-1);
}

/**
  *cpy_n_cat - Function to copy and catenate full_path with text
  *@path: proposed path of interest
  *@suffix: suffix to add to original path
  *@prefix: The prefix to the path
  *
  *Return: full_path
  */

char *cpy_n_cat(char *path, char *prefix, char *suffix)
{
	_strcpy(path, prefix);
	_strcat(path, "/");
	_strcat(path, suffix);
	return (path);
}


/**
  *get_cmd_path - function to get command full pathname if cmd exists
  *@text_from_line: Raw text that should come from command line
  *@env: array of env
  *
  *Return: An actual string if given command is a command, or NULL otherwise
  */

char *get_cmd_path(char *text_from_line, char **env)
{
	char *path_str, *path_str_copy, *token, *full_path;
	struct stat buf;

	if (dir_or_not(text_from_line) == 0)
	{
		if (cmd_or_not(text_from_line) == 0)
		{
			full_path = _strdup(text_from_line);
			if (full_path == NULL)
				return (NULL);
			return (full_path);
		}
			return (NULL);
	}
	else
	{
		path_str_copy = _getenv("PATH", env); /* use _getenv of main func instead*/
		path_str = _strdup(path_str_copy);
		if (path_str_copy != NULL)
			free(path_str_copy);
		if (path_str == NULL)
			return (NULL);
		token = strtok(path_str, ":");
		while (token != NULL)
		{
			full_path = malloc(sizeof(char) * 1024);
			if (full_path == NULL)
				break;
			cpy_n_cat(full_path, token, text_from_line);
			if (stat(full_path, &buf) == 0)
			{
				free(path_str);
				return (full_path);
			}
			token = strtok(NULL, ":");
			free(full_path);
		}}
	free(path_str);
	return (NULL);	/*free text, if str is not null*/
}
