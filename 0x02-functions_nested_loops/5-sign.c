#include "main.h"

/**
 * print_sign - printing the sign of a number
 * @n: input as an integer
 *
 * Return: 1 for greater number / 0 for zero
 * -1 for lesser than zero number
*/

int print_sign(int n)

{
	if (n > 0)
	{
		_putchar(43);
	return (1);
	}
	else if (n < 0)
	{
		_putchar(45);
		return (0);
	}
	else
	{
		_putchar(48);
		return (-1);
	}
}
