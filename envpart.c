#include "header.h"

/**
* current_env - function to print the current env
*
* Return: 0 on success.
*/

int current_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
