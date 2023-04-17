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
