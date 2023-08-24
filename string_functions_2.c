#include "shell.h"

/**
 * splitstr - Split a string into tokens
 * @str: The string to be split
 *
 * Return: An array of tokens
 */
char **splitstr(char *str)
{
	char *token, **tokens = NULL, *saveptr;
	int count = 0;

	token = _strtok_r(str, " \t\n", &saveptr);
	while (token)
	{
		tokens = _realloc(tokens,
		count * sizeof(char *), (count + 1) * sizeof(char *));
		count++;
		if (!tokens)
		{
			perror("realloc couldn't alloc :(");
			exit(EXIT_FAILURE);
		}
		tokens[count - 1] = token;
		token = _strtok_r(NULL, " \t\n", &saveptr);
	}
	tokens = _realloc(tokens, count * sizeof(char*), (count + 1) * sizeof(char *));
	tokens[count] = NULL;
	return (tokens);
}

/**
 * char *_strcpy - copy src to dest
 * @dest: the dest
 * @src: the src
 * Return: the dest
 */
char *_strcpy(char *dest, char *src)
{
	int lll = 0;
	int xxx = 0;

	while (*(src + lll) != '\0')
	{
		lll++;
	}
	for ( ; xxx < lll ; xxx++)
	{
		dest[xxx] = src[xxx];
	}
	dest[lll] = '\0';
	return (dest);
}

/**
 * _strcmp - cmps s1 and s2
 * @s1: the first str
 * @s2: the  second
 *
 * Return: *s1 - *s2
 */
int _strcmp(char *s1, char *s2)
{
	int index;

	if (!s1 || !s2)
	{
		return (-15);
	}
	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] != s2[index])
		{
			return (s1[index] - s2[index]);
		}
		index++;
	}
	return (0);
}

/**
 * _strdup - dups str into the returner
 * @str: the str
 * Return: the duplicate
 */
char *_strdup(char *str)
{
	char *duplicate;
	int i, r = 0;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;

	duplicate = malloc(sizeof(char) * (i + 1));

	if (duplicate == NULL)
	{
		free(duplicate);
		return (NULL);
	}

	for (r = 0; str[r]; r++)
		duplicate[r] = str[r];

	return (duplicate);
}

/**
 * _strncmp - Compare two length-limited strings
 * @cs: One string
 * @ct: Another string
 * @count: The maximum number of bytes to compare
 * Return: cs - ct
 */
int _strncmp(char *cs, char *ct, int count)
{
	int i = 0, j = 0;

	while (count)
	{
		if (cs[i] != ct[j])
		{
			return (cs[i] - ct[j]);
		}
		i++;
		j++;
		count--;
	}
	return (0);
}
