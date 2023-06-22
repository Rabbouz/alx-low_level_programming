#include "main.h"

/**
 * _isdigit - Writing a function that checks for a digit*
 * @i: integer to be checked
 * Return: 1 for digit output / 0 otherwise
*/

int _isdigit(int i)

{
	if (i >= 49 && i <= 57)
	{
		return (1);
	}
	return (0);
}
