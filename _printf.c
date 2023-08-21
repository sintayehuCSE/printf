#include "main.h"
/**
 * _printf - Prints a formatted output to the standard output stream
 * @format: A pointer to the format to be used for printing
 *
 * Return: The number of character printed out excluding format specifier
 */
int _printf(const char *format, ...)
{
	int printed_char = 0, i = 0, printed = 0;
	va_list arg_list;
	char array[BUFFER_SIZE];

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	for (; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(*(format + i));
			printed_char++;
		}
		else
		{
			++i;
			printed = print_format(format, &i, arg_list, array);
			if (printed == -1)
				return (-1);
			printed_char = printed_char + printed;
		}
	}
	va_end(arg_list);
	return (printed_char);
}
