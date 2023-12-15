#include "monty.h"
#include <string.h>
#include <stdio.h>

int enact_monty(FILE *script_fd);

/**
 * release_memory - Reallocates the memory used by the
 * global op_toks array of strings.
 *
 * Returns: void
 */
void release_memory(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;
	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * tokarray_string - Obtains the length of the current op_toks.
 *
 * Return: Length of the current op_toks (as an integer).
 */
unsigned int tokarray_string(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * devoid_line - The function confirms if a line,
 * got from getline,holds only delimiter characters.
 *
 * @line: A pointer to the line to be checked.
 * @delims: A string of delimiter characters.
 *
 * Return: 1 if the line consists solely of delimiters,0 otherwise.
 */
int devoid_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; delims[j]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}
	return (1);
}

/**
 * process_func - Obtains the function similar
 * to a given opcode.
 *
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the similar function.
 */
void (*process_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", my_pint},
		{"pop", my_pop},
		{"swap", my_swap},
		{"add", my_add},
		{"nop", my_nop},
		{"sub", my_sub},
		{"div", my_div},
		{"mul", my_mul},
		{"mod", my_mod},
		{"pchar", my_pchar},
		{"pstr", my_pstr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}
	return (NULL);
}

/**
 * enact_monty - Main function for implementing a
 * Monty bytecode script.
 *
 * @script_fd: File explanation for an open Monty bytecode script.
 *
 * Return: Returns EXIT_SUCCESS on success,
 * or the correct fault code on failure.
 */
int enact_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (execute_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		op_toks = tok_str(line, DELIMS);
		if (op_toks == NULL)
		{
			if (devoid_line(line, DELIMS))
				continue;
			unpack_stack(&stack);
			return (mallocfailed_fault());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			release_memory();
			continue;
		}
		op_func = process_func(op_toks[0]);
		if (op_func == NULL)
		{
			unpack_stack(&stack);
			exit_status = clearcode_fault(op_toks[0], line_number);
			release_memory();
			break;
		}
		prev_tok_len = tokarray_string();
		op_func(&stack, line_number);
		if (tokarray_string() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			release_memory();
			break;
		}
		release_memory();
	}
	unpack_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (mallocfailed_fault());
	}

	free(line);
	return (exit_status);
}
