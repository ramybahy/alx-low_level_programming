#include "main.h"
#include <stdlib.h>

/**
 * read_textfile-  file txt pr to STDOUT.
 * @filename: read file txt
 * @letters: read letters num
 * Return: z --byte num printed
 * 0 if func failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t m;
	ssize_t z;
	char *hed;
	ssize_t ws;

	ws = open(filename, O_RDONLY);
	if (ws == -1)
		return (0);
	hed = malloc(sizeof(char) * letters);
	m = read(ws, hed, letters);
	z = write(STDOUT_FILENO, hed, m);

	free(hed);
	close(ws);
	return (z);
}

