#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- A function that Reads a text file print
 * to standard output.
 * @filename: text file
 * @letters: number of letters
 * Return: number of bytes read and printed,
 * 0 if failed or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)

{
	char *bf;
	ssize_t f;
	ssize_t s;
	ssize_t z;


	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	bf = malloc(sizeof(char) * letters);
	s = read(f, bf, letters);
	z = write(STDOUT_FILENO, bf, s);

	free(bf);
	close(f);
	return (z);
}
