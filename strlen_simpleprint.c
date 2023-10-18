#include "header.h"
/**
 * my_strlen - function to calculate length of string
 * @str: string to get its length
 *
 * Return: length of str
 */
int my_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * simple_print- prints simple string using write
 * @str: str to print
 *
 * Return: nothing
 */

void simple_print(char *str)
{
	write(1, str, my_strlen(str));
}
