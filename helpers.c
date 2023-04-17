#include "monty.h"

/**
 * free_stack - Frees all memory used by the stack
 *
 * @stack: the stack to free
*/
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

/**
 * strip_newline - remove newline from string
 *
 * @str: string to edit
 */
void strip_newline(char *str)
{
	int i;
	int len = strlen(str);

	for (i = 0; i < len; i++)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
	}
}

/**
 * throw_usage_error - throw an error for wrong usage
 *
 * @line_number: line in file where error occurred
 */
void throw_usage_error(int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
