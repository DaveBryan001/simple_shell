#include "simple_hell.h"

/**
 * main - entry point
 *
 * Return: always 0.
 */

int main(void)
{
	char input[120];
	size_t size = 0;

	while (1)
	{
		my_prompt();
		read_input((char **)&input, &size);
		exec_user_command(input);

	/**
	 * if (strcmp(input, "exit") == 0)
		{
			print_my("Exiting the shell.\n");
			break;
		}
		else
		{
			print_my(" :No command found\n";
		}
	*/
	}



	return (0);
}