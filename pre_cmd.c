#include "header.h"
/**
 * pre_line - function to print prompt at
 * the start of a line
 *
 * Return: 0 on success
 */
int pre_line(void)
{
	if (isatty(STDIN_FILENO))
	{
		_printf("$ ");
	}
	return (0);
}
