#include "header.h"
/**
 * free_array - free allocated memory for array items
 * @arr: arr to clear of memory
 *
 * Return: nothing.
*/
void free_array(char *arr[])
{
	int i = 0;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
}
