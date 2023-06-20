#include "main.h"

/**
 * _isalpha - checking for alphabetic character
 * @c: the characters on ASCII table
 * Return: 1 for letters / 0 for elsse result
*/

int _isalpha(int c)

{

	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}
