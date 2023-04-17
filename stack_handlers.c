#include "monty.h"

/**
 * push - push a new node to the stack
 *
 * @stack: the stack to push to, represented as a pointer to a linked list
 * @line_number: current line number of file being parsed
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack;
	stack_t *head = *stack;
	char *value_to_push;
	int value_to_push_int;

	value_to_push = strtok(NULL, " ");

	if (!value_to_push)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value_to_push_int = atoi(value_to_push);

	if (value_to_push[0] != '0' && value_to_push_int == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_stack = malloc(sizeof(stack_t));

	if (!new_stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (head)
		head->prev = new_stack;

	new_stack->prev = NULL;
	new_stack->next = head;
	new_stack->n = atoi(value_to_push);
	*stack = new_stack;
}

/**
 * pall - print the contents of the stack
 *
 * @stack: the stack to push to, represented as a pointer to a linked list
 * @line_number: current line number of file being parsed
*/
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
