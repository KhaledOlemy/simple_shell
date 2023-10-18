#include "header.h"
/**
 * current_env - function responsible for printing env
 * to stdout.
 * Return: 0, always success.
 */
int current_env(void)
{
	extern char **environ;
	int i = 0;

	while (environ[i] != NULL)
	{
		_printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
