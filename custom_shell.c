#include "custom_shell.h"

/**
 * sigint_handler - Handles the SIGINT signal (Ctrl+C)
 * @signum: The signal number (unused)
 */
void sigint_handler(int signum)
{
(void)signum;
write(STDOUT_FILENO, "\n$ ", 3);
}



/**
 * main - Is the custom shell main function
 * Return: Always 0
 */
int main(void)
{

char *buffer = NULL;
int len;
size_t n = 0;

if (signal(SIGINT, sigint_handler) == SIG_ERR)
{

perror("signal");
exit(EXIT_FAILURE);
}

while (1)
{
prompt_custom();

if (getline(&buffer, &n, stdin) == -1)
{
free(buffer);
exit(0);
}

len = my_strlen(buffer);
if (buffer[len - 1] == '\n')
{
buffer[len - 1] = '\0';
}

execute_command(buffer);

}


free(buffer);

return (0);
}
