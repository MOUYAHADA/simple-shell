#include "main.h"

/**
 * _print_error - prints an error
 *
 * @program_name: name of the current program
 * @number: error number
 * @cmd: command
 * @error_msg: error message
 *
 */

void _print_error(char *program_name, int number, char *cmd, char *error_msg)
{
	char str[10];

	_int_to_string(number, str);
	(void)number;
	_write(STDERR_FILENO, program_name);
	_write(STDERR_FILENO, ": ");

	if (number >= 0)
	{
		_write(STDERR_FILENO, str);
		_write(STDERR_FILENO, ": ");
	}
	if (cmd != NULL)
	{
		_write(STDERR_FILENO, cmd);
		_write(STDERR_FILENO, ": ");
	}
	_write(STDERR_FILENO, error_msg);
	_write(STDERR_FILENO, "\n");
}
