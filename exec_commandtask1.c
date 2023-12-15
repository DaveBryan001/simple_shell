#include "simple_hell.h"

/**
 * exec_user_command_task1 - executes command
 * Description - This function takes a shell command as input,
 * forks a new process, and
 * executes the command in the child process using execve. The parent process
 * waits for the child to complete execution.
 *
 *@input: command to be executed
 *@envp: environment variable
 *Return: no return
 */

void exec_user_command_task1(const char *input, char *envp[])
{
	pid_t child_pid = fork();

	char *args[256];
	char error_msg[256] = "";
	if (child_pid == -1)
	{
		perror("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		int arg_count = 0;
		int i;

		char *token = strtok((char *)input, " ");
		size_t dest_len = 0;

		while (token != NULL && arg_count < 255)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		/*
		 *  Handling error message construction
		 */

		_strncat(error_msg, "davebryan@penguin$", sizeof(error_msg));
		_strncat(error_msg, ": ", sizeof(error_msg));

		for (i = 0; i < arg_count; ++i)
		{
			_strncat(error_msg + dest_len, args[i], sizeof(error_msg) - dest_len);
			dest_len += strlen(args[i]);
			if (i < arg_count - 1)
			{
				_strncat(error_msg + dest_len, " ", sizeof(error_msg) - dest_len);
				dest_len++;
			}
		}

		_strncat(error_msg + dest_len, ": not found", sizeof(error_msg) - dest_len);
		_strncat(error_msg, "\n", sizeof(error_msg));

		if (arg_count != 1)
		{
			write(STDERR_FILENO, error_msg, sizeof(error_msg) - 1);
			exit(EXIT_FAILURE);
		}

		if (execve(args[0], args, envp) == -1)
		{

			write(STDERR_FILENO, error_msg, sizeof(error_msg) - 1);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
