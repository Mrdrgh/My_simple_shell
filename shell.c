#include "shell.h"
/**
 * check_interactivity - checks if the stdin was redirected by the terminal
 * or it is flushed
 * Return: 0 if it was redirected , not 0 if else
 */
int check_interactivity(void)
{
	return (isatty(STDIN_FILENO));
}

/**
 * main - the main function to sh
 * @ac: the nbr of args
 * @av: the args
 * @envp: the env pointer
 * Return: 0 on exit_success
 */
int main(int ac, char **av, char **envp)
{
	int is_interactive = 1, i;
	char *line_buffer = NULL;
	ssize_t chars_nbr;
	size_t n = 0, task_id = 4;

	(void) ac, (void) av;
	while (is_interactive)
	{
		is_interactive = check_interactivity();
		if (is_interactive)
		{
			write(STDOUT_FILENO, "(Mr_drgh_shell)$ ", _strlen("(Mr_drgh_shell)$ "));
			chars_nbr = _getline(&line_buffer, &n, stdin);
		}
		else
			chars_nbr = non_interactive_getline(&line_buffer, &n, stdin);
		if (chars_nbr == -1)
		{
			free(line_buffer);
			return (EXIT_FAILURE);
		}
		if (chars_nbr != EOF)
		{
			i = checker(line_buffer, envp);
			if (i != 0)
			{
				if (i == 1)
					break;
				if (i != 1)
					continue;
			}
			executionner_prime(envp, line_buffer, task_id);
		}
	}
	free(line_buffer);
	exit(0);
}
/**
 * executionner_prime - will iterate through an array of commands that
 * were separated by ';' in the line_buffer, and then fork and execute
 * each one of them
 * @envp: env pointer, EXTERN is in the header if you want to use it
 * @line_buffer: evident
 * @task_id: the task id
*/
void executionner_prime(char **envp, char *line_buffer, int task_id)
{
	char ***token_of_tokens;
	pid_t son;
	int stat, i = 0;

	token_of_tokens = split_str_prime(line_buffer);
	while (token_of_tokens[i])
	{
		if (_strcmp(token_of_tokens[i][0], "cd") == 0)
		{
			change_dir(token_of_tokens[i], envp);
			i++;
			continue;
		}
		son = fork();
		if (son == -1)
		{
			free(line_buffer);
			perror("son died");
			exit(EXIT_FAILURE);
		}
		if (son == 0)
		{
			executionner(line_buffer, task_id, envp, token_of_tokens[i]);
		}
		else
		{
			wait(&stat);
		}
		i++;
	}
	free(token_of_tokens);
}

