#include "shell.h"

/**
 * checker - checks line buffer for builtin commands
 * @line_buffer: the command line
 * @envp: environ pointer
 * Return: command indicator or 0 if not found
 */
int checker(char *line_buffer, char **envp)
{
	char *cmd_copy = strdup(line_buffer), *save_ptr = NULL;
	char *token = strtok_r(cmd_copy, " \t\n", &save_ptr);
	char *arg1 = NULL, *arg2 = NULL, *arg3 = NULL;

	if (_strcmp(token, "exit") == 0)
	{
		free(cmd_copy);
		return (1);
	}
	if (_strcmp(token, "env") == 0)
	{
		print_env(envp);
		free(cmd_copy);
		return (2);
	}
	if (_strcmp(token, "setenv") == 0)
	{
		arg1 = strtok_r(NULL, " \t\n", &save_ptr);
		arg2 = strtok_r(NULL, " \t\n", &save_ptr);
		arg3 = strtok_r(NULL, " \t\n", &save_ptr);
		if (!arg1 || !arg2)
		{
			perror("error");
			free(cmd_copy);
			return (-1);
		}
		_setenv(arg1, arg2, (_strcmp(arg3, "1")) ? false : true);
		free(cmd_copy);
		return (3);
	}

	if (_strcmp(token, "unsetenv") == 0)
	{
		arg1 = strtok_r(NULL, " \t\n", &save_ptr);
		_unsetenv(arg1);
		free(cmd_copy);
		return (4);
	}
	return (0);
}
