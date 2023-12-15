#include "monty.h"

/**
  * monty_filefault - Displays fault message USAGE if
  * user doesn't give any file or more than 1 argument.
  *
  * Return: EXIT_FAILURE
  */
int monty_filefault(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
