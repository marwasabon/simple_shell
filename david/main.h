#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <errno.h>
int print_prompt(int fd);
int count_words(char *str);
char **string_to_tokens(char *string);
int print_string_array(char **str_array);
int free_string_array(char **string_array);

ssize_t _getline(char **lineptr, size_t *n);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);
char *_strcat(char *str1, char *str2);

int free_all(char *line, char **argv, char *full_path);
char *int_to_string(int command);
unsigned int int_count(int command);
int _printerror(int fd, char *string, int command_count, char *cmd_name);
int _exec(char **linetptr, char **argv, char **env, char *cmd_name);


int print_path_name(char *full_pathname);
int dir_or_not(char *pathname);
int cmd_or_not(char *pathname);
char *get_cmd_path(char *text_from_line);

int dir_or_not(char *pathname);
int cmd_or_not(char *pathname);
char *get_cmd_path(char *text_from_line);
char *_path(char **argv, char **line,
		char *shell_name, int cmd_count, int *staus);
int _print_path_error(char *shell_name, char *wrong_cmd, int command_count);

char *_getenv(char *name);
int extra(char ***argv, char **line, int *status);
void exit_shell(char **argv);
void print_env(void);
extern char **environ;

#endif
