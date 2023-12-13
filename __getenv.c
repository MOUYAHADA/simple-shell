#include "main.h"

/**
 * _getenv - get enviroment variable value
 *
 * @var: given environment variable
 * @env_arr: array of environment variables
 *
 * Return: the value of @var if it exists
 */

char *_getenv(char *var, char **env_arr)
{
	char *var_cpy = NULL;
	char *var_value = NULL;
	char *var_key = NULL;
	int index = 0;

	while (env_arr[index])
	{
		var_cpy = _strdup(env_arr[index]);
		if (var_cpy == NULL)
			return (NULL);
		var_key = strtok(var_cpy, "=");
		if (_strcmp(var_key, var) == 0)
		{
			var_value = _strdup(strtok(NULL, "\n"));
			free(var_cpy);
			return (var_value);
		}
		free(var_cpy);
		index++;
	}
	return (NULL);
}
