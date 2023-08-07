#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *c_buffer(char *file);
void closing_file(int fd);

/**
 * closing_file - A fucntion that closes file descriptors.
 * @f_d: file descriptor
 */

void closing_file(int f_d)

{
	int cl;

	cl = close(f_d);

	if (cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_d);
		exit(100);
	}
}

/**
 * c_buffer - A function that allocates 1024 bytes
 * for the buffer.
 * @file: file buffer to store chars in
 *
 * Return: A pointer
 */

char *c_buffer(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buff);
}

/**
 * main - A function that copies the contents of a file to a secoond file.
 * @argc: number of arguments
 * @argv: An array
 *
 * Return: Always 0 (success)
 */

int main(int argc, char *argv[])
{
	int source_fd, dest_fd, bytes_wr, bytes_rd;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = c_buffer(argv[2]);
	source_fd = open(argv[1], O_RDONLY);
	bytes_rd = read(source_fd, buff, 1024);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (source_fd == -1 || bytes_rd == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		bytes_wr = write(dest_fd, buff, bytes_rd);
		if (dest_fd == -1 || bytes_wr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		bytes_rd = read(source_fd, buff, 1024);
		dest_fd = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buff);
	close_file(source_fd);
	close_file(dest_fd);

	return (0);
}
