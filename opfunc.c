#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = malloc(sizeof(stack_t)); /* not freed */
	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	tmp->n = globes.data;
	tmp->prev = NULL;
	tmp->next = NULL;
	if (*stack != NULL)
	{
		tmp->next = *stack;
		(*stack)->prev = tmp;
	}
	*stack = tmp;
}
void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	stack_t *tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
void pint(stack_t **stack, unsigned int line_number)
{
}
void pop(stack_t **stack, unsigned int line_number)
{
}
void swap(stack_t **stack, unsigned int line_number)
{
}
void add(stack_t **stack, unsigned int line_number)
{
}
void nop(stack_t **stack, unsigned int line_number)
{
}
