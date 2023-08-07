#include "main.h"

/**
 * create_file - A function that creates a file.
 * @filename: A pointer of file name
 * @text_content: A pointer of string
 *
 * Return: if filename is NULL return -1,
 * if text_content is NULL create an empty file.
 */
int create_file(const char *filename, char *text_content)
{
	int wr, f;
	int length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[length] != '\0')
		length++;
	}

	f = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wr = write(fd, text_content, length);

	if (f == -1 || wr == -1)
		return (-1);

	close(f);

	return (1);
}
