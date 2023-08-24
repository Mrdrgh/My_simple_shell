#include "shell.h"
/**
 * check_delim - Checks If A Character Match Any Char
 * @c: Char
 * @str: Stri
 * Return: 1
 */
unsigned int check_delim(char c, char *str)
{
	unsigned int index;

	for (index = 0; str[index] != '\0'; index++)
	{
		if (c == str[index])
			return (1);
	}
	return (0);
}

/**
 * _strtok_r - Token A String Into Token (strtrok), this is a safe version
 * of _strtok
 * @str: Str
 * @saveptr: a saving pointer instead of static chars
 * @delim: delimiter
 * Return: Pointer To The
 */
char *_strtok_r(char *str, char *delim, char **saveptr)
{
	char *token;
	unsigned int i;

	if (str != NULL)
		*saveptr = str;
	token = *saveptr;
	if (token == NULL)
		return (NULL);
	for (i = 0; token[i] != '\0'; i++)
	{
		if (check_delim(token[i], delim) == 0)
			break;
	}

	if ((*saveptr)[i] == '\0' || (*saveptr)[i] == '#')
	{
		*saveptr = NULL;
		return (NULL);
	}
	token = *saveptr + i;
	*saveptr = token;
	for (i = 0; (*saveptr)[i] != '\0'; i++)
	{
		if (check_delim((*saveptr)[i], delim) == 1)
			break;
	}

	if ((*saveptr)[i] == '\0')
		*saveptr = NULL;
	else
	{
		(*saveptr)[i] = '\0';
		*saveptr = *saveptr + i + 1;
		if (**saveptr == '\0')
			*saveptr = NULL;
	}

	return (token);
}
