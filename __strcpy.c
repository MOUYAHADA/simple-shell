#include "main.h"

/**
 * _strcpy - copies a strign from str to dest
 * @src: source string
 * @dest: destination
 * Return: address of dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;
	char *s = src;

	while (*s != '\0')
	{
		*(dest + i) = *s;
		i++;
		s++;
	}
	*(dest + i) = '\0';

	return (dest);
}
