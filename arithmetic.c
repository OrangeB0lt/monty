#include "monty.h"
/**
 * add - add two nodes remove the top node and place sum in new
 * @stack: dll stack
 * @line_number: line num
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = a + b;
}
/**
 * sub - sub two nodes remove the top node and place sum in new
 * @stack: dll stack
 * @line_number: line num
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = b - a;
}
/**
 * divide - div two nodes remove the top node and place sum in new
 * @stack: dll stack
 * @line_number: line num
 *
 * Return: void
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	if (a == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	b = (*stack)->next->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = b / a;
}
/**
 * mul - mul two nodes remove the top node and place sum in new
 * @stack: dll stack
 * @line_number: line num
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = b * a;
}
/**
 * mod - mod two nodes remove the top node and place sum in new
 * @stack: dll stack
 * @line_number: line num
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	if (a == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	b = (*stack)->next->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = b % a;
}
