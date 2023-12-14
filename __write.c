#include "main.h"

/**
 * _write - a better clone of the write function
 *
 * @FD: file descriptor
 * @str: string to write
 */

void _write(int FD, const char *str)
{
	unsigned int len = _strlen(str);

	if (len > 0)
		if (write(FD, str, len) == -1)
			return;
}
