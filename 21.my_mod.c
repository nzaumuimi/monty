#include "monty.h"

/**
 * my_mod - calculates the modulus
 * of the top two values on a stack_t linked list.
 * @stack: pointer to the top node.
 * @line_number: current line number.
 *
 * Description: function computes the modulus of the second value
 * from the top of the stack by the top value. The top value is removed
 * after the result is stored in the second value node.
 */
void my_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fr_toks_fault(briefstack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		fr_toks_fault(print_diverror(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	my_pop(stack, line_number);
}
