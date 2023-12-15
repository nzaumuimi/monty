#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* 1.montyfile_error.c prototpes */
int monty_filefault(void);

/* 2.openfile_error.c prototpes */
int freefile_fault(char *filename);

/* 3.opcode_error.c prototpes */
int clearcode_fault(char *opcode, unsigned int line_number);

/* 4.mallocfailed_error.c prototpes */
int mallocfailed_fault(void);

/* 5.op_toks_error.c prototpes */
void fr_toks_fault(int error_code);

/* 6.string_converter.c prototpes */
char *get_int(int num);
unsigned int my_abs(int i);
int numbase_length(unsigned int num, unsigned int base);
void fill_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);
/* 7.string_tokenizer.c prototpes */
char **tok_str(char *str, char *delims);
int _delimeter(char ch, char *delims);
int token_length(char *str, char *delims);
int token_count(char *str, char *delims);
char *next_token(char *str, char *delims);

/* 8.stacks prototpes */
void unpack_stack(stack_t **stack);
int execute_stack(stack_t **stack);
int test_mode(stack_t *stack);

/* 9.execute_monty prototpes */
void free_memory(void);
unsigned int tokarray_string(void);
int enact_monty(FILE *script_fd);
int empty_line(char *line, char *delims);
void (*process_func(char *opcode))(stack_t**, unsigned int);

/* 10.pushinteger_error.c prototpes */
int pushint_error(unsigned int line_number);

/* 11.push_pall.c prototpes */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);

/* 12.my_pint.c prototpes */
int print_pinterror(unsigned int line_number);
void my_pint(stack_t **stack, unsigned int line_number);

/* 13.my_pop.c prototpes */
void my_pop(stack_t **stack, unsigned int line_number);
int print_poperror(unsigned int line_number);

/* 14.briefstack.c prototpes */
int briefstack_error(unsigned int line_number, char *op);

/* 15.my_swap.c prototpes */
void my_swap(stack_t **stack, unsigned int line_number);

/* 16.my_add.c prototpes */
void my_add(stack_t **stack, unsigned int line_number);

/* 17.my_nop.c prototpes */
void my_nop(stack_t **stack, unsigned int line_number);

/* 18.my_sub.c prototpes */
void my_sub(stack_t **stack, unsigned int line_number);

/* 19.my_div.c prototpes */
void my_div(stack_t **stack, unsigned int line_number);
int print_diverror(unsigned int line_number);

/* 20.my_mul.c prototpes */
void my_mul(stack_t **stack, unsigned int line_number);

/* 21.mod.c prototpes */
void my_mod(stack_t **stack, unsigned int line_number);

/* 22.my_pchar.c prototpes */
int print_pcharerror(unsigned int line_number, char *message);
void my_pchar(stack_t **stack, unsigned int line_number);

/* 23.my_pstr.c prototpes */
void my_pstr(stack_t **stack, unsigned int line_number);

/* 24.my_rotl.c prototpes */
void my_rotl(stack_t **stack, unsigned int line_number);

/* 25.my_rotr.c prototpes */
void my_rotr(stack_t **stack, unsigned int line_number);

/* 26.my_stack_queue.c prototpes */
void my_stack(stack_t **stack, unsigned int line_number);
void my_queue(stack_t **stack, unsigned int line_number);


#endif
