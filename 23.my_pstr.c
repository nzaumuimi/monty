#include "monty.h"

/**
 * my_pstr - outputs the stored string in the list.
 *
 * @stack: pointer to the top node.
 * @line_number: current line number.
 */
void my_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}
