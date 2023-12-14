#include "simple_hell.h"

/**
 * exec_user_command - executes command
 * Description - This function takes a shell command as input,
 * forks a new process, and
 * executes the command in the child process using execve. The parent process
 * waits for the child to complete execution.
 *
 *@input: command to be executed
 *Return: no return
 */

void exec_user_command(const char *input)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		print_my("Error forking process. \n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *args[170];

		int arg_count = 0;

		char *token = strtok((char *) input, " ");

		while (token != NULL & arg_count < 169)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		(execve(args[0], args, NULL) == -1);

		print_my(" Command not found.\n");
		exit(EXIT_FAILURE);

	}
	else
	{
		wait(NULL);
	}
}
