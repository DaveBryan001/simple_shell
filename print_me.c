#include "simple_hell.h"

/**
 * print_my - prints text to stdout
 * @my_text: pointer to string
 * Return: no return
 */

void print_my(const char *my_text)
{
	write(STDOUT_FILENO, my_text, strlen(my_text));
}

