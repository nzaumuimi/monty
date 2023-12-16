#include "monty.h"

/**
  * mallocfailed_fault - Outputs malloc failed when unable to malloc.
  *
  * Return: EXIT_FAILURE.
  */
int mallocfailed_fault(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
