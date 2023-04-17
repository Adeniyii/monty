#include "monty.h"

/**
 * main - check the code
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	stack_t *stack;
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	stack = NULL;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	parse_script(file, &stack);

	fclose(file);
	free_stack(stack);
	return (0);
}
