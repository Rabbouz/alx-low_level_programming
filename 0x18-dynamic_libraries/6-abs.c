#include "main.h"

/**
 * _abs - computing the absolute
 * value of an integer
 * @i: input as integer
 *
 * Return: absolute value of integer
*/
int _abs(int i)

{
	if (i >= 0)
	{
		return (i);
	}
	else
	{
		return (i * -1);
	}
}
