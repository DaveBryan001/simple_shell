#include "simple_hell.h"

/**
 * read_input - reads user commands
 * @input: buffer to store command
 * @size: size of the buffer
 * Return: 0
 */

void read_input(char **input, size_t *size)
{
	ssize_t read_size;

	read_size = getline(input, size, stdin);

	printf("read: %ld\n",read_size);
	if (read_size == -1)
	{
		if (feof(stdin))
		{
			print_my("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			print_my("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	if ((*input)[read_size - 1] == '\n')
	{
		(*input)[read_size - 1] = '\0';
	}
}
