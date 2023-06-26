#include "main.h"
/**
 * print_rev - imprime en reversa
 * @s: string
 * return: 0
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
	}
}
