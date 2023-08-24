#include "shell.h"

/**
 * is_command - Checks if a command exists in PATH
 * @cmd: The command name to check
 * @envp: the envp
 * Return: 1 if command exists, 0 if not
*/

int is_command(char *cmd, char **envp)
{
	char *path = NULL, *saveptr;
	char *token = NULL;
	char *cmd_path = NULL;
	struct stat st;

	if (!cmd)
	{
		return (0);
	}
	if (stat(cmd, &st) == 0)
	{
		return (1);
	}
	path = _getenv("PATH", envp);
	token = _strtok_r(path, ":", &saveptr);

	while (token)
	{
		cmd_path = malloc(sizeof(char) * (_strlen(token) + _strlen(cmd) + 2));
		_strcpy(cmd_path, token);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, cmd);
		if (stat(cmd_path, &st) == 0)
		{
			free(cmd_path);
			return (1);
		}
		free(cmd_path);
		token = _strtok_r(NULL, ":", &saveptr);
	}
	return (0);
}
