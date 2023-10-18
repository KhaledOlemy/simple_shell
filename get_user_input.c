#include "header.h"
/**
 * get_user_input - function reads input command and
 *
 * Return: string input
 */
char *get_user_input(void)
{
	size_t n = 0;
	char *buf = NULL;
	ssize_t nchar_read;

	nchar_read = getline(&buf, &n, stdin);
	
	if (nchar_read == -1 || _strcmp(buf, "exit\n") == 0)
	{
		free(buf);
		exit (1);
	}
	return (buf);
}
