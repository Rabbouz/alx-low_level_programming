#include "main.h"
/**
 * binary_to_uint - A function that converts
 * a binary number to unsigned int
 * @b: string
 *
 * Return: int(converted number)
 */

unsigned int binary_to_uint(const char *b)
{
	int it;
	unsigned int d_value = 0;

	if (!b)
		return (0);

	for (it = 0; b[it]; it++)
	{
		if (b[it] < '0' || b[it] > '1')
			return (0);
		d_value = 2 * d_value + (b[it] - '0');
	}

	return (d_value);
}
