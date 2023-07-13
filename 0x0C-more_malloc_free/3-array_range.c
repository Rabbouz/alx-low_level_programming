#include <stdlib.h>
#include "main.h"

/**
 * *array_range - A function that creates an array of integers
 * @min: minimum range of values
 * @max: maximum range of values
 *
 * Return: pointer
 */

int *array_range(int min, int max)
{
	int *ptr;
	int m, range_length;

	if (min > max)
		return (NULL);

	range_length = max - min + 1;

	ptr = malloc(sizeof(int) * range_length);

	if (ptr == NULL)
		return (NULL);

	for (m = 0; min <= max; m++)
		ptr[m] = min++;

	return (ptr);
}
