#include "monty.h"
/**
 * opcomp - check command in dictionary
 * @opcode: the string name that is extracted by sscanf from getline
 *
 * Return: function pointer or null if no match
 */
void opcomp(stack_t **stack, unsigned int line_number, char *opcode)
{
	int index = 0;

	instruction_t opc[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"nop", nop}, {NULL, NULL}
	};

	while (opc[index].opcode != NULL)
	{
		if (strcmp(opcode, opc[index].opcode) == 0)
		{
			opc[index].f(stack, line_number);
			return;
		}
		index++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
