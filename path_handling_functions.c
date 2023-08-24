#include "shell.h"

/**
 * _getenv - getenv
 * @var: the name of the environment variable
 * @envp: the environ pointer , extern IS NOT ALLOWED
 * Return: the value of the environment variable, or NULL if it does not exist
 */
char *_getenv(char *var, char **envp)
{
	int i;
	size_t len = strlen(var);

	for (i = 0; envp[i] != NULL; i++)
	{
		if (_strncmp(envp[i], var, len) == 0 && envp[i][len] == '=')
			return (&envp[i][len + 1]);
	}
	return (NULL);
}

/**
 * get_command - gets the full path of a command
 * @command: the command to get the path of
 * @envp: the env pointer
 * Return: the full path of the command, or NULL if it does not exist
 */
char *get_command(char *command, char **envp)
{
	char *path = _getenv("PATH", envp);
	char *token, *saveptr;
	char *full_cmd;
	struct stat st;

	token = _strtok_r(path, ":", &saveptr);
	while (token)
	{
		full_cmd = malloc(sizeof(char) * (_strlen(token) + _strlen(command) + 2));
		_strcpy(full_cmd, token);
		_strcat(full_cmd, "/");
		_strcat(full_cmd, command);
		if (stat(full_cmd, &st) == 0)
			return (full_cmd);
		token = _strtok_r(NULL, ":", &saveptr);
	}
	free(full_cmd);
	return (NULL);
}

/**
 * print_env - prints the environ of the current program
 * @envp: the environ pointer
*/

void print_env(char **envp)
{
	int i = 0;

	while (envp[i])
	{
		write(1, envp[i], _strlen(envp[i]));
		write(1, "\n", 1);
		i++;
	}
}
