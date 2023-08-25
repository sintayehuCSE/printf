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

	if (format[nxt_indx] == 'l')
		size = LONG_SIZE;
	else if (format[nxt_indx] == 'h')
		size = SHORT_SIZE;
	if (size != 0)
		*index = nxt_indx;
	return (size);
}
/**
 * get_minus - Determine the flag minus option for formating
 * @fmt: The pointer to the formating argument
 * @index: Pointer to the index where need to look for formating arise
 *
 * Return: Ascii value of minus char
*/
int get_minus(const char *fmt, int *index)
{
	int nxt_indx = *index + 1;
	char flag_in_chr[] = {'-', '+', '0', '#', ' ', '\0'};
	int flag = 0, i = nxt_indx, space = 1;

	for (i = 0; i < 5; i++)
	{
		if (fmt[*index + 2] == flag_in_chr[i])
			space = 0;
	}
	i = nxt_indx;
	if (fmt[i] == ' ')
	{
		if (space)
			return (flag);
	}
	for (; (fmt[i] > 31 && fmt[i] < 65) || (fmt[i] == 'l' || fmt[i] == 'h');)
	{
		if (fmt[i] == 45)
		{
			flag = 45;
			break;
		}
	}
	return (flag);
}
/**
 * get_plus - Determine the flag minus option for formating
 * @fmt: The pointer to the formating argument
 * @index: Pointer to the index where need to look for formating arise
 *
 * Return: Ascii value of plus char
 */
