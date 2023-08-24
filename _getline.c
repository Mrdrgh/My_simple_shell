#include "shell.h"
#include <linux/limits.h>
/**
 * _getchar - reads a single character from stdin
 *
 * Return: The character read from stdin if successful, EOF otherwise
 */
int _getchar(void)
{
	int c = 0;
	ssize_t len_read = 0;

	len_read = read(STDIN_FILENO, &c, 1);
	if (len_read == -1)
	{
		perror("getchar");
		return (EOF);
	}
	if (len_read == 0)
	{
		return (EOF);
	}

	return (c);
}
/**
 * _getline - Reads a line from a stream into a buffer
 * @lineptr: Double pointer to the buffer that will store the line
 * @n: Pointer to the size of the buffer
 * @stream: The stream to read from (usually stdin)
 *
 * Return: The number of characters read or -1 on error
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buff = NULL, c;
	size_t buff_size = 0, len_read = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL)
	{
		*lineptr = malloc(*n * sizeof(char));
		if (*lineptr == NULL)
			return (-1);
	}
	buff = *lineptr;
	buff_size = *n;

	while ((c = _getchar()) != EOF)
	{
		if (len_read + 1 >= buff_size)
		{
			buff_size += 128;
			buff = _realloc(buff, *n, buff_size);
			if (buff == NULL)
			{
				free(buff);
				return (-1);
			}
		}
		buff[len_read++] = c;
		if (c == '\n')
			break;
	}
	if (len_read == 0)
	{
		free(buff);
		return (-1);
	}
	buff[len_read] = '\0';
	*lineptr = buff;
	*n = buff_size;
	return (len_read);
}
/**
 * non_interactive_getline - Reads a line from a stream into a buffer but
 * doens't stop until it reaches \0
 * @lineptr: Double pointer to the buffer that will store the line
 * @n: Pointer to the size of the buffer
 * @stream: The stream to read from (usually stdin)
 *
 * Return: The number of characters read or -1 on error
 */
ssize_t non_interactive_getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buff = NULL, c;
	size_t buff_size = 0, len_read = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL)
	{
		*lineptr = malloc(*n * sizeof(char));
		if (*lineptr == NULL)
			return (-1);
	}
	buff = *lineptr;
	buff_size = *n;

	while ((c = _getchar()) != EOF)
	{
		if (len_read + 1 >= buff_size)
		{
			buff_size += 128;
			buff = _realloc(buff, *n, buff_size);
			if (buff == NULL)
			{
				free(buff);
				return (-1);
			}
		}
		buff[len_read++] = c;
		if (c == '\0')
			break;
	}
	if (len_read == 0)
	{
		free(buff);
		return (-1);
	}
	buff[len_read] = '\0';
	*lineptr = buff;
	*n = buff_size;
	return (len_read);
}
