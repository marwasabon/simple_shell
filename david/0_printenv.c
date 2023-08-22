#include <stdio.h>

extern char **environ;

/**
  *main - function to print environment
  *
  *Return: void
  */

int main(void)
{
	char **env = environ;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
