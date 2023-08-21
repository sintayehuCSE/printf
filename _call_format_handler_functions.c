#include "main.h"
/**
 * print_format - Call to the function that
 * will handle the specified format
 * @format: A formated string passed in by user in which
 *  to perform the formater
 * @ind: The index of character after format specifier
 * @arg_list: The list of variable argument to be printed
 *
 * Return: 1 or 2
 */
int print_format(const char *format, int *ind, va_list arg_list)
{
	int i = 0, len = 0, invalid_format = -1;
	type fmt_typ[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};

	for (; fmt_typ[i].fmt != '\0'; i++)
	{
		if (format[*ind] == fmt_typ[i].fmt)
			return (fmt_typ[i].func(arg_list));
	}
	if (fmt_typ[i].fmt == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
			len += write(1, "", 1);
		len += write(1, &format[*ind], 1);
		return (len);
	}
	return (invalid_format);
}
