#include "main.h"
/**
 * print_binary - A function that prints
 * the binary equivalent of a decimal number
 * @n: printed number
 *
 * Return: void
 */

void print_binary(unsigned long int n)
{
	int it, counter;
	unsigned long int curr;

	counter = 0;

	for (it = 63; it >= 0; it--)
	{
		curr = n >> it;

		if (curr & 1)
		{
			_putchar('1');
			counter++;
		}
		else if (counter)
			_putchar('0');
	}
	if (!counter)
		_putchar('0');
}
