#include "main.h"

/**
 * _strlen - count the length of a string
 *
 * @str:string
 *
 * Return: length of the string @str
 */

size_t _strlen(char const *str)
{
	unsigned int i;

	i = 0;
	if (str == NULL)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}
