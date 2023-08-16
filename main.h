#ifndef MAIN_H
#define MAIN_H

int count_words(char *str);
char **string_to_tokens(char *string);
int print_string_array(char **str_array);
int free_string_array(char **string_array);
extern char **environ;

#endif
