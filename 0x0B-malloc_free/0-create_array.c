#include "main.h"
#include <stdlib.h>
/**
 * create_array - creating an  array of size size and assign char c
 * @size: size of array
 * @c: char
 * Description: create array of size size and assign char c
 * Return: pointer to array, NULL if fail
 *
 */

char *create_array(unsigned int size, char c)
{
	char *st;
	unsigned int i;

	st = malloc(sizeof(char) * size);
	if (size == 0 || st == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		st[i] = c;
	return (st);
}