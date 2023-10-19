#include "header.h"
/**
 * my_execute - function to execute command
 * @cmd: entered command
 * @envv: environ variable
 *
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
		venv[z] = _strdup(environ[z]);
		z++;
	}
	venv[z] = NULL;
	string_splitter(temp, cmd, "\n ");
	honda = _strdup(temp[0]);		/*********************/
	if (!honda)
	{
		_printf("Command '%s' not found\n", honda);
		new_exit.exit_1 = NULL;
		new_exit.exit_2 = 0;
		free_array(temp);
		free_array(venv);
		return (new_exit);
	}
	if (_strcmp(honda, "exit") == 0)
	{
		new_exit.exit_1 = _strdup(honda);	/*********************/
		new_exit.exit_2 = 0;
		free_array(temp);
		free_array(venv);
		free(honda);
		return (new_exit);
	}
	new_exit.exit_1 = NULL;
	if (_strcmp(honda, "env") == 0)
	{
		current_env();
		new_exit.exit_2 = 0;
		free_array(temp);
		free_array(venv);
		free(honda);
		return (new_exit);
	}
	foundit = search_in_paths(temp[0], envv);
	if (!foundit)
	{
		_printf("Command '%s' not found\n", honda);
		new_exit.exit_2 = 127;
		free(honda);
		free_array(temp);
		free_array(venv);
		return (new_exit);
	}
	c_p = fork();
	if (c_p == -1)
	{
		_printf("Error Forking\n");
		new_exit.exit_2 = 126;
		free(honda);
		free(foundit);
		free_array(temp);
		free_array(venv);
		return (new_exit);
	}
	if (c_p == 0)
	{
		if (execve(foundit, temp, venv) == -1)
		{
			_printf("Command '%s' not found\n", honda);
			new_exit.exit_2 = 127;
			free(honda);
			free(foundit);
			free_array(temp);
			free_array(venv);
			return (new_exit);
		}
	}
	else
	{
		wait(NULL);
	}
	new_exit.exit_2 = 0;
	free(honda);
	free(foundit);
	free_array(temp);
	free_array(venv);
	return (new_exit);
}
