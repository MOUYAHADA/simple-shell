#include "main.h"
/**
 * _exit_program - exits program
 *
 * @cmd: command
 */
void _exit_program(t_cmd *cmd)
{
	_free_cmd(cmd);
	exit(EXIT_SUCCESS);
}

/**
 * _print_env - print environment variables
 *
 */

void _print_env(void)
{
	int index = 0;

	if (!environ || !environ[0])
		return;

	while (environ[index])
	{
		_write(STDOUT_FILENO, environ[index]);
		_write(STDOUT_FILENO, "\n");
		index++;
	}
}

/**
 * _execute_builtin - execute builtin commands
 *
 * @cmd: command
 */

void _execute_builtin(t_cmd *cmd)
{
	if (_strcmp(cmd->cmd, "exit") == 0)
		_exit_program(cmd);
	if (_strcmp(cmd->cmd, "env") == 0)
		_print_env();
}
