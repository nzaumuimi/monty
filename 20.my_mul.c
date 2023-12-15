#include "monty.h"

/**
 * my_mul - multiplies the top two values
 * of a stack_t linked list.
 * @stack: pointer to the top node.
 * @line_number: current line number
 *
 * Description: function multiplies the top two values
 * of the stack. The top value is removed after the result is stored
 * in the second value node.
 */
void my_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fr_toks_fault(briefstack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	my_pop(stack, line_number);
}
