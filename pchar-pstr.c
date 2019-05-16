#include "monty.h"
/**
 * pchar - print the char at the top of the stack
 * @stack: stack
 * @line_number: line number in monty file
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
                exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * pstr - print the string starting at the top of the stack
 * @stack: stack
 * @line_number: line number in monty file
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp;
	/* if (*stack == NULL) */
	/* { */
	/* 	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number); */
        /*         exit(EXIT_FAILURE); */
	/* } */
	/* if ((*stack)->n < 0 || (*stack)->n > 127) */
	/* { */
	/* 	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number); */
	/* 	exit(EXIT_FAILURE); */
	/* } */

	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->n <= 0 || tmp->n > 127)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
