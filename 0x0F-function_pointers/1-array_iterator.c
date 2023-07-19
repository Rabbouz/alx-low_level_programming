#include "function_pointers.h"
#include <stdio.h>
/**
 * array_iterator - a function that prints each element
 * of an array
 * @array: array
 * @size: elements
 * @action: function pointer
 * Return: void
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array != NULL || action != NULL)

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
