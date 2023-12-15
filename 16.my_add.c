#include "monty.h"

/**
 * my_add - adds a stack_t linked list
 * top two values
 * @stack: pointer to the top node
 * @line_number: current line number
 *
 * Description: the top value is removed and the result
 * is stored in the second value node from the top
 */
void my_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fr_toks_fault(briefstack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	my_pop(stack, line_number);
}
