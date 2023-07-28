#include <stdio.h>

void first(void) __attribute__ ((constructor));

/**
 * first - A function that prints a sentence before the main
 * function is xecuted
 * Return: nothind(void)
 */

void first(void)

{
 printf("You're beat! and yet, you must allow,\n");
 printf("I bore my house upon my back!\n");
}
