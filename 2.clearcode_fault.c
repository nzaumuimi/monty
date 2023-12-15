#include "monty.h"

/**
  * clearcode_fault - prints fault text if,
  * null instruction input.
  * @opcode: obtain line number where instruction executed.
  * @line_number: Monty file where the error appeared.
  *
  * Return: EXIT_FAILURE.
  */
int clearcode_fault(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
	return (EXIT_FAILURE);
}
