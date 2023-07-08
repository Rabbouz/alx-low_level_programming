#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * check_num - check - A string there are digit
 * @str: array str
 *
 * Return: Always 0
 */

int check_num(char *str)

{
	unsigned int count;

	count = 0;

	while (count < strlen(str))

	{
		if (!isdigit(str[count]))
		{
			return (0);
		}

		count++;
	}
	return (1);
}

/**
 * main - A program that Prints the name of it
 * @argc: Count arguments
 * @argv: Arguments
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])

{

	int count;
	int str_to_intg;
	int result = 0;

	count = 1;
	while (count < argc)
	{
		if (check_num(argv[count]))

		{
			str_to_intg = atoi(argv[count]);
			result += str_to_intg;
		}

		else
		{
			printf("Error\n");
			return (1);
		}

		count++;
	}

	printf("%d\n", result);

	return (0);
}
