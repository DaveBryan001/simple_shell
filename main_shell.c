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

		exec_user_command(input, envp);

		free(input);
	}

	return (0);
}
