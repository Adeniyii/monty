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
	char *value_to_push, *endptr;
	int value_to_push_int;

	value_to_push = strtok(NULL, " ");

	if (!value_to_push)
		throw_usage_error(line_number);

	value_to_push_int = strtol(value_to_push, &endptr, 10);
	strip_newline(endptr);

	if (*endptr != '\0')
		throw_usage_error(line_number);

	if (value_to_push[0] == '-')
		value_to_push_int = value_to_push_int * -1;
	else if (value_to_push[0] != '0' && value_to_push_int == 0)
		throw_usage_error(line_number);

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
	new_stack->n = value_to_push_int;
	*stack = new_stack;
}

/**
 * pall - print the contents of the stack
 *
 * @stack: the stack, represented as a pointer to a linked list
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

/**
 * pint - print the value at the top of the stack, followed by a new line.
 *
 * @stack: the stack, represented as a pointer to a linked list
 * @line_number: current line number of file being parsed
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!stack || !head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->n);
}

/**
 * pop - remove the value at the top of the stack.
 *
 * @stack: the stack, represented as a pointer to a linked list
 * @line_number: current line number of file being parsed
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!stack || !head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = head->next;

	if (head->next)
		head->next->prev = NULL;

	free(head);
}
