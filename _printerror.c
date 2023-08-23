#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"
/**
 *int_count - Function to count the commands entered by the user.
 *@command: the command.
 *Return: An integer number of command.
 */
unsigned int int_count(int command)
{
	unsigned int i = 0;

	if (command == 0)
		return (1);

	while (command != 0)
	{
		command = command / 10;
		i++;
	}
	return (i);
}
/**
 *int_to_string - Function to print the error and its number.
 *@command: the command.
 * Return: string to the commands entered..
 */
char *int_to_string(int command)
{
	unsigned int i, count;
	char *str;

	count = int_count(command);

	str  = malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	for (i = 0; i < count; i++)
	{
		str[count - i - 1] =  (command % 10) + '0';
		command = command / 10;

	}
	str[count] = '\0';
	return (str); /*malloc needs to be freed*/
}
/**
 *_printerror - Function to print the error and its number.
 *@fd: file descriptor.
 *@string: shell name.
 *@command_count: number of commands.
 *@cmd_name: command full path name to print error
 *Return: An integer the error no.
 */
int _printerror(int fd, char *string, int command_count, char *cmd_name)
{
	char *str;

	str = int_to_string(command_count);

	write(fd, string, (_strlen(string) + 1));
	write(fd, ": ", 3);
	if (str != NULL)
	{
		write(fd, str, (_strlen(str) + 1));
		write(fd, ": ", 3);
	}
	write(STDERR_FILENO, cmd_name, (_strlen(cmd_name) + 1));
	write(STDERR_FILENO, ": ", 3);
	perror(NULL);
	free(str);
	return (0);
}
