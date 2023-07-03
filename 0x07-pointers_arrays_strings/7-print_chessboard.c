#include "main.h"

/**
 * print_chessboard - Writing a function that prints the chessboard
 * @a: array
 * Return: Always 0
 */

void print_chessboard(char (*a)[8])

{
	int i, jr;

	for (i = 0; i < 8; i++)
	{
		for (jr = 0; jr < 8; jr++)
			_putchar(a[i][jr]);
		_putchar('\n');
	}
}

