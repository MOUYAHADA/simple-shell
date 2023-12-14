#include "main.h"

/**
 * _arr_len - calculates array length
 *
 * @arr: array
 *
 * Return: length of @arr
 */

int _arr_len(char **arr)
{
	int len = 0;

	if (!arr)
		return (len);
	while (arr[len])
		len++;
	return (len);
}
