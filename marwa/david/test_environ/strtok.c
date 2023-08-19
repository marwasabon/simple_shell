#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <unistd.h>
/**
  *count_words - Function to count the number of spaces in a string
  *@str: String to count the spaces for
  *
  *Return: >= 0 if successful, and -1 otherwise
  */

int count_words(char *str)
{
	char *s, *token;
	int count = 0;

	if (str == NULL)
		return (-1);

	s = _strdup(str);
	if (s == NULL)
		return (-1);

	token = strtok(s, " \t");

	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " \t");
	}
	free(s);
	return (count);
}

/**
  *string_to_tokens - Function to split string to array of tokens seperated
  *by space
  *@string: String to be split into tokens
  *Return: An array of strings
  */

char **string_to_tokens(char *string)
{
	int count, i, j;
	char **string_array;
	char *string_cpy, *token;

	if (string == NULL)
		return (NULL);
	string_cpy = _strdup(string);
	if (string_cpy == NULL)
		return (NULL);
	count = count_words(string);
	if (count <= 0)
	{
		free(string_cpy);
		return (NULL);
	}
	string_array = malloc(sizeof(char *) * (count + 1));
	if (string_array == NULL)
	{
		free(string_cpy);
		return (NULL);
	}
	token = strtok(string_cpy, " \t");
	for (i = 0; token != NULL; i++)
	{
		string_array[i] = _strdup(token);
		if (string_array[i] == NULL)
		{
			for (j = 0; j <= i; i++)
				free(string_array[j]);
			free(string_array);
			free(string_cpy);
			return (NULL);
		}
		token = strtok(NULL, " \t");
	}
	string_array[i] = token; /*NULL terminating array*/
	free(string_cpy);
	return (string_array);  /*string_array must be freed by user program*/
}


/**
  *free_string_array - Function to free a string array
  *@string_array: string array passed into func
  *
  *Return: 0
  */

int free_string_array(char **string_array)
{
	char *str = "placeholder";
	int i = 0, j;

	if (string_array == NULL)
		return (0);

	for (i = 0; str != NULL; i++)
	{
		str = string_array[i];
	}
	for (j = 0; j < i; j++)
		free(string_array[j]);
	free(string_array);
	return (0);
}


/**
 *free_all - Function to free a string array
 *@string: string command line.
 *@string_array: argument vector.
 *@full_path: name of full path name
 *
 *Return: 0
 */

int free_all(char *string, char **string_array, char *full_path)
{
	if (string)
		free(string);
	if (string_array)
		free_string_array(string_array);
	if (full_path != NULL)
	{
		free(full_path);
	}
	return (0);
}
