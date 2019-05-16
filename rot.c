#include "monty.h"
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
