#include "custom_shell.h"

/**
 * create_process - Creates a new process using fork function
 * Return: The pid of the child process if it succeeds, or -1 if it fails
 */

pid_t create_process(void)
{
pid_t pid = fork();
if (pid == -1)
{
perror("fork error");
exit(1);
}
return (pid);
}


