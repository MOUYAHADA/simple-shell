#include "main.h"

/**
 * _execute - executes a program
 *
 * @input: full input
 * @cmd: command
 *
 * Return: exit status of child process
 */

int _execute(char *input, t_cmd *cmd)
{
	pid_t child_PID;
	int status;

	child_PID = fork();

	if (child_PID == 0)
	{
		if (execve(cmd->cmd, cmd->av, cmd->env))
		{
			_free_cmd(cmd);
			free(input), input = NULL;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_PID, &status, 0);
		_free_cmd(cmd);
	}
	return (WEXITSTATUS(status));
}
