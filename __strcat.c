#include "main.h"

/**
 * _strcat - concatenate two strings
 *
 * @dest: final string
 * @src: additional string
 *
 * Return: final string
 */

char *_strcat(char *dest, char *src)
{
	char *dest_2 = dest;

	while (1)
	{
		if (*dest_2 == '\0')
		{
			while (*src != '\0')
			{
				*dest_2 = *src;
				src++;
				dest_2++;
			}
			break;
		}
		dest_2++;
	}
	*dest_2 = '\0';
	return (dest);
}
