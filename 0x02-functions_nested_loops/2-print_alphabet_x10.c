#include "main.h"

/**
 * print_alphabet_x10 - printing alphabet 10 times
 *
 * Return: void
*/

void print_alphabet_x10(void)
{
	char z;
	int i = 0;

	while (i <= 10)
	{
		for (z = 'a'; z <= 'z'; z++)
		{
			_putchar(z);
		}
		_putchar('\n');
		i++;
	}
}
