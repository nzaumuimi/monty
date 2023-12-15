#include "monty.h"

/**
 * fr_toks_fault - Places the last component of fr_toks_fault to an error code.
 *
 * @error_code: Int to be stored as a string in fr_toks_fault.
 */
void fr_toks_fault(int error_code)
{
	int toks_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = tokarray_string();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		mallocfailed_fault();
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		mallocfailed_fault();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
