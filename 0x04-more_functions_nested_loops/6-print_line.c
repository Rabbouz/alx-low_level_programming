#include "main.h"

/**
 * print_line - Writing a function that draws a straight line in the terminal*
 *@n: number of times "_" should be printed
 * Return: void
*/

void print_line(int n)

{
	int a;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (a = 1; a <= n; a++)
		{
			_putchar('_');
		}
		_putchar('\n');
	}

}
