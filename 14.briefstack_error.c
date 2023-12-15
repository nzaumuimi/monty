#include "monty.h"

/**
 * briefstack_error - Prints error messages for Monty math
 * functions when stacks/queues have fewer than two nodes.
 *
 * @line_number: Line number in the Monty bytecode file
 * where the error occurred.
 *
 * @op: Operation where the error occurred.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int briefstack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}
