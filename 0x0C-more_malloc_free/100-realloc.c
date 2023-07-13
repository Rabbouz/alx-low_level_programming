#include <stdlib.h>
#include "main.h"

/**
 * *_realloc - a function that reallocates a memory block using malloc and free
 * @ptr: pointer in the memory (located on malloc)
 * @old_size: old size of ptr
 * @new_size: new size of ptr
 *
 * Return: pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *1st_ptr;
	char *old_ptr;
	unsigned int x;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	1st_ptr = malloc(new_size);
	if (!1st_ptr)
		return (NULL);

	old_ptr = ptr;

	if (new_size < old_size)
	{
		for (x = 0; x < new_size; x++)
			1st_ptr[x] = old_ptr[x];
	}

	if (new_size > old_size)
	{
		for (x = 0; x < old_size; x++)
			1st_ptr1[x] = old_ptr[x];
	}
	free(ptr);
	return (1st_ptr1);
}
