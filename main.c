#include "header.h"

/**
* main - check the code
*
* Return: 0 on success
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
			while (envv[i])
			{
				free(envv[i]);
			}
			return (0);
		}
	}
	while (envv[i])
	{
		free(envv[i]);
	}
	return (0);
}
