#include "custom_shell.h"

/**
 * exit_command - It handles the custom shell "exit" command
 * @args: The range of arguments passed to the command
 * @input: The original input string
 * Return: Nothing
 */

void exit_command(char **args, char *input)
{
if (args[0] != NULL && strcmp(args[0], "exit") == 0)
{
if (args[1] != NULL)
{
char *endptr;
long status = strtol(args[1], &endptr, 10);
if (*endptr == '\0')
{
if (status < 0)
{
fprintf(stderr, "./hsh: %d: exit: Illegal number: %s\n", 1, args[1]);
free(input);
exit(2);
}
else
{
free(input);
exit(status);
}
}
else
{
fprintf(stderr, "./hsh: %d: exit: Illegal number: %s\n", 1, args[1]);
free(input);
exit(2);
}
}
else
{
free(input);
exit(0);
}
}

}
