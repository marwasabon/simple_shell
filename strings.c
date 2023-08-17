#include <stdlib.h>


/**
  *_strcpy - Function to copy src to dest
  *@dest: Already set string to copy into
  *@src: src of string to copy from
  *
  *Return: A pointer to destination
  */

char *_strcpy(char *dest, char *src)
{
	char *p;
	int i;

	for (p = src; p[i] != '\0'; i++)
	{
		dest[i] = p[i];
	}
	dest[i] = '\0';
	return (dest);
}


/**
  *_strlen - Function that calculates the length of the string
  *@str: string
  *
  *Return: integer length of the string
  */

int _strlen(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
		continue;
	return (i);
}

/**
  *_strcmp - Function to compare two strings lexicogr...
  *@str1: first string to compare
  *@str2: second string to compare
  *
  *Return: An integet that tells if s1>s2, equal, or s1<s2
  */

int _strcmp(char *str1, char *str2)
{
	int compare;

	char *s1 = str1;
	char *s2 = str2;

	for (; *s1 != '\0'; s1++, s2++)
	{
		if (*s1 != *s2)
		{
			compare = *s1 - *s2;
			return (compare);
		}
	}
	compare = *s1 - *s2;
	return (compare);
}

/**
  *_strdup - Function to duplicate string.
  *@str: string to duplicate
  *
  *Return: String duplicated
  */

char *_strdup(char *str)
{
	char *str_dup;
	int i, len;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);

	str_dup = malloc((sizeof(char) * len) + 1);
	if (str_dup == NULL)
		return (NULL);

	if (len == 0)
		str_dup[0] = str[0];
	else
	{
		for (i = 0; i <= len; i++)
			str_dup[i] = str[i];
	}
	return (str_dup);
}

