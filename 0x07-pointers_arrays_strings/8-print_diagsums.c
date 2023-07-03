#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Writing a function that prints
 * the sum of the two diagonals of a square matrix of integers
 * @a: pointer input
 * @size: integer input
 * Return: Always 0
 */

void print_diagsums(int *a, int size)

{
	int i;
	int s1 = 0;
	int s2 = 0;

	for (i = 0; i < size; i++)
	{
		s1 += a[i];
		s2 += a[size - i - 1];
		a += size;
	}
	printf("%d, ", s1);
	printf("%d\n", s2);
}
