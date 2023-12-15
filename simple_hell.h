#ifndef SIMPLE_HELL_H
#define SIMPLE_HELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stddef.h>

void print_my(const char *my_text);
void my_prompt(void);
void read_input(char **input, size_t *size);
void exec_user_command(const char *input, char *envp[]);
char *_strncat(char *dest, char *src, int n);


#endif /*SIMPLE_HELL_H*/

