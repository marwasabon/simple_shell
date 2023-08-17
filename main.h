#ifndef MAIN_H
#define MAIN_H

int count_words(char *str);
char **string_to_tokens(char *string);
int print_string_array(char **str_array);
int free_string_array(char **string_array);

ssize_t _getline(char **lineptr, size_t *n);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);

int free_all(char *line, char **argv);
char *int_to_string(int command);
unsigned int int_count(int command);
int _printerror(int fd, char *string, int command_count);
int _exec(char **argv, char **env);


int print_path_name(char *full_pathname);
int dir_or_not(char *pathname);
int cmd_or_not(char *pathname);
char *get_cmd_path(char *text_from_line);

extern char **environ;

#endif
