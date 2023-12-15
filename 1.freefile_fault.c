#include "monty.h"

/**
  * freefile_fault - prints cannot free file error text,
  * @filename: will be the name of the file that failed to free
  *
  *Return: EXIT_FAILURE
  */
int freefile_fault(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}
