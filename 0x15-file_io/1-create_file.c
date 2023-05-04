#include "main.h"

/**
 * create_file - file crt
 * @filename:file nm
 * @text_content: file termn string
 * Return: 1 if succeed and -1 if  failed
 */
int create_file(const char *filename, char *text_content)
{
	int ws, fer, type_byt;

	if (filename == NULL)
		return (-1);

	ws = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (ws == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(ws);
		return (1);
	}

	for (fer = 0; text_content[fer]; fer++)
		;

	type_byt = write(ws, text_content, fer);
	if (type_byt == -1)
	{
		close(ws);
		return (-1);
	}

	close(ws);
	return (1);
}
