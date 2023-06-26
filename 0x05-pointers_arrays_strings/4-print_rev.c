#include "main.h"
/**
 * print_rev - Writing a function that prints a string, in reverse,
 * followed by a new line.
 * @s: is a string
 * return: Always 0
 */

void print_rev(char *s)
{
	int len = 0;
	int p;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	s--;
	for (p = len; p > 0; p--)
	{
		_putchar(*s);
		s--;
	}
		_putchar('\n');
}
