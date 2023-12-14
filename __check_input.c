#include "main.h"

/**
 * _check_input - checks the input and then executes it if possible
 *
 * @input: command as a full string
 * @av: argument vector
 * @status: pointer to status variable
 * @count: commands count
 *
 * Return: 0 on success, -1 on failure
 */

int _check_input(char *input, char **av, int *status, int count)
{
	t_cmd *cmd = NULL;

	if (strtok(input, "\n") == NULL)
	{
		free(input), input = NULL;
		return (-1);
	}
	cmd = _init_cmd(input);
	if (cmd == NULL)
	{
		free(input), input = NULL;
		return (-1);
	}
	if (_isbuiltin(cmd->cmd))
	{
		free(input);
		_execute_builtin(cmd);
		_free_cmd(cmd);
		return (-1);
	}
	if (access(cmd->cmd, F_OK | X_OK) == -1)
	{
		char *full_path = _get_joined_path(cmd);

		if (!full_path)
		{
			*status = 127;
			_print_error(av[0], count, cmd->av[0], "not found");
			_free_cmd(cmd);
			free(input), input = NULL;
			return (-1);
		}

		free(cmd->cmd);
		cmd->cmd = _strdup(full_path);
		free(full_path);
	}

	*status = _execute(input, cmd);
	return (0);
}
