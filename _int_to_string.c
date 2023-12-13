#include "main.h"

/**
 * get_len - get number length
 *
 * @num: number
 *
 * Return: length of @num
 */

int get_len(int num)
{
	int length = 1;

	while (num /= 10)
	{
		length++;
	}

	return (length);
}

/**
 * _int_to_string - converts int to string
 *
 * @num: number to convert
 * @str: final string
 *
 */

void _int_to_string(int num, char *str)
{
	int length = get_len(num);
	int is_negative = 0, i;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
		length++;
	}

	for (i = length - 1; i >= is_negative; i--)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
	}

	if (is_negative)
	{
		str[0] = '-';
	}

	str[length] = '\0';
}
