#include "monty.h"

/**
 * add - add the two top elements of the stack.
 *
 * @stack: the stack, represented as a pointer to a linked list
 * @line_number: current line number of file being parsed
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *after_head;

	if (!head || !stack)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	after_head = head->next;

	if (!after_head)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	after_head->prev = NULL;
	after_head->n = after_head->n + head->n;

	*stack = after_head;
	free(head);
}

/**
 * sub - sub the two top elements of the stack.
 *
 * @stack: the stack, represented as a pointer to a linked list
 * @line_number: current line number of file being parsed
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *after_head;

	if (!head || !stack)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	after_head = head->next;

	if (!after_head)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	after_head->prev = NULL;
	after_head->n = after_head->n - head->n;

	*stack = after_head;
	free(head);
}

/**
 * div - div the two top elements of the stack.
 *
 * @stack: the stack, represented as a pointer to a linked list
 * @line_number: current line number of file being parsed
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *after_head;

	if (!head || !stack)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	after_head = head->next;

	if (!after_head)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	after_head->prev = NULL;
	after_head->n = after_head->n / head->n;

	*stack = after_head;
	free(head);
}

/**
 * mul - mul the two top elements of the stack.
 *
 * @stack: the stack, represented as a pointer to a linked list
 * @line_number: current line number of file being parsed
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *after_head;

	if (!head || !stack)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	after_head = head->next;

	if (!after_head)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	after_head->prev = NULL;
	after_head->n = after_head->n * head->n;

	*stack = after_head;
	free(head);
}

/**
 * mod - mod the two top elements of the stack.
 *
 * @stack: the stack, represented as a pointer to a linked list
 * @line_number: current line number of file being parsed
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *after_head;

	if (!head || !stack)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	after_head = head->next;

	if (!after_head)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	after_head->prev = NULL;
	after_head->n = after_head->n % head->n;

	*stack = after_head;
	free(head);
}
