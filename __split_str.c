#include "main.h"

/**
 * _split_str - splits a string to tokens
 *
 * @input: string to split
 * @delim: delimiter
 * @token_count: number of tokens
 *
 * Return: array of strings containing tokens, or NULL on failure
 */

char **_split_str(char *input, const char *delim, int *token_count)
{
	char *input_dup = NULL;
	char *token = NULL;
	char **arr = NULL;
	int count = 0, index = 0;

	input_dup = _strdup(input);
	if (input_dup == NULL)
		return (NULL);
	token = strtok(input_dup, delim);
	if (token == NULL)
	{
		free(input_dup);
		return (NULL);
	}
	while (token != NULL) /* count the number of tokens in the string */
	{
		count++;
		token = strtok(NULL, delim);
	}
	if (token_count != NULL) /* export token count if argument is set */
		*token_count = count;
	arr = malloc(sizeof(char *) * (count + 1));
	if (arr == NULL)
	{
		free(input_dup);
		return (NULL);
	}
	free(input_dup);
	input_dup = _strdup(input);
	token = strtok(input_dup, delim);
	while (token != NULL) /* assign tokens to array */
	{
		arr[index] = _strdup(token);
		token = strtok(NULL, delim);
		index++;
	}
	arr[index] = NULL; /* nullify last item in array */
	free(input_dup);
	return (arr);
}
