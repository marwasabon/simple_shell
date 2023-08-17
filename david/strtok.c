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
  *print_string_array - Function to print the string in an array
  *@str_array: array of strings
  *
  *Return: 0, if successful
  */

int print_string_array(char **str_array)
{
	char *str = "placeholder";
	int i = 0, j;

	for (i = 0; str != NULL; i++)
	{
		str = str_array[i];
		if (str != NULL)
		{
			if (i == 0)
				printf("%s", str);
			else
				printf("...%s", str);
		}
	}
	printf("\n");
	for (j = 0; j < i; j++)
		free(str_array[j]);
	free(str_array);
	return (0);
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
