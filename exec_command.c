#include "simple_hell.h"

/**
 * exec_user_command - executes command
 * Description - This function takes a shell command as input,
 * forks a new process, and executes the command in the child process
 * using execve. The parent process waits for the child to complete execution.
 *
 * @input: command to be executed
 * @envp: environment variable
 * Return: no return
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
		char *args[2];
		args[0] = (char *)input;
		args[1] = NULL;

		if (execve(args[0], args, envp) == -1)
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
