#include "monty.h"

/**
 * my_pint - prints the top element
 * of a stack_t linked list.
 * @stack: pointer to the top node of the  list.
 * @line_number: current line number
 */
void my_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		fr_toks_fault(print_pinterror(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}

/**
 * print_pinterror - prints my_pint error on empty stacks.
 * @line_number: current line number.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int print_pinterror(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
