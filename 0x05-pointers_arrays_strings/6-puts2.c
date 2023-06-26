#include "main.h"

/**
 * puts2 - Write a function that prints every other character of a string
 * starting with the first character, followed by a new line
 * @str: is a string
 * Return: void
*/

void puts2(char *str)

{
	int len = 0;
	int x = 0;
	char *s = str;
	int t;

	while (*s != '\0')
	{
		s++;
		len++;
	}
	x = len - 1;
	for (t = 0 ; t <= x ; t++)
	{
		if (t % 2 == 0)
		{
			_putchar(str[t]);
		}
	}
	_putchar('\n');
}
