#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
  *print_path_name - prints path nemaeif the path to the file exist
  *@full_pathname: path name to the file
  *
  *Return: 0 if successful, and -1 otherwise
  */

int print_path_name(char *full_pathname) /*No need of func*/
{
	if (full_pathname != NULL)
		printf("%s\n", full_pathname);
	return (0);
}

/**
  *main - function to put all the above functions to make which
  *@argc: count of arguments
  *@argv: vector of arguments
  *
  *Return: 0
  */


int main(int argc, char **argv)
{
	char *full_path_name = NULL;
	int i;

	if (argc < 2)
	{
		printf("Usage: %s ...\n", argv[0]);
	}

	for (i = 1; i < argc; i++)
	{
		full_path_name = get_cmd_path(argv[i]);
		print_path_name(full_path_name);
		free(full_path_name);
	}
	return (0);
}
