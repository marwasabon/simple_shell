#include <stdio.h>
#include <stdlib.h>
#include "main.h"


/**
  *main - Function to test out the strings
  *
  *Return: 0 if success
  */


int main(void)
{
	char *dest, *dest1;
	char *src = "Joy cometh";

	dest1 = malloc(100);
	_strcpy(dest1, src);
	dest = _strdup(src);
	printf("src str: %s, dest str: %s\n", dest, src);

	printf("Lenth of dest string is %d, and for src string is %d\n", _strlen(dest), _strlen(src));
	printf("Comparism between dest and src is %d\n", _strcmp(dest, src));
	printf("Comparism between cat and camp is %d\n", _strcmp("cat", "camp"));
	printf("src str: %s, dest str: %s\n", dest, src);
	_strcat(dest1, src);
	printf("The catenation of dest1+src is: %s\n", dest1);
	free(dest);
	free(dest1);

	return (0);
}
