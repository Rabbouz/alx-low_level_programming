#include <stdlib.h>
#include "main.h"

/**
 * *initializeMemoryToZero - a funcion that fills memory with a constant byte
 * @s: memory area to be filled
 * @c: char
 * @n: number of times
 *
 * Return: pointer
 */

char *initializeMemoryToZero(char *s, char c, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = c;
	}

	return (s);
}

#include <stdlib.h>
#include "main.h"

/**
 * *_calloc - a function that allocates memory for an array
 * @nmemb: number of elements
 *  @size: size of each element
 *
 * Return: pointer
 */

void *_calloc(unsigned int nmemb, unsigned int size)

{
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(size * nmemb);

	if (ptr == NULL)
		return (NULL);

	initializeMemoryToZero(ptr, 0, nmemb * size);

	return (ptr);
}
