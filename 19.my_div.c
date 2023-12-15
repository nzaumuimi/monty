#include "monty.h"

/**
 * print_diverror - prints error message for div. by zero.
 * @line_number: line number where the error occurred.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int print_diverror(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * my_div - divides the top two values
 * of a stack_t linked list.
 * @stack: pointer to the top node
 * of a list.
 * @line_number: current line number.
 *
 * Description: function divides the second value by the top value
 * of the stack. The top value is removed
 * and the result is stored in the second value node.
 */
void my_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fr_toks_fault(briefstack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		fr_toks_fault(print_diverror(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	my_pop(stack, line_number);
}
