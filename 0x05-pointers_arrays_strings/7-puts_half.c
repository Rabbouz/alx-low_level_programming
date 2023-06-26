#include "main.h"
/**
 * puts_half - Write a function that prints half of a string
 * followed by a new line.
 * if odd len, n = (length_of_the_string - 1) / 2
 * @str: string input
 * Return: half of input
 */

void puts_half(char *str)

{
	int e, i, len;

	len = 0;

	for (e = 0; str[e] != '\0'; e++)
		len++;

	i = (len / 2);

	if ((len % 2) == 1)
		i = ((len + 1) / 2);

	for (e = i; str[e] != '\0'; e++)
		_putchar(str[e]);
	_putchar('\n');
}
