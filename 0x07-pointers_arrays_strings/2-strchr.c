#include "main.h"

/**
 * _strchr - Write a function that locates
 * a character in a string
 * @s: pointer input
 * @c: constant input
 * Return: poiter s
 */

char *_strchr(char *s, char c)

{
	int i;

	for (i = 0; s[i] >= '\0' ; i++)
		{
			if (s[i] == c)
			{
				return (s + i);
			}
		}
	return ('\0');
}
