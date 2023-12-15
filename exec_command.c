#include "simple_hell.h"

/**
 * exec_user_command - executes command
 * Description - This function takes a shell command as input,
 * forks a new process, and
 * executes the command in the child process using execve. The parent process
 * waits for the child to complete execution.
 *
 *@input: command to be executed
 *@envp: environment variable
 *Return: no return
 */

void exec_user_command(const char *input, char *envp[])
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *args[256];
		char exec_path[1024] = "";
		int arg_count = 0;

		char *token = strtok((char *)input, " ");

		while (token != NULL && arg_count < 255)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		_strncat(exec_path, "/bin/", sizeof(exec_path));
		_strncat(exec_path, args[0], sizeof(exec_path));


		if (execve(exec_path, args, envp) == -1)
		{
			perror("execve: Command not found.\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
