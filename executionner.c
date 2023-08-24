#include "shell.h"
/**
 * _executionner - this is the function that will do it all
 * @line_buff: the line_buffer
 * @task_id: the task id to execute the right function for the right task
 * @envp: the envp
 * @tokens: the array of cmds
 */
void executionner(char *line_buff, int task_id, char **envp
, char **tokens)
{
	switch (task_id)
	{
		case 1:
			exec1(line_buff, tokens, envp);
			break;
		case 2:
			exec2(line_buff);
			break;
		case 3:
			exec3(line_buff, envp);
			break;
		case 4:
			exec4(tokens, envp);
	}
}

/**
 * exec1 - this function is specifically made for task 1
 * @line_buff: the line buffer
 * @tokens: an array of args
 * @envp: the env pointer
 */
void exec1(char *line_buff, char **tokens, char **envp)
{
	char *one_token, *two_token, *saveptr;
	char *args[] = {NULL};
	int i = 0, j = 0;

	(void) tokens;
	while (line_buff[i])
	{
		if (line_buff[i] == '\n')
		{
			one_token = _strtok_r(line_buff + j, " \t", &saveptr);
			while (1)
			{
				two_token = _strtok_r(NULL, " \t", &saveptr);
				if (!two_token)
					break;
				_strcat(one_token, two_token);
			}
			j = i + 1;
		}
		i++;
	}
	one_token[_strlen(one_token) - 1] = '\0';
	if (one_token)
	{
		execve(one_token, args, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

/**
 * exec2 - task 2 funciton (the arguments array will be of size 1024,
 * @line_buff: the line buffer
 */
void exec2(char *line_buff)
{
	char **args = splitstr(line_buff);

	if (args)
	{
		execve(args[0], args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

/**
 * exec3 - this function is specifically made for task 3
 * @line_buff: the line buffer
 * @envp: the env pointer
 */
void exec3(char *line_buff, char **envp)
{
	char **args = splitstr(line_buff);
	char *cmd;

	cmd = get_command(args[0], envp);
	if (cmd)
	{
		execve(cmd, args, envp);
		perror("cmd");
		exit(EXIT_FAILURE);
	}
	else
	{
		execve(args[0], args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
/**
 * exec4 - this function will handle the ";" "&&" "#" and "||"
 * @tokens: this is an array of arrays of strings
 * @envp: the env pointer, again , extern is not allowed
*/
void exec4(char **tokens, char **envp)
{
	char *cmd;

	cmd = get_command(tokens[0], envp);
	if (cmd)
	{
		execve(cmd, tokens, envp);
		perror("cmd");
		exit(EXIT_FAILURE);
	}
	else
	{
		execve(tokens[0], tokens, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
