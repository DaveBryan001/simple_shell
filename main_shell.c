#include "simple_hell.h"

/**
 * main - entry point
 *
 * Return: always 0.
 */

int main(void)
{
	char *input = NULL;
	size_t size = 0;

	char *envp[] = {NULL};

	while (1)
	{
		my_prompt();
		read_input(&input, &size);

		/*	exec_user_command(input, envp);
		*/
		if (_strcmp(input, "exit") == 0) 
		{
			print_my("Exiting the shell.\n");
			break;
		}
		exec_user_command_task1(input, envp);
		free(input);
	}

	return (0);
}
