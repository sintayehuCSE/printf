#include "main.h"
int get_delimiter(const char *fmt, int *index);
/**
 * _printf - Prints a formatted output to the standard output stream
 * @format: A pointer to the format to be used for printing
 *
 * Return: The number of character printed out excluding format specifier
 */
int _printf(const char *format, ...)
{
	int prntd_chr = 0, i = 0, prntd = 0, size, minus, plus, zero, hash;
	int space, width, precision;
	va_list arg_list;
	char array[BUFFER_SIZE];

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	for (; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(*(format + i)), prntd_chr++;
		}
		else
		{
			size = get_size(format, &i);
			width = get_width(format, &i, arg_list);
			precision = get_precision(format, &i, arg_list);
			minus = get_minus(format, &i), plus = get_plus(format, &i);
			hash = get_hash(format, &i), zero = get_zero(format, &i);
			space = get_space(format, &i);
			i = get_delimiter(format, &i);
			prntd = print_format(format, &i, arg_list, array, minus,
					       plus, zero, hash, space, size,
					       width, precision);
			if (prntd == -1)
				return (-1);
			prntd_chr = prntd_chr + prntd;
		}
	}
	va_end(arg_list);
	return (prntd_chr);
}
/**
 * get_delimiter - Set the index to formating character
 * @index: Pointer to the current character
 * @fmt: Pointer to formating string
 *
 * Return: Value of index that point to format delimiter
 */
int get_delimiter(const char *fmt, int *index)
{
	int i = 0;
	char del;
	int space = 1;
	char flag_in_chr[] = {'-', '+', '0', '#'};

	for (; i < 4; i++)
	{
		if (fmt[*index + 1] == ' ')
			if (fmt[*index + 2] == flag_in_chr[i])
				space = 0;
		if (fmt[*index + 1] != ' ')
		{
			space = 0;
			break;
		}
	}
	if (space)
	{
		del = fmt[*index + 2];
		if (del == 'd' || del == 'i')
			return (*index + 2);
		return (*index + 1);
	}
	i = *index;
	if (fmt[i] == 'l' || fmt[i] == 'h' || fmt[i] == '%')
		i++;
	while (fmt[i] != '\0')
	{
		del = fmt[i];
		if ((del > 64 && del < 91) || (del > 96 && del < 123)
		    || del == '%')
			break;
		else if (del > 90 && del < 97)
			break;
		else if ((del > 32 && del < 48) && (del != '+' && del != '-' &&
				  del != '#' && del != '*'))
			break;
		else if ((fmt[i - 1] == 'l' || fmt[i - 1] == 'h') &&
			 (del == '\n' || del == '\0'))
		{
			i--;
			break;
		}
		i++;
	}
	return (i);
}
