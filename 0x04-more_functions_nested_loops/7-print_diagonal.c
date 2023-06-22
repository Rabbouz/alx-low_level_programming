#include "main.h"

/**
 * print_diagonal - Writing a function
 * that draws a diagonal line on the terminal
 * @n: number of times the character \ should be printed
 * Return:  void
*/

void print_diagonal(int n)

{
	int a;
	int z;

	if (n <= 0)
	{
		_putchar('\n');
	}
		else
		{
			for (a = 0; a < n; a++)
			{
				for (z = 0; z < a; z++)
				{
					_putchar(32);
				}
				_putchar(92);
				_putchar('\n');
			}
		}
}
