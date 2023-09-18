#include "main.h"
/**
 * _strncat - writing a function that concatenate two strings
 * using at most n bytes from src
 * @dest: distination string
 * @src:source string
 * @n: input value
 *
 * Return: dest
 */

char *_strncat(char *dest, char *src, int n)

{
	int a, b;

	a = 0;
	while (dest[a] != '\0')
	{
		a++;
	}
	b = 0;
	while (b < n && src[b] != '\0')
	{
	dest[a] = src[b];
	a++;
	b++;
	}
	dest[a] = '\0';
	return (dest);
}
