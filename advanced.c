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
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit_free(*stack);
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
/**
 * rotl - rotate the stack to the top
 * @stack: stack
 * @line_number: line number in monty file
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	int tmp;
	stack_t *ptr = *stack;

	if (*stack == NULL)
		return;
	tmp = (*stack)->n;
	while (ptr->next != NULL)
	{
		ptr->n = ptr->next->n;
		ptr = ptr->next;
	}
	ptr->n = tmp;
}
/**
 * rotr - rotate the stack to the top
 * @stack: stack
 * @line_number: line number in monty file
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	int tmp;
	stack_t *ptr = *stack;

	if (*stack == NULL)
		return;

	while (ptr->next != NULL)
		ptr = ptr->next;
	tmp = ptr->n;
	while (ptr->prev != NULL)
	{
		ptr->n = ptr->prev->n;
		ptr = ptr->prev;
	}
	ptr->n = tmp;
}
