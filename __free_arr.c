#include "main.h"

/**
 * _free_arr - free an array
 * @arr: array
 */

void _free_arr(char **arr)
{
	int i;

	if (arr == NULL)
		return;

	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]), arr[i] = NULL;
	}

	free(arr), arr = NULL;
}
