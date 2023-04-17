#include "monty.h"

/**
 * get_handler - Returns the correct function to perform an operation.
 * @s: The operator passed.
 *
 * Return: A pointer to the appropriate function.
 */
void (*get_handler(char *token))(stack_t**, unsigned int)
{
	int i = 0;

	instruction_t ops_stack[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pchar", pchar},
		{"pstr", pstr},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"nop", nop},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", queue_handler},
		{"stack", stack_handler},
		{"#", nop},
		{NULL, NULL},
	};

	strip_newline(token);

	while (ops_stack[i].opcode != NULL)
	{
		if (strncmp(token, ops_stack[i].opcode, strlen(ops_stack[i].opcode)) == 0)
		{
			if (token[strlen(ops_stack[i].opcode)] == '\0')
				return (ops_stack[i].f);
			else if (token[0] == '#')
				return (ops_stack[i].f);
		}
		i++;
	}

	return (ops_stack[i].f);
}
