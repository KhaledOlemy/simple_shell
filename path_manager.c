#include "header.h"
#include <dirent.h>
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
			break;
		}
		c++;
	}
	piece = strtok(str, "=");
	piece = strtok(NULL, "=");	/** free needed for str */
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
	char *temoo[1024];	/* too much*/
	char *str_holder = NULL;

	if ((access(command, F_OK) == 0) && (opendir(command) == NULL))
	{
		str_holder = _strdup(command);
		return (str_holder);
	}
	string_splitter(temoo, command, "/");
	if (!temoo[0])
	{
		return (NULL);
	}
	while (temoo[q])
	{
		q++;
	}
	z = 0;
	while (pathlist[z])
	{
		str_holder = _strdup(pathlist[z]);
		str_holder = _strcat(str_holder, "/");
		str_holder = _strcat(str_holder, temoo[q - 1]);
		if ((access(str_holder, F_OK) == 0) &&
		 (_strcmp(str_holder, pathlist[z]) != 0))
		{
			free_array(temoo);
			return (str_holder);
		}
		free(str_holder);
		z++;
	}
	free_array(temoo);
	return (NULL);
}
