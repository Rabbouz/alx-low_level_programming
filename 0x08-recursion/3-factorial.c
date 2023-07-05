#include "main.h"

/**
 * factorial - Writing a function that returns the factorial of a number
 * @n: integer to return the factorial
 *
 * Return: (int)factorial of n
 */
int factorial(int n)

{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}
