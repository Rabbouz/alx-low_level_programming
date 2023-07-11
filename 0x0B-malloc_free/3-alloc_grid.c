#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - a function that returns
 * a pointer to a 2 dimensional array of integers
 * * @width: width input
 * @height: height input
 * Return: pointer, NULL if failure
 */

int **alloc_grid(int width, int height)

{
	int **us;
	int a, b;

	if (width <= 0 || height <= 0)
		return (NULL);

	us = malloc(sizeof(int *) * height);

	if (us == NULL)
		return (NULL);

	for (a = 0; a < height; a++)
	{
		us[a] = malloc(sizeof(int) * width);

		if (us[a] == NULL)
		{
			for (; a >= 0; a--)
				free(us[a]);

			free(us);
			return (NULL);
		}
	}

	for (a = 0; a < height; a++)
	{
		for (b = 0; b < width; b++)
			us[a][b] = 0;
	}

	return (us);
}
