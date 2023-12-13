#include "main.h"

/**
 * _get_joined_path - get full path for command if it exists
 *
 * @cmd: command
 *
 * Return: full path of command if it exists, otherwise NULL
 */

char *_get_joined_path(t_cmd *cmd)
{
	char *PATH;
	char *DIR;
	struct stat st;

	if (cmd == NULL)
		return (NULL);

	if (_ispath(cmd->cmd))
		return (NULL);
	PATH = _getenv("PATH", cmd->env);
	if (PATH == NULL)
		return (NULL);
	DIR = strtok(PATH, ":");
	while (DIR != NULL)
	{
		char *full_path;

		full_path = malloc(sizeof(char) * (_strlen(DIR) + _strlen(cmd->cmd) + 2));
		if (full_path == NULL)
			return (NULL);
		_strcpy(full_path, DIR);
		_strcat(full_path, "/");
		_strcat(full_path, cmd->cmd);

		if (stat(full_path, &st) == 0)
		{
			free(PATH), PATH = NULL;
			return (full_path);
		}
		free(full_path);
		DIR = strtok(NULL, ":");
	}

	free(PATH);

	return (NULL);
}
