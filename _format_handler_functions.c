#include "main.h"
/**
 * print_char -  Prints the optional argument with char formating
 * @ap: The optional/variable argument to be printed in char format
 * @array: Buffer for storing characters
 *
 * Return: Number of characters printed
 */
int print_char(va_list ap, char array[])
{
	char c = va_arg(ap, int);

	UNUSED(array);
	return (write_char(c));
}
/**
 * print_string - Print the argument in string form
 * @ap: The variable argument
 * @array: Of no use here
 *
 * Return: Number of characters printed
 */
int print_string(va_list ap, char array[])
{
	int len = 0;
	char *str = va_arg(ap, char *);

	UNUSED(array);
	/* if (str == NULL) */
	while (str[len] != '\0')
		len++;
	return (write(1, str, len));
}
/**
 * print_percent - Print the percent symbol
 * @ap: The variable argument feedin by user/call of _printf()
 * @array: Of no use here
 *
 * Return: Number of characters printed
 */
int print_percent(va_list ap, char array[])
{
	UNUSED(ap);
	UNUSED(array);
	return (write(1, "%%", 1));
}
/**
 * print_number - Prints out number character to std output
 * @ap: Pointer to the variable argument
 * @array: An array that will store number characters
 *
 * Return: Number of characters and signs printed
 */
int print_number(va_list ap, char array[])
{
	long int num = va_arg(ap, long int);
	int i = BUFFER_SIZE - 2;
	int is_ngtive = 0;
	unsigned long int n;

	n = (unsigned long int)num;
	if (num == 0)
		array[i--] = '0';
	array[BUFFER_SIZE - 1] = '\0';
	if (num < 0)
	{
		n = (unsigned long int)((-1) * num);
		is_ngtive = 1;
	}
	while (n)
	{
		array[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	i++;
	return (write_number(is_ngtive, array, i));
}
