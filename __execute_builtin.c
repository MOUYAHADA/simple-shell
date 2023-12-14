#include "main.h"
/**
 * _exit_program - exits program
 *
 * @cmd: command
 * @status: exit status
 * @i: environ length
 */

void _exit_program(t_cmd *cmd, int *status, int i)
{
	if (_strlen(cmd->av[1]) > 0)
		*status = _string_to_int(cmd->av[1]);

	while (environ[i])
		free(environ[i++]);
	_free_cmd(cmd);
	exit(*status);
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
		if (environ[index][0] != '\0')
		{
			_write(STDOUT_FILENO, environ[index]);
			_write(STDOUT_FILENO, "\n");
		}
		index++;
	}
}

/**
 * _setenv - set an evnironment variable
 *
 * @cmd: command
 */

void _setenv(t_cmd *cmd)
{
	int index = 0;

	if (_strlen(cmd->av[1]) == 0 || _strlen(cmd->av[2]) == 0)
		return;

	while (environ[index])
	{
		char *copy = _strdup(environ[index]);

		if (!copy)
			break;
		if (_strcmp(strtok(copy, "="), cmd->av[1]) == 0)
		{
			free(copy);
			_strcpy(environ[index], cmd->av[1]);
			_strcat(environ[index], "=");
			if (cmd->av[2])
				_strcat(environ[index], cmd->av[2]);
			return;
		}
		free(copy);
		index++;
	}
	index = 0;
	while (environ[index])
		index++;
	environ[index] = malloc(sizeof(char) *
			(_strlen(cmd->av[1]) + _strlen(cmd->av[2]) + 2));
	_strcpy(environ[index], cmd->av[1]);
	_strcat(environ[index], "=");
	if (cmd->av[2])
		_strcat(environ[index], cmd->av[2]);
	environ[index + 1] = NULL;
}


/**
 * _unsetenv - unset an evnironment variable
 *
 * @cmd: command
 */


void _unsetenv(t_cmd *cmd)
{
	int index = 0;

	if (_strlen(cmd->av[1]) == 0)
		return;
	while (environ[index])
	{
		char *copy = _strdup(environ[index]);

		if (!copy)
			return;
		if (_strcmp(strtok(copy, "="), cmd->av[1]) == 0)
		{
			free(copy);
			environ[index][0] = '\0';
			return;
		}
		free(copy);
		index++;
	}
}
/**
 * _execute_builtin - execute builtin commands
 *
 * @cmd: command
 * @status: exit status
 * @env_len: environ length
 */

void _execute_builtin(t_cmd *cmd, int *status, int env_len)
{
	if (_strcmp(cmd->cmd, "exit") == 0)
		_exit_program(cmd, status, env_len);
	if (_strcmp(cmd->cmd, "env") == 0)
		_print_env();
	if (_strcmp(cmd->cmd, "setenv") == 0)
		_setenv(cmd);
	if (_strcmp(cmd->cmd, "unsetenv") == 0)
		_unsetenv(cmd);
}
