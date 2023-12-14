#include "main.h"

/**
 * main - simple shell clone main function
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	char *input = NULL;
	int status = 0, code, count = 0;
	int env_len = _arr_len(environ);
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_write(STDOUT_FILENO, "$ ");
		input = _getline();
		if (input == NULL)
		{

			while (environ[env_len])
				free(environ[env_len++]);
			if (isatty(STDIN_FILENO))
				_write(STDOUT_FILENO, "\n");
			return (status);
		}
		count++;
		code = _check_input(input, av, &status, count, env_len);
		if (code == -1)
			continue;
		free(input);
	}
	while (environ[env_len])
		free(environ[env_len++]);
	return (status);
}
