#include "header.h"
/**
 * _strdup- copies a string to a new location using malloc
 * @str: string to be copied
 * Return: pointer to the new string.
 */
char *_strdup(char *str)
{
	char *ptr;
	int i;
	int j = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[j] != '\0')
	{
		j++;
	}
	j += 1;
	ptr = malloc(j * sizeof(char));
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < j; i++)
	{
		ptr[i] = str[i];
	}
	ptr[i] = '\0';
	return (ptr);
}
