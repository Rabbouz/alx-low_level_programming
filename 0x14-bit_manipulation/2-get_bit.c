#include "main.h"
/**
 * get_bit - A function that returns the value
 * of a bit at an index in a decimal number
 * @n: number
 * @index: index
 *
 * Return: int(bit value)
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bit_value;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
