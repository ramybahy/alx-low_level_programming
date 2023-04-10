#include "main.h"

/**
 * main - 1st pnt
 * description: copy file cont to another
 * @vfqc: argum num
 * @vfqb: argum arr
 * Return: if succeeded 0, if failed 97-100
 */
int main(int vfqc, char *vfqb[])
{
	int port, rec, rd_byte, type_byte;
	char bfr[1024];

	if (vfqc != 3)
		dprintf(STDERR_FILENO, "Usage: cp port rec\n"), exit(97);

	/* open port */

	port = open(vfqb[1], O_RDONLY);
	if (port == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", vfqb[1]);
		exit(98);
	}

	/* opn file_to */

	rec = open(vfqb[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (rec == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", vfqb[2]), exit(99);

	/* rd from port and type to rec */

	while ((rd_byte = read(port, bfr, 1024)) > 0)
	{
		type_byte = write(rec, bfr, rd_byte);
		if (type_byte == -1)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", vfqb[2]), exit(99);
	}

	if (rd_byte == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", vfqb[1]);
		exit(98);
	}

	if (close(port) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", port), exit(100);

	if (close(rec) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", rec), exit(100);

	return (0);
}
