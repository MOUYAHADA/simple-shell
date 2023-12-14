#include "main.h"

/**
 * _strdup - duplicate a string
 *
 * @str: string
 *
 * Return: new str_cpy of @str
 */

char *_strdup(const char *str)
{
	int i;
	char *str_cpy;

	if (_strlen(str) == 0)
		return (NULL);

	str_cpy = malloc(sizeof(char) * (_strlen(str) + 1));

	if (str_cpy == NULL)
		return (NULL);

	i = 0;
	while (str[i])
	{
		str_cpy[i] = str[i];
		i++;
	}
	str_cpy[i] = '\0';

	return (str_cpy);
}
