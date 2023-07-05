#include "main.h"

int check_actual_prime(int n, int val);

/**
 * is_prime_number - Writing a function that check if
 * an integer is a prime number or not
 * @n: integer
 *
 * Return: 1 if n is a prime number, 0 if not
 */

int is_prime_number(int n)
{
	return (check_actual_prime(n, 2));
}

/**
 * check_actual_prime - A function that calculates
 * if a number is prime recursively
 * @n: integer
 * @val: iterator
 *
 * Return: 1 if n is prime, 0 if not
 */

int check_actual_prime(int n, int val)
{
	if (val == 1)
		return (1);
	else if (n % val == 0 && val > 0)
		return (0);
	return (check_actual_prime(n, val - 1));
}
