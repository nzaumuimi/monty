#include "monty.h"

/**
 * print_pcharerror - prints error messages for pchar.
 * @line_number: line number where the error occurred.
 * @message: error message to print.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int print_pcharerror(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}

/**
 * my_pchar - outputs the char stored in the top value
 * node of the.
 *
 * @stack: pointer to the top node.
 * @line_number: current line number.
 */
void my_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		fr_toks_fault(print_pcharerror(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		fr_toks_fault(print_pcharerror(line_number,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}
