#include "main.h"

/**
 * print_square - printing a square
 * followed by a new line
 * @size: the size of the square
 * Return: void
*/

void print_square(int size)

{
	int a, z;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (a = 0; a < size; a++)
		{
			for (z = 0; z < size; z++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
}
