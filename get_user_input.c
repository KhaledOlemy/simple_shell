#include "header.h"
/**
 * get_user_input - function reads input command and
 *
 * Return: string input
 */
char *get_user_input(void)
{
	size_t n = 1024;
	char *buf = NULL;
	int nchar_read;

	nchar_read = getline(&buf, &n, stdin);
	if (nchar_read == -1 || _strcmp(buf, "exit\n") == 0)
	{
		free(buf);
		return ("void_line");
	}
	if (nchar_read == -1)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}
