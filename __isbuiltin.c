#include "main.h"

/**
 * _isbuiltin - check if a command is built in
 *
 * @cmd: command
 *
 * Return: 1 if true, 0 otherwise
 */

int _isbuiltin(char *cmd)
{
	if (_strcmp(cmd, "exit") == 0)
		return (1);
	if (_strcmp(cmd, "env") == 0)
		return (1);
	if (_strcmp(cmd, "setenv") == 0)
		return (1);
	if (_strcmp(cmd, "unsetenv") == 0)
		return (1);

	return (0);
}
