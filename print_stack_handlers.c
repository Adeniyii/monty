#include "monty.h"

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
 * pchar - print the value at the top of the stack, followed by a new line.
 *
 * @stack: the stack, represented as a pointer to a linked list
 * @line_number: current line number of file being parsed
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!stack || !head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (head->n > 127 || head->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", head->n);
}
