#include "monty.h"
#include <stdlib.h>

char **tok_str(char *str, char *delims);

/**
 * tok_str - Parses a string and separates its words.
 *
 * @str: The string to separate into words.
 * @delims: The delimiters to use for word separation.
 *
 * Return: A 2D array of pointers to each word.
 */
char **tok_str(char *str, char *delims)
{
	char **words = NULL;
	int wc, wl, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = token_count(str, delims);

	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wl = token_length(str, delims);
		if (_delimeter(*str, delims))
		{
			str = next_token(str, delims);
		}
		words[i] = malloc((wl + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wl)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = next_token(str, delims);
		i++;
	}
	words[i] = NULL;
	return (words);
}

/**
 * _delimeter - Checks if the stream has a delimiter character.
 *
 * @ch: The character in the stream.
 *
 * @delims: Pointer to a null-terminated array of delimiters.
 *
 * Return: 1 (success), 0 (failure).
 */
int _delimeter(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * token_length - Retrieves the length of the current word
 * in the string.
 *
 * @str: The string to get the word length from the current word.
 * @delims: Delimiters used to delimit words.
 *
 * Return: The word length of the current word.
 */
int token_length(char *str, char *delims)
{
	int wlen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (_delimeter(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wlen++;
		}
		if (wlen > 0 && _delimeter(str[i], delims))
			break;
		i++;
	}
	return (wlen);
}

/**
 * token_count - Retrieves the word count of a string.
 *
 * @str: The string to get the word count from.
 * @delims: Delimiters used to delimit words.
 *
 * Return: The word count of the string.
 */
int token_count(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (_delimeter(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * next_token - Retrieves the next word in a string.
 *
 * @str: The string to get the next word from.
 * @delims: Delimiters used to delimit words.
 *
 * Return: A pointer to the first character of the next word.
 */
char *next_token(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (_delimeter(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
