#include <stdio.h>
#include <string.h>
#include "main.h"


/**
  *main - Function to test line func above
  *
  *Return: size_t datatype
  */

int main(void)
{
	char *line = NULL;
	size_t n;
	ssize_t n_read;

	n_read = _getline(&line, &n);
	if (n_read > 0)
		printf("Check if new line still exists %s after string\n", line);
	return (0);
}
