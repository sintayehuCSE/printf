#include "main.h"
/**
 * print_char -  Prints the optional argument with char formating
 * @ap: The optional/variable argument to be printed in char format
 *
 * Return: Number of characters printed
 */
int print_char(va_list ap)
{
	char c = va_arg(ap, int);

	return (write_char(c));
}
/**
 * print_string - Print the argument in string form
 * @ap: The variable argument
 *
 * Return: Number of characters printed
 */
int print_string(va_list ap)
{
	int len = 0;
	char *str = va_arg(ap, char *);

	/* if (str == NULL) */
	while (str[len] != '\0')
		len++;
	return (write(1, str, len));
}
/**
 * print_percent - Print the percent symbol
 * @ap: The variable argument feedin by user/call of _printf()
 *
 * Return: Number of characters printed
 */
int print_percent(va_list ap)
{
	UNUSED(ap);
	return (write(1, "%%", 1));
}
