#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

/**
 * struct s_cmd - command type
 *
 * @cmd:  name of the command
 * @av:  argument vector
 * @ac: argument count
 *
 */

typedef struct s_cmd
{
	char *cmd;
	char **av;
	int ac;
} t_cmd;

void _free_arr(char **arr);
t_cmd *_init_cmd(char *input);
char *_getline(void);
char *_strdup(const char *str);
size_t _strlen(const char *str);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *src);
void _write(int FD, const char *str);
int _execute(char *input, t_cmd *cmd);
char *_getenv(char *var);
void _free_cmd(t_cmd *cmd);
char **_split_str(char *input, const char *delim, int *token_count);
int _check_input(char *input, char **av, int *status, int count);
char *_get_joined_path(t_cmd *cmd);
char *_strcpy(char *dest, char *src);
void _print_error(char *program_name, int number, char *cmd, char *error_msg);
void _int_to_string(int num, char *str);
int _ispath(char *str);
int _isbuiltin(char *cmd);
void _execute_builtin(t_cmd *cmd);

#endif
