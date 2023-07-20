#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - A funtion that returns the sum of two numbers
 * @a: 1st number
 * @b: 2nd number
 *
 * Return: sum
 */

int op_add(int a, int b)

{
	return (a + b);
}

/**
 * op_sub - A function that returns the difference of two numbers
 * @a: 1st number
 * @b: 2nd number
 *
 * Return: difference
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - a function that returns the product of two numbers
 * @a: 1st number
 * @b: 2nd number
 *
 * Return: product
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - a function that returns the division of two numbers
 * @a: 1st number
 * @b: 2nd number
 *
 * Return: result
 */
int op_div(int a, int b)
{
	return (a / b);
}
/**
 * op_mod - a function that eturns the result of the division of two numbers
 * @a: The first number.
 * @b: The second number.
 *
 * Return: remainder
 */
int op_mod(int a, int b)
{
	return (a % b);
}
