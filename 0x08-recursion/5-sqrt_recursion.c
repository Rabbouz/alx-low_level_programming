#include "main.h"

int square(int n, int val);
/**
 * _sqrt_recursion - Writing a function that return
 * natural square root of a number
 * @n: integer to calculate the square root
 *
 * Return: integer
 */

int _sqrt_recursion(int n)
{
	return (square(n, 1));
}

/**
 * square - Writing a function that recurses to find the natural
 * square root of a number
 * @n: number(int) to find the sqaure
 * @val: square root
 *
 * Return: int
 */

int square(int n, int val)
{
	if (val * val > n)
		return (-1);
	else if (val * val == n)
		return (val);
	return (square(n, val + 1));
}
