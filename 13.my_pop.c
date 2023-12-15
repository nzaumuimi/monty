#include "monty.h"

/**
 * my_pop - removes a stack_t linked list
 * top element.
 * @stack: pointer to the top node.
 * @line_number: current line number.
 */
void my_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		fr_toks_fault(print_poperror(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
  * print_poperror - prints "pop" error message
  * on empty stacks.
  * @line_number: line number where the error occurred.
  *
  * Return: Always returns (EXIT_FAILURE).
  */
int print_poperror(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}
