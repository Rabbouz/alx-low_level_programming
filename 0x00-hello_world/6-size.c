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


	printf("The size of char: %lu byte(s)\n", sizeof(s));
	printf("The size of int: %lu byte(s)\n", sizeof(b));
	printf("The size of long int: %lu byte(s)\n", sizeof(l));
	printf("The size of long long init: %lu byte(s)\n", sizeof(c));
	printf("The size of float: %lu byte(s)\n", sizeof(z));


return (0);
}
