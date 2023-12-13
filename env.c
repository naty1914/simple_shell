#include "custom_shell.h"

/**
* print_environment - Prints the current  envrionment variables
* Return: Void
*/




void print_environment(void)
{
int i, j;

for (i = 0; environ[i]; i++)
{
if (i > 0)
write(STDOUT_FILENO, "\n", 1);
for (j = 0; environ[i][j]; j++)
{
write(STDOUT_FILENO, &environ[i][j], 1);
}
}

write(STDOUT_FILENO, "\n", 1);
}
