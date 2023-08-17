#ifndef MAIN_H
#define MAIN_H

int count_words(char *str);
char **string_to_tokens(char *string);
int print_string_array(char **str_array);
int free_string_array(char **string_array);
extern char **environ;

/*New addition */
ssize_t _getline(char **lineptr, size_t *n);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);

#endif
