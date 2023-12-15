#include "monty.h"

/**
  * pushint_error - Prints error message if not an integer,
  * or no argument given to push.
  * @line_number: Monty file where error appeared.
  *
  * Return: EXIT_FAILURE.
  */
int pushint_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
