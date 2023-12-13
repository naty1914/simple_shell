#ifndef CUSTOM_SHELL_H
#define CUSTOM_SHELL_H


#define DELIM " \t\r\n"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stddef.h>
extern char **environ;

extern char *_getenv(const char *name);



void prompt_custom(void);
size_t my_strlen(const char *str);
pid_t create_process(void);
void execute_command(char *input);
void search_command_in_path(char *args[], char *input);
void exit_command(char **args, char *input);

void print_environment(void);



#endif

