#include <stdio.h>
#include "main.h"

/**
  *_getline - Function to get line and remove new line character
  *@lineptr: pointer(address) to line string
  *@n: The newly allocated size of the string
  *
  *Return: n_read, number of bytes read
  */

ssize_t _getline(char **lineptr, size_t *n)
{
	ssize_t n_read;
	unsigned int len;

	n_read = getline(lineptr, n, stdin);
	if (n_read <= 0)
		return (n_read);
	len = _strlen(*lineptr);
	if ((*lineptr)[len - 1] == '\n')
		(*lineptr)[len - 1] = '\0';
	return (n_read);
}
