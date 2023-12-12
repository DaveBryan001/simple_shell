#include "simple_hell.h"

void print_me(const char *my_text)
{
	write(STDOUT_FILENO, text, strlen(my_text));
}
