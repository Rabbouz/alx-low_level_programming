#include "main.h"


/**
 * _sqrt_recursion - Writing a function that return
 * natural square root of a number
 * @n: integer to calculate the square root
 *
 * Return: integer
 */
int square(int n, int vl);
int _sqrt_recursion(int n)
{
	return (square(n, 1));
}

/**
 * square - Writing a function that recurses to find the natural
 * square root of a number
 * @n: number(int) to find the sqaure
 * @vl: square root
 *
 * Return: integer
 */

int square(int n, int vl)
{
	if (vl * vl > n)
		return (-1);
	else if (vl * vl == n)
		return (vl);
	return (square(n, vl + 1));
}
