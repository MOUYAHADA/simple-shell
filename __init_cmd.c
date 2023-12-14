#include "main.h"

/**
 * _init_cmd - initialize a command
 *
 * @input: full input
 *
 * Return: a command struct
 */

t_cmd *_init_cmd(char *input)
{
	t_cmd *cmd = NULL;

	if (input == NULL)
		return (NULL);

	cmd = malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);

	cmd->av = _split_str(input, " \t\n", &cmd->ac);
	if (cmd->av == NULL)
	{
		free(cmd);
		return (NULL);
	}
	cmd->cmd = _strdup(cmd->av[0]);

	return (cmd);
}
