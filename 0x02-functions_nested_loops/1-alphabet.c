#include "main.h"

/**
 * main- Entry point
 *
 * Description: printing the alphabet in lowercase
 *
 * Return: Void
*/

void print_alphabet(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
	{
	_putchar(c);
	}
	_putchar('\n');
}
