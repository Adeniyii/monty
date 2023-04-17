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

/**
 * handle_stack_insert - insert a new node into the stack
 *
 * @stack: the stack to insert into
 * @value_to_push_int: the value to insert
*/
void handle_stack_insert(stack_t **stack, int value_to_push_int)
{
	stack_t *new_stack;
	stack_t *head = *stack;

	new_stack = malloc(sizeof(stack_t));

	if (!new_stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_stack->n = value_to_push_int;

	if (strcmp(structure_mode, "queue") == 0)
	{
		new_stack->next = NULL;

		if (!head)
		{
			new_stack->prev = NULL;
			*stack = new_stack;
			return;
		}

		while (head)
		{
			if (!head->next)
			{
				new_stack->prev = head;
				head->next = new_stack;
				break;
			}
			head = head->next;
		}
	}
	else
	{
		if (head)
			head->prev = new_stack;

		new_stack->prev = NULL;
		new_stack->next = head;
		*stack = new_stack;
	}
}
