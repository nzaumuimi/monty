#include "monty.h"

/**
 * my_stack - change a queue to a stack.
 * @stack: pointer to the top node.
 * @line_number: current line number.
 */
void my_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * my_queue - change a stack to a queue.
 * @stack: pointer to the top node.
 * @line_number: current line number.
 */
void my_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
