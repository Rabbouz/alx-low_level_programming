#include "main.h"

/**
 * _islower -  checking for lowercase character
 *
 * @c: The character in ASCII table
 *
 * Return: 1 for lowercase character / 0 for else result
*/

int _islower(int c)
{
	if (c >= 97 && c <= 172)
	{
		return (1);
	}
	return (0);
}
