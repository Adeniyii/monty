#include "monty.h"

/**
 * nop - do nothing.
 *
 * @stack: the stack, represented as a pointer to a linked list
 * @line_number: current line number of file being parsed
 */
void nop(stack_t **stack __attribute__((unused)),
	unsigned int line_number __attribute__((unused)))
{}

/**
 * queue_handler - set structure mode to queue.
 *
 * @stack: the stack, represented as a pointer to a linked list
 * @line_number: current line number of file being parsed
 */
void queue_handler(stack_t **stack __attribute__((unused)),
	unsigned int line_number __attribute__((unused)))
{
	structure_mode = "queue";
}

/**
 * stack_handler - set structure mode to stack.
 *
 * @stack: the stack, represented as a pointer to a linked list
 * @line_number: current line number of file being parsed
 */
void stack_handler(stack_t **stack __attribute__((unused)),
	unsigned int line_number __attribute__((unused)))
{
	structure_mode = "stack";
}
