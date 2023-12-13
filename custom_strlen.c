#include "custom_shell.h"



/**
 * my_strlen - Calculate the length of a string
 * @str: The input string
 *
 * Return: The length of the string (excluding the null terminator)
 */


size_t my_strlen(const char *str)
{
size_t length = 0;
while (*str)
{
length++;
str++;
}
return (length);

}
