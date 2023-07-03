#include "main.h"
/**
 *_memcpy - Writing a function that copies memory area
 *@dest: memory to store
 *@src: source
 *@n: number of bytes
 *
 *Return: pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
