#include "main.h"

/**
 * _isupper - Writing a function that checks for uppercase character
 * @c: is the  character to be checked as an integer
 * Return: 1 for uppercase / 0 otherwise
 *
*/

int _isupper(int c)

{

	if (c == 'A')
	{
		return (1);
	}
	else if (c == 'a')
	{
		return (0);
	}
	return (0);
}
