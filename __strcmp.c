#include "main.h"

/**
 * _strcmp - compares two strings and returns an int
 *
 * @str1: first string
 * @str2: second string
 *
 * Return: the difference of first different char
 */

int _strcmp(char *str1, char *str2)
{
	if (_strlen(str1) > _strlen(str2))
	{
		while (*str1 != '\0')
		{
			if (*str1 < *str2 || *str1 > *str2)
			{
				return ((int)(*str1 - *str2));
			}
			if (*str1 != '\0')
				str1++;
			if (*str2 != '\0')
				str2++;
		}
	}
	else
	{
		while (*str2 != '\0')
		{
			if (*str1 < *str2 || *str1 > *str2)
			{
				return ((int)(*str1 - *str2));
			}
			if (*str1 != '\0')
				str1++;
			if (*str2 != '\0')
				str2++;
		}
	}
	return (0);
}
