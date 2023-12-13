#include "main.h"

/**
 * _free_cmd - free a command struct
 *
 * @cmd: pointer to cmd
 */

void _free_cmd(t_cmd *cmd)
{
	_free_arr(cmd->av);
	free(cmd->cmd), cmd->cmd = NULL;
	free(cmd);
}
