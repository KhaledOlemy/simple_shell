#include "header.h"
/**
 * get_user_input - function reads input command and
 *
 * Return: string input
 */
char *get_user_input()
{
	size_t n = 1024;
	char *buf = NULL, *str;
	int nchar_read;

	buf = malloc(sizeof(char) * n);
	nchar_read = getline(&buf, &n, stdin);
	if (nchar_read == 1)
	{
		return ("void_line");
	}
	if (nchar_read == -1)
	{
		return (NULL);
	}
	str = _strdup(buf);
	free(buf);
	return (str);
}
