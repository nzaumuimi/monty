#include "monty.h"
#include <stdlib.h>

/**
 * get_int - Converts an integer to a new string representation.
 * @num: The number to convert.
 *
 * Return: A pointer to the newly created
 * string.Returns NULL if memory allocation fails.
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_1 = 0;
	char *ret;

	temp = my_abs(num);
	length = numbase_length(temp, 10);

	if (num < 0 || num_1 < 0)
		length++; /* set the first character of string */
	ret = malloc(length + 1); /* memory for new string */
	if (!ret)
		return (NULL);

	fill_buff(temp, 10, ret, length);
	if (num < 0 || num_1 < 0)
		ret[0] = '-';

	return (ret);
}

/**
  * my_abs - Calculates the absolute value of an integer.
  * @i: The integer to find the absolute value of.
  *
  * Return: An unsigned integer showing the absolute value of i.
 */
unsigned int my_abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * numbase_length - Calculates the required buffer
 * length for an unsigned integer.
 * @num: The number for which to calculate the buffer length.
 * @base: The base of the number representation used by the buffer.
 *
 * Return: An integer representing the length of
 * the buffer needed (excluding the null terminator).
 */
int numbase_length(unsigned int num, unsigned int base)
{
	int len = 1; /* minimum length of a number */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_buff - Populates a buffer with the correct
 * digits up to base 36.
 * @num: The number to convert to a string in the given base.
 * @base: The base used in the conversion; valid up to base 36.
 * @buff: The buffer to fill with the result of the conversion.
 * @buff_size: The size of the buffer in bytes.
 *
 * Return: void.
 */
void fill_buff(unsigned int num, unsigned int base, char *buff,
		int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* return lowercase ASCII */
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
