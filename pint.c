#include "monty.h"
/**
 *
 *
 *
 **/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if(tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}
