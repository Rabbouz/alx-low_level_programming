#include "main.h"
/**
 * _strlen - Writing a function that returns the length of a string
 * @s: is a string
 * Return: length
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}

	return (len);
}
