#include "main.h"

/**
 * _puts_recursion - Writing a  function that
 * prints a string, followed by a new line
 *
 * @s*: pointer of  string
 * return: Always 0
*/
void _puts_recursion(char *s)

{
	if (*s == '\0')
	{
		_putchar('\n');
	}
	else
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}
}
