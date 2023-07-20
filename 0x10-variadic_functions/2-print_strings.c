#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - A function that prints strings, followed by a new line
 * @separator: The string
 * @n: The number of arguments
 * @...: Other variables
 *
 * Return: void
 */

void print_strings(const char *separator, const unsigned int n, ...)

{
	va_list string_lists;
	char *str;
	unsigned int i;

	va_start(string_lists, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(string_lists, char *);

		if (str != NULL)
			printf("%s", str);
		else
			printf("(nil)");

		if (i != (n - 1) && separator != NULL)
			printf("%s", separator);
	}

	printf("\n");

	va_end(string_lists);
}
