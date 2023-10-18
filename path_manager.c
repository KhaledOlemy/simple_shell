#include "header.h"
/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string where i search
 * @needle: string to find
 * Return: haystack
 */

char *starts_with(char *haystack, char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack++)
		{
			return (NULL);
		}
	}
	return (haystack);
}
/**
 * path_finder - finction to find a path
 *
 * Return: path
 */
char *path_finder(void)
{
	char *path = "PATH=";
	int c = 0;
	char *str = NULL;
	char *piece;

	while (environ[c])
	{
		if (starts_with(environ[c], path))
		{
			str = _strdup(environ[c]);
		}
		c++;
	}
	piece = strtok(str, "=");
	piece = strtok(NULL, "=");
	return (piece);
}
/**
 * search_in_paths - searches for command in pathlist
 * @command: command to be executed
 * @pathlist: list of pathes
 * Return: command if found
 */
char *search_in_paths(char *command, char *pathlist[])
{
	int z = 0, q = 0;
	char *temoo[1024];
	char *str_holder = NULL;

	if (access(command, F_OK) == 0)
	{
		return (command);
	}
	string_splitter(temoo, command, "/");
	while (temoo[q])
	{
		q++;
	}
	while (pathlist[z])
	{
		str_holder = pathlist[z];
		str_holder = _strcat(str_holder, "/");
		str_holder = _strcat(str_holder, temoo[q - 1]);
		if (access(str_holder, F_OK) == 0)
		{
			return (str_holder);
		}
		z++;
	}
	return (NULL);
}
