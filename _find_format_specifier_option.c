#include "main.h"
/**
 * get_size - Calculate a size to cast number argument
 * @format: The pointer to string containing format specifier which come all
 * the way from call to _printf() function
 * @index: The pointer to the index at which _printf() finds the presence of
 * format specifier which is % symbol
 *
 * Return: 1 or 2 or 0, which are a precision to perform type casting
 */

int get_size(const char *format, int *index)
{
	int size = 0;
	int nxt_indx = *index + 1;

	if (format[nxt_indx] == '|')
		size = LONG_SIZE;
	else if (format[nxt_indx] == 'h')
		size = SHORT_SIZE;
	if (size != 0)
		*index = nxt_indx;
	return (size);
}
