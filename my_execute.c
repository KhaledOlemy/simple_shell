#include "header.h"

/*
* my_execute - function to execute command
* @cmd: entered command
* @envv: environ variable
* Return: exit status
*/

exit_struct_t my_execute(char *cmd, char *envv[])
{
	pid_t c_p;
	char *temp[1024], *venv[1024];
	char *honda, *foundit;
	int z = 0;
	exit_struct_t new_exit;

	while (environ[z])
	{
		venv[z] = strdup(environ[z]);
		z++;
	}
	venv[z] = NULL;
	string_splitter(temp, cmd, "\n ");
	honda = _strdup(temp[0]);
	if (strcmp(honda, "exit") == 0)
	{
		new_exit.exit_1 = honda;
		if (temp[1])
		{
			new_exit.exit_2 = atoi(temp[1]);
		}
		else
		{
			new_exit.exit_2 = 0;
		}
		return (new_exit);
	}
	new_exit.exit_1 = NULL;
	if (strcmp(honda, "env") == 0)
	{
		current_env();
		new_exit.exit_2 = 0;
		return (new_exit);
	}
	foundit = search_in_paths(temp[0], envv);
	if (!foundit)
	{
		free(foundit);
		_printf("Command '%s' not found\n", temp[0]);
		new_exit.exit_2 = 127;
		return (new_exit);
	}
	c_p = fork();
	if (c_p == -1)
	{
		_printf("Error Forking\n");
		new_exit.exit_2 = 126;
		return (new_exit);
	}
	if (c_p == 0)
	{
		if (execve(foundit, temp, venv) == -1) /*string type []*/
		{
			_printf("Command '%s' not found\n", honda);
			new_exit.exit_2 = 127;
			return (new_exit);
		}
		free(foundit);
	}
	else
	{
		wait(NULL);
	}
	new_exit.exit_2 = 0;
	return (new_exit);
}
