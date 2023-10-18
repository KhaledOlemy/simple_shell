#include "header.h"
/**
 * main - main function responsible for getting user input commands
 * , reading it, parsing, and eventually executing, to work in both
 * interactive mode, and non-interactive mode.
 *
 * Return: 0 when successful, else [1:255].
 */
int main(void)
{
	char *cmd, *path, *envv[1024];
	int i = 0;
	exit_struct_t rtrn;

	while (1)
	{
		pre_line();
		cmd = get_user_input();
		if (cmd == NULL)
		{
			return (0);
		}
		if (_strcmp(cmd, "void_line") == 0)
		{
			continue;
		}
		path = path_finder();
		string_splitter(envv, path, ":");
		rtrn = my_execute(cmd, envv);
		if (rtrn.exit_1)
		{
			return (rtrn.exit_2);
		}
		free(cmd);
		if (!isatty(STDIN_FILENO))
		{
			return (0);
		}
	}
	while (envv[i])
	{
		free(envv[i]);
	}
	return (0);
}
