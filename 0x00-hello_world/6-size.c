#include <stdio.h>

/**
 * main - Starting point
 *
 * Description: a C program that prints the size of various types
 *
 * Return: Alwawys 0 (Success)
*/
int main(void)
{

	char s;
	int b;
	long int l;
	long long int c;
	float z;


	printf("Size of a char: %lu byte(s)\n", (unsigned long)sizeof(s));
	printf("Size of an int: %lu byte(s)\n", (unsigned long)sizeof(b));
	printf("Size of a long int: %lu byte(s)\n", (unsigned long)sizeof(l));
	printf("Size of a long long int: %lu byte(s)\n", (unsigned long)sizeof(c));
	printf("Size of a float: %lu byte(s)\n", (unsigned long)sizeof(z));


return (0);
}
