#include "monty.h"

/**
 * parse_script - parse the monty file
 * @file: file to read from
 * @stack: stack data structure to work with
 */
void parse_script(FILE *file, stack_t **stack)
{
	char buffer[1024], *token;
	unsigned int line_number;
	void (*handler)(stack_t **stack, unsigned int line_number);

	line_number = 0;

	while (fgets(buffer, sizeof(buffer), file))
	{
		line_number++;

		while (1)
		{
			token = strtok(buffer, " ");

			if (!token)
				break;

			handler = get_handler(token);

			if (handler)
			{
				handler(stack, line_number);
				break;
			}

			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}
	}
}
