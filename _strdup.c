#include "header.h"
/**
 * _strdup- copies a string to a new location using malloc
 * @str: string to be copied
 * Return: pointer to the new string.
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i = 0, len = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[len])
	{
		len++;
	}
	dup = malloc(sizeof(char) * (len + 10000));
	if (dup == NULL)
	{
		free(dup);
		return (NULL);
	}
	while ((dup[i] = str[i]) != '\0')
	{
		i++;
	}
	return (dup);
}
