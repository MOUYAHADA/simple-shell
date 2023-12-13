#include "main.h"

/**
 * _ispath - check if a string is a path
 *
 * @str: string to check
 *
 * Return: 1 if path, 0 if not
 */

int _ispath(char *str)
{
	int index = 0;

	while (str[index] != '\0')
	{
		if (str[index] == '/')
			return (1);
		index++;
	}
	return (0);
}
