#include "custom_shell.h"

/**
 * _getenv - Retrieves the value of an environmental variable
 * @name: The name of the environmental variable
 * Return: A pointer to the value of the environmental variable, or NULL
 */


char *_getenv(const char *name)
{
size_t name_len = my_strlen(name);

char **env = environ;
while (*env != NULL)
{
if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
{
return ((*env) + name_len + 1);
}
env++;
}

return (NULL);
}

/**
 * search_command_in_path - It runs a command in the child process
 * @args:  The range of arguments passed to the command
 * @input: The original input string
 * Return: Void
 */
void search_command_in_path(char *args[], char *input)
{
char *path_copy;
char *token;
char full_path[1024];
int command_found = 0;
char separator = '/';
path_copy = _getenv("PATH");
if (strchr(args[0], '/') != NULL)
{
if (execve(args[0], args, NULL) == -1)
{
perror("execve failed");
free(input);
exit(1);
}
}
token = strtok(path_copy, ":");
while (token != NULL)
{
snprintf(full_path, sizeof(full_path), "%s%c%s", token, separator, args[0]);
if (access(full_path, X_OK) == 0)
{command_found = 1;
break;
}
token = strtok(NULL, ":");
}
if (!command_found)
{
fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
free(input);
exit(127);
}
else
{
if (execve(full_path, args, NULL) == -1)
{
perror("execve failed");
free(input);
exit(2);
}
}
}
