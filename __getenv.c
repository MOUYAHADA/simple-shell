#include "main.h"

/**
 * _getenv - get enviroment variable value
 *
 * @var: given environment variable
 *
 * Return: the value of @var if it exists
 */

char *_getenv(char *var)
{
	char *var_cpy = NULL;
	char *var_value = NULL;
	char *var_key = NULL;
	int index = 0;

	if (!environ || !environ[0])
		return (NULL);

	while (environ[index])
	{
		var_cpy = _strdup(environ[index]);
		if (var_cpy == NULL)
			return (NULL);
		var_key = strtok(var_cpy, "=");
		if (_strcmp(var_key, var) == 0)
		{
			var_value = _strdup(strtok(NULL, "\n"));
			if (var_value == NULL)
			{
				free(var_cpy);
				return (NULL);
			}
			free(var_cpy);
			return (var_value);
		}
		free(var_cpy);
		index++;
	}
	return (NULL);
}
