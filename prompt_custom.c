#include "custom_shell.h"

/**
 * prompt_custom - Prints the custom prompt
 * Return: Void
 */
void prompt_custom(void)
{
if (isatty(STDIN_FILENO))
{
const char prompt[] = "$ ";

write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
fflush(stdout);

}

}

