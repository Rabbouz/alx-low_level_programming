#include "main.h"

/**
 * flip_bits - A function that counts the number
 * of bits to change to get from one number to another
 * @n: 1st number
 * @m: 2nd number
 *
 * Return: number of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int it, counter = 0;
	unsigned long int curr;
	unsigned long int exc = n ^ m;

	for (it = 63; it >= 0; it--)
	{
		curr = exc >> it;
		if (curr & 1)
		{
			counter++;
		}
	}

	return (counter);
}
