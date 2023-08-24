#include "shell.h"

/**
 * _putchar - puts a char
 * @c: the char to put
 * Return: whatever
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - using _putchar , print a string into stdout
 * @s: the string to put out
 * Return: the nbr of chars printed
*/
int _puts(char *s)
{
	char *p = s;
	int len = 0;

	while (*p)
	{
		_putchar(*p);
		p++;
		len++;
	}
	return (len);
}
/**
 * _strlen - returns the len of the string
 * @s: the string to checck
 * Return: the  nbr of chars
*/
int _strlen(char *s)
{
	char *p = s;
	int len = 0;

	while (*p)
	{
		p++;
		len++;
	}
	return (len);
}
/**
 * _strcat - concates str2  into str1
 * @dest: the result
 * @src: the str to concate
 * Return: the result str
*/
char *_strcat(char *dest, char *src)
{
	int i_dest, i_src;

	i_dest = 0;
	while (dest[i_dest] != '\0')
	{
		i_dest++;
	}
	i_src = 0;
	while (src[i_src] != '\0')
	{
		dest[i_dest] = src[i_src];
		i_dest++;
		i_src++;
	}

	dest[i_dest] = '\0';
	return (dest);
}
/**
 * _strncat - concatenates the first n chars of src
 * @dest: the destination
 * @src: the source
 * @n: the number of the chars
 * Return: the destination
*/

char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	char *ppp = src;
	char *qqq = dest;

	while (*qqq)
	{
		qqq++;
	}
	while (i < n && *ppp)
	{
		*qqq = *ppp;
		i++;
		ppp++;
		qqq++;
	}
	*qqq = '\0';
	return (dest);
}

