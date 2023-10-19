#include "header.h"

/**
  * handle_comments - function to delete comments
  * @temp: input
  * Return: the input without comments
  */

char *handle_comments(char *temp)
{
	char *comment_position;

	comment_position = _strstr(temp, "#");
	if (comment_position)
	{
		*comment_position = '\0';
	}
	return (temp);
}

/**
  * _strstr - function that locates substring
  * @haystack: first input
  * @needle: second input
  * Return: pointer to the beginning of the located substring
  */

char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *h = haystack;
		char *n = needle;

		while (*h == *n && *n != '\0')
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return (haystack);
	}
	return (0);
}
