#include "main.h"
/**
 * print_format - Call to the function that
 * will handle the specified format
 * @fmt: A formated string passed in by user in which
 *  to perform the formater
 * @ind: The index of character after format specifier
 * @arg_list: The list of variable argument to be printed
 * @array: An array that will reserve a bufer for storing characters
 * @size: Determine the type of a number to be used
 * @minus: Determine the minu flags
 * @plus: Search for the plus flags
 * @zero: The zero fill flag value
 * @hash: The hash flag value
 * @space: The space flag value
 * @width: Value of a width to used for printing
 * @precision: Value for precision flag
 *
 * Return: 1 or 2
 */
int print_format(const char *fmt, int *ind, va_list arg_list, char array[],
		 int minus, int plus, int zero, int hash, int space, int size
		 , int width, int precision)
{
	int i = 0, len = 0, invalid_format = -1;
	type fmt_typ[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_number},
		{'i', print_number},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hexa_lower},
		{'X', print_hexa_upper},
		{'S', print_non_printable},
		{'p', print_address},
		{'r', print_reverse},
		{'R', print_rot13},
		{'\0', NULL}
	};

	for (; fmt_typ[i].fmt != '\0'; i++)
	{
		if (fmt[*ind] == fmt_typ[i].fmt)
			return (fmt_typ[i].func(arg_list, array, minus, plus,
						zero, hash, space, size, width,
					precision));
	}
	if (fmt_typ[i].fmt == '\0')
	{
		if ((fmt[*ind] == '\0') || (fmt[*ind] == ' ' && fmt[*ind + 1] == '\0'))
			return (invalid_format);
		if (fmt[*ind] == 'l' || fmt[*ind] == 'h')
			return (write(1, "%%", 1));
		len += write(1, "%%", 1);
		len += write(1, &fmt[*ind], 1);
		if (fmt[*ind] == ' ')
			*ind += 2;
		return (len);
	}
	return (invalid_format);
}
