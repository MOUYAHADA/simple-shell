#include "main.h"

/**
 * _getline - get user input
 *
 * Return: line of input or NULL on EOF
 */

char *_getline(void)
{
	char *input = NULL;
	size_t inputSize = 0;

	if (getline(&input, &inputSize, stdin) == -1)
	{
		free(input);
		return (NULL);
	}
	return (input);
}
