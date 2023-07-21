#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - A function that prints anything
 * @format: list of argement types
 *
 * Return: void
*/

void print_all(const char * const format, ...)

{

	int index = 0;
	char *str, *seperator = "";
	va_list list_of_anything;

	va_start(list_of_anything, format);

	if (format)
	{
		while (format[index])
		{
			switch (format[index])
			{
				case 'c':
					printf("%s%c", seperator, va_arg(list_of_anything, int));
					break;
				case 'i':
					printf("%s%d", seperator, va_arg(list_of_anything, int));
					break;
				case 'f':
					printf("%s%f", seperator, va_arg(list_of_anything, double));
					break;
				case 's':
					str = va_arg(list_of_anything, char *);
					if (!str)
						str = "(nil)";
					printf("%s%s", seperator, str);
					break;
				default:
					index++;
					continue;
			}
			seperator = ", ";
			index++;
		}
	}

	printf("\n");
	va_end(list_of_anything);
}
