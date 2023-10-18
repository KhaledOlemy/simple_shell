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
	struct exit_struct rtrn;

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
		free(cmd);
		free_array(envv);
		if (rtrn.exit_1)
		{
			free(rtrn.exit_1);
			return (rtrn.exit_2);
		}
		if (!isatty(STDIN_FILENO))
		{
			return (0);
		}
	}
	return (0);
}
