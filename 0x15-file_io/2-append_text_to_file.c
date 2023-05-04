#include "main.h"

/**
 * append_text_to_file - txt append file end
 * @filename: file nm
 * @text_content: termn str file end
 * Return: if succeeded 1, if failed -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int ws, fer, type_byte;

	if (filename == NULL)
		return (-1);

	ws = open(filename, O_WRONLY | O_APPEND);
	if (ws == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(ws);
		return (1);
	}

	for (fer = 0; text_content[fer]; fer++)
		;

	type_byte = write(ws, text_content, fer);
	if (type_byte == -1)
	{
		close(ws);
		return (-1);
	}

	close(ws);
	return (1);
}
