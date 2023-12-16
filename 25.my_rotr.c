#include "monty.h"

/**
 * my_rotr - rotates the bottom value
 * to the top of a stack_t linked list
 * @stack: pointer to the top node.
 * @line_number: current line number.
 */
void my_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom, *top;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}
