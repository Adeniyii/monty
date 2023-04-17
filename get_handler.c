#include "monty.h"

/**
 * get_handler - Returns the correct function to perform an operation.
 * @s: The operator passed.
 *
 * Return: A pointer to the appropriate function.
 */
void (*get_handler(char *s))(stack_t**, unsigned int)
{
	int i = 0;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pchar", pchar},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"nop", nop},
		{"#", nop},
		{NULL, NULL},
	};

	strip_newline(s);

	while (ops[i].opcode != NULL)
	{
		if (strncmp(s, ops[i].opcode, strlen(ops[i].opcode)) == 0)
		{
			if (s[strlen(ops[i].opcode)] == '\0')
				return (ops[i].f);
			else if (s[0] == '#')
				return (ops[i].f);
		}
		i++;
	}

	return (ops[i].f);
}
