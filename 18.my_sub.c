#include "monty.h"

/**
 * my_sub - subtracts the top two values of a list.
 * @stack: pointer to the top node.
 * @line_number: current line number.
 *
 * Description: subtracts a stacks top value from the
 * second value. The top value is removed
 * and the result is stored in the second value node.
 */
void my_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fr_toks_fault(briefstack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	my_pop(stack, line_number);
}
