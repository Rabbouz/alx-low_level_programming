#include "main.h"

/**
 * print_number - printing an integer
 * @i: integer to be printed
 */
void print_number(int i)

{
	unsigned int un;

	if (i < 0)
	{
		un = -i;
		_putchar('-');
	}
	else
	{
		un = i;
	}

	if (un / 10)
	{
		print_number(un / 10);
	}
	_putchar((un % 10) + '0');
}
