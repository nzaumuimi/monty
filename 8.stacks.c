#include "monty.h"
#include <string.h>

/**
 * unpack_stack - Deallocates memory for a stack_t.
 *
 * @stack: Pointer to the top (stack) or
 * bottom (queue) of a stack_t.
 */
void unpack_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
			free(*stack);
		*stack = tmp;
	}
}

/**
 * execute_stack - Initializes a stack_t stack with initial
 * stack and terminal queue nodes.
 *
 * @stack: A pointer to an uninitialized stack_t stack.
 *
 * Return: Returns EXIT_FAILURE if an error occurs.
 * Otherwise, returns EXIT_SUCCESS.
 */
int execute_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (mallocfailed_fault());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * test_mode - Determines if a stack_t linked
 * list is in stack or queue mode.
 *
 * @stack: A pointer to the top (stack) or
 * bottom (queue) of a stack_t linked list.
 *
 * Return: Returns STACK (0) if the stack_t is in stack mode,
 * QUEUE (1) if it is in queue mode, and 2 otherwise.
 */
int test_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
