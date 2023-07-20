#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - A function that Prints numbers followed by a new line
 * @separator: The string
 * @n: The number of integers
 * @...: other variables
 */

void print_numbers(const char *separator, const unsigned int n, ...)

{

	va_list numbs;
	unsigned int i;

	va_start(numbs, n);

	for (i = 0; i < n; i++)
	{
		if (i > 0 && separator != NULL)
			printf("%s", separator);

		printf("%d", va_arg(numbs, int));
	}

	printf("\n");

	va_end(numbs);
}
