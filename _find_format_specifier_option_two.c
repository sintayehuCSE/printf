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
 * get_width - Find the wdth option of format specifier
 * @fmt: Pointer to the formating string
 * @index: Pointer to initializer of format specifier
 * @ap: Pointer to the argument to serve as a width option value
 *
 * Return: The width option
 */
int get_width(const char *fmt, int *index, va_list ap)
{
	int i = *index, end = 0, width = 0;
	char del;

	if (fmt[i] == 'h' || fmt[i] == 'l' || fmt[i] == '%')
		i++;
	while (fmt[i] != '\0')
	{
		del = fmt[i];
		if (del == '.')
		{
			end = i;
			break;
		}
		else if ((del > 64 && del < 91) || (del > 96 && del < 123))
		{
			end = i;
			break;
		}
		else
		{
			i++;
		}
	}
	if (fmt[i - 1] == '*')
	{
		width = va_arg(ap, int);
		return (width);
	}
	i--;
	while (fmt[i] > 47 && fmt[i] < 58)
	{
		i--;
	}
	i++;
	for (; i < end; i++)
	{
		width = width * 10;
		width = width + fmt[i] - '0';
	}
	return (width);
}
/**
 * get_precision - Determine the supposed precision
 * @fmt: Pointer to formating string
 * @index: Pointer to format specifier marker
 * @ap: Point to argument that can be a value of precision
 *
 * Return: The specified precision
 */
int get_precision(const char *fmt, int *index, va_list ap)
{
	int i = *index;
	char del;
	int precision = 0;

	if (fmt[i] == 'l' || fmt[i] == 'h' || fmt[i] == '%')
		i++;
	while (fmt[i] != '\0')
	{
		del = fmt[i];
		if ((del > 64 && del < 91) || (del > 96 && del < 123))
			break;
		if (fmt[i] == '.')
		{
			break;
		}
		i++;
	}
	i++;
	if (fmt[i] == '*' && fmt[i - 1] != '\0')
	{
		precision = va_arg(ap, int);
		return (precision);
	}
	while (fmt[i] != '\0' && fmt[i - 1] != '\0')
	{
		del = fmt[i];
		if ((del > 64 && del < 91) || (del > 96 && del < 123))
			break;
		if (del >= 48 && del <= 57)
		{
			precision *= 10;
			precision += del + '0';
		}
		i++;
	}
	return (precision);
}
