#include "main.h"

/**
 * print_array - Write a function that prints n elements
 *  of an array of integers, followed by a new line.
 * @a:is an  array
 * @n: is the number of elements of array
 * Return: a and n
 */

void print_array(int *a, int n)

{
	int x;

	for (x = 0; x < (n - 1); x++)
	{
		printf("%d, ", a[x]);
	}
		if (x == (n - 1))
		{
			printf("%d", a[n - 1]);
		}
			printf("\n");
}
