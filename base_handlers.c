#include "monty.h"

/**
 * push - push a new node to the stack
 *
 * @stack: the stack to push to, represented as a pointer to a linked list
 * @line_number: current line number of file being parsed
*/
void push(stack_t **stack, unsigned int line_number)
{
	char *value_to_push, *endptr;
	int value_to_push_int;

	value_to_push = strtok(NULL, " ");

	if (!value_to_push)
		throw_usage_error(line_number);

	value_to_push_int = strtol(value_to_push, &endptr, 10);
	strip_newline(endptr);

	if (*endptr != '\0' || endptr == value_to_push)
		throw_usage_error(line_number);

	handle_stack_insert(stack, value_to_push_int);
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

/**
 * swap - swap the two top elements of the stack.
 *
 * @stack: the stack, represented as a pointer to a linked list
 * @line_number: current line number of file being parsed
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *after_head;

	if (!head || !stack)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	after_head = head->next;

	if (!after_head)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	head->next = after_head->next;
	head->prev = after_head;

	after_head->prev = NULL;
	after_head->next = head;

	*stack = after_head;
}

/**
 * rotl - rotate the stack to the top.
 * The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
 *
 * @stack: the stack, represented as a pointer to a linked list
 * @line_number: current line number of file being parsed
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;
	stack_t *tmp = *stack;

	if (head && head->next)
	{
		while (tmp)
		{
			if (!tmp->next)
			{
				*stack = head->next;
				head->next->prev = NULL;

				head->next = NULL;
				head->prev = tmp;

				tmp->next = head;
				break;
			}
			tmp = tmp->next;
		}
	}
}

/**
 * rotr - rotate the stack to the bottom,
 * the last element of the stack becomes the first.
 *
 * @stack: the stack, represented as a pointer to a linked list
 * @line_number: current line number of file being parsed
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp = *stack;
	stack_t *head = *stack;

	if (tmp && tmp->next)
	{
		while (tmp)
		{
			if (!tmp->next)
			{

				tmp->prev->next = NULL;
				tmp->next = head;
				tmp->prev = NULL;
				head->prev = tmp;

				*stack = tmp;
				break;
			}
			tmp = tmp->next;
		}
	}
}
