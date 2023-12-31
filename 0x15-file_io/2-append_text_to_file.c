#include "main.h"
/**
 * append_text_to_file - A function that ap²pends text
 * at the end of a file.
 * @filename: A pointer to same file
 * @text_content: string
 *
 * Return: Return: 1 on success and -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)

{
	int op, length = 0, wr;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[length])
		length++;
	}

	op = open(filename, O_WRONLY | O_APPEND);
	if (op == -1)
	return (-1);
	wr = write(op, text_content, length);
	close(op);
	if (wr == -1)
	return (-1);

	return (1);
}
