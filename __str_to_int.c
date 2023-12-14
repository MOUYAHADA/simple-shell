#include "main.h"

/**
 * _string_to_int - convert string to number
 *
 * @str: string to convert
 *
 * Return: number
 */
int _string_to_int(const char *str)
{
	int result = 0;
	int sign = 1;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}

	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + (*str - '0');
		else
			return (0);
		str++;
	}

	return (result * sign);
}
