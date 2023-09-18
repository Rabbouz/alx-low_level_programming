#include "main.h"
/**
 * _memset - Writing a function that fills a block of memory
 * with a specific value
 * @s: pointer
 * @b: constant
 * @n: number of bytes to use
 *
 * Return: new value of n
 */

char *_memset(char *s, char b, unsigned int n)

{
	unsigned int i;

	for (i = 0; n > 0; i++, n--)
	{
		s[i] = b;
	}
	return (s);
}
