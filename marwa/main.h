#ifndef MAIN_H
#define MAIN_H

int count_words(char *str);
char **string_to_tokens(char *string);
int print_string_array(char **str_array);
int free_string_array(char **string_array);
int free_all(char *line, char **argv);
char *int_to_string(int command);
unsigned int int_count(int command);
int _printerror(int fd, char *string, int command_count);
extern char **environ;

#endif
