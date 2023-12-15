#include "monty.h"

void _push(stack_t **stack, unsigned int line_number);

/**
  * _push - Inserts a value into a stack_t linked list.
  * @stack: pointer to the topmost node of a stack_t linked list.
  * @line_number: current line number in the Monty file.
  */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fr_toks_fault(mallocfailed_fault());
		return;
	}

	if (op_toks[1] == NULL)
	{
		fr_toks_fault(pushint_error(line_number));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			fr_toks_fault(pushint_error(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (test_mode(*stack) == STACK)
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * _pall - Prints the values of a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}
