#include "main.h"

/**
 * _isupper - Writing a function that checks for uppercase character
 * @i: the integer to be checked
 * Return: 1 for uppercase / 0 otherwise
 *
*/

int _isupper(int i)
{
	if (i >= 65 && i <= 90)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
