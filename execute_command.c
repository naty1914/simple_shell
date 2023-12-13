#include "custom_shell.h"

/**
 * tokenize_input - Tokenizes the input string into an array of arguments
 * @input: The input string to be tokenized
 * @args: An array of command arguments
 * Return: Nothing
 */
void tokenize_input(char *input, char *args[])
{
char *token = strtok(input, DELIM);
int arg_counter = 0;

while (arg_counter < 999)
{
args[arg_counter] = token;
if (args[arg_counter] == NULL)
break;
token = strtok(NULL, DELIM);
arg_counter++;
}

args[arg_counter] = NULL;
}

/**
 * execute_external_command - Executes an external command in a child process
 * @args: An array of command arguments
 * @input: The original input string
 * Return: Nothing
 */
void execute_external_command(char *args[], char *input)
{
pid_t pid = create_process();
int status;

if (pid == 0)
{
if (isatty(STDIN_FILENO) && args[0] != NULL)
search_command_in_path(args, input);
else
search_command_in_path(args, input);
}
else if (pid == -1)
{
perror("fork");
exit(0);
}
else
{
waitpid(pid, &status, 0);

if (!isatty(STDIN_FILENO))
{
if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
{
free(input);
exit(127);
}
}
}
}

/**
 * execute_command - Executes the input command
 * @input: The input string containing the command
 * Return: Nothing
 */

void execute_command(char *input)
{
char *args[1000];
tokenize_input(input, args);

exit_command(args, input);




if (args[0] != NULL && (strcmp(args[0], "env") == 0 ||
strcmp(args[0], "printenv") == 0))
{
print_environment();
return;
}

if (args[0] != NULL)
{
execute_external_command(args, input);
}
}

