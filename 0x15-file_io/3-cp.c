#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - 1024 bytes allocate buffer.
 * @file: file nm
 * Return: new buffer
 */
char *create_buffer(char *file)
{
	char *bfr;

	bfr = malloc(sizeof(char) * 1024);

	if (bfr == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (bfr);
}


void close_file(int ws)
{
	int m;

	m = close(ws);

	if (m == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", ws);
		exit(100);
	}
}


int main(int vfqc, char *vfqb[])
{
	int port, rec, g, z;
	char *bfr;

	if (vfqc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	bfr = create_buffer(vfqb[2]);
	port = open(vfqb[1], O_RDONLY);
	g = read(port, bfr, 1024);
	rec = open(vfqb[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (port == -1 || g == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", vfqb[1]);
			free(bfr);
			exit(98);
		}

		z = write(rec, bfr, g);
		if (rec == -1 || z == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", vfqb[2]);
			free(bfr);
			exit(99);
		}

		g = read(port, bfr, 1024);
		rec = open(vfqb[2], O_WRONLY | O_APPEND);

	} while (g > 0);

	free(bfr);
	close_file(port);
	close_file(rec);

	return (0);
}
