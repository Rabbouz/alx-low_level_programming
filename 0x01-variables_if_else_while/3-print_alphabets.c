#include <stdio.h>

/**
 * main- Entry point
 *
 * Description: printing alphabet in lowercase, and then in uppercase
 *
 * Return: Always 0
*/
int min(void)
{

	char lowercase, uppercase;

	for (lowercase = 'a' ; lowercase <= 'z'; lowercase++)
{
	putchar(lowercase);
}
for (uppercase = 'A'; uppercase <= 'Z'; uppercase++)

{
	putchar(uppercase);
}
putchar('\n');
return (0);
}
