#include "header.h"

/**
  * pre_line - function to print prompt at
  * the start of a line
  *
  * Return: 0 on success
  */

int pre_line(void)
{
	if (isatty(STDIN_FILENO))
	{
		/**
		* char cwd[1024];
		* char *user;
		* char host[1024];
		* user = getlogin();
		* getcwd(cwd, sizeof(cwd));
		* gethostname(host, sizeof(host));
		* _printf("%s@%s:%s$ ", user, host, cwd);
		*/
		_printf("$ ");
	}
	return (0);
}
