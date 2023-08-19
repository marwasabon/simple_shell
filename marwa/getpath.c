#include <stdio.h>
#include <unistd.h>
#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
	char *construct_fpathname(char *path, char *file)
{
	int path_len = strlen(path);
	int file_len = strlen(file);
	char *full_path = malloc(path_len + file_len + 2);

	for (int i = 0; i < path_len; i++)
	{
		full_path[i] = path[i];
	}
	full_path[path_len] = '/';

	for (int i = 0; i < file_len; i++)
	{
		full_path[path_len + 1 + i] = file[i];
	}

	full_path[path_len + file_len + 1] = '\0';

	return (full_path);/*full path should be freed by user*/
}


char *_getenv(const char *name)
{
	int j, i = 0;
	size_t name_len = strlen(name);
	char *var;
	for (i = 0; environ[i] != NULL; i++)
	{
		var = environ[i];/**/
		j = 0;

		while (var[j] == name[j])
		{

			if (name[j] == '\0' || var[j] == '=')
			{

				break;
			}

			j++;

		}
		if (var[j] == '=' && j == name_len)

		{

			return (&var[j + 1]);
		}

	}
	return (NULL);
}
char *get_paths(char **file)
{
	struct stat buffer;
	char *env_path;
	char *dir;
	char *file_path;
	int dir_length, file_length;

	env_path = _getenv("PATH");
	dir = env_path;
	int found = 0;

	dir = my_strtok(env_path, ":");
	while (dir != NULL)
	{
		dir_length = strlen(dir);
		file_length = strlen(*file);
		file_path = malloc(dir_length + file_length + 2);

		file_path = construct_fpathname(dir, *file);

		if (stat(file_path, &buffer) == 0)
		{
			write(STDOUT_FILENO, "command exists", 14);
			write(STDOUT_FILENO, "\n", 1);
			found = 1;
			break;
		}
		else
		{
			free(file_path);
			file_path = NULL;
		}

		dir = my_strtok(NULL, ":");
	}

	if (found)
	{
		char *result = malloc(sizeof(char *));

		result = file_path;
		return (result);
	}
	else
	{
		write(STDOUT_FILENO, "command does not exist", 20);
		write(STDOUT_FILENO, "\n", 1);
		return (NULL);
	}
}
