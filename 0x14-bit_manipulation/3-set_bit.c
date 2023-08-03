#include "main.h"
/**
 * set_bit - A funcion that sets a bit at a given index to 1
 * @n: pointer
 * @index: index
 *
 * Return: 1 if  success, -1 if failed
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n |= (1UL << index);
	return (1);
}
