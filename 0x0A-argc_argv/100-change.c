#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - A program that prints the minimum number of coins to
 * make change for an amount of money
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 if Success, 1 if Error
 */

int main(int argc, char *argv[])

{
	int num, l;
	int result;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num = atoi(argv[1]);
	result = 0;

	if (num < 0)
	{
		printf("0\n");
		return (0);
	}

	for (l = 0; l < 5 && num >= 0; l++)
	{
		while (num >= coins[l])
		{
			result++;
			num -= coins[l];
		}
	}

	printf("%d\n", result);
	return (0);
}
