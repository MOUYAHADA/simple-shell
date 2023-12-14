#include "main.h"

/**
 * main - simple shell clone main function
 *
 * @ac: argument count
 * @av: argument vector
 * @env: environment variables array
 *
 * Return: 0 on success
 */

int main(int ac, char **av, char **env)
{
	char *input = NULL;
	int status = 0, code, count = 0;

	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_write(STDOUT_FILENO, "$ ");
		input = _getline();
		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
				_write(STDOUT_FILENO, "\n");
			return (status);
		}
		count++;
		code = _check_input(input, av, &status, count);
		if (code == -1)
			continue;
		free(input);
	}
	return (status);
}
