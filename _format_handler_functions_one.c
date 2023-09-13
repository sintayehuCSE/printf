#include "main.h"
/**
 * print_char -  Prints the optional argument with char formating
 * @ap: The optional/variable argument to be printed in char format
 * @array: Buffer for storing characters
 * @minus: Flag character minus
 * @plus: Flag character plus
 * @zero: Flag character zero
 * @hash: Flag character hash
 * @space: Flag char invisible plus sign
 * @size: Determine the type of numbers to be used
 * @width: Flag character width
 * @precision: Flag character precision
 *
 * Return: Number of characters printed
 */
int print_char(va_list ap, char array[], int minus, int plus, int zero,
	       int hash, int space, int size, int width, int precision)
{
	char c = va_arg(ap, int);
	int i = BUFFER_SIZE - 2;

	UNUSED(size);
	UNUSED(plus);
	UNUSED(zero);
	UNUSED(hash);
	UNUSED(space);
	UNUSED(precision);
	array[BUFFER_SIZE - 1] = '\0';
	array[i] = c;
	return (write_char(array, i, minus, width));
}
/**
 * print_string - Print the argument in string form
 * @ap: The variable argument
 * @array: Of no use here
 * @minus: Flag character minus
 * @plus: Flag character plus
 * @zero: Flag character zero
 * @hash: Flag character hash
 * @space: Flag char invisible plus sign
 * @size: Determine the type of numbers to be used
 * @width: Flag character width
 * @precision: Flag character precision
 *
 * Return: Number of characters printed
 */
int print_string(va_list ap, char array[], int minus, int plus, int zero,
		 int hash, int space, int size, int width, int precision)
{
	int len = 0;
	int i = 0;
	char padd = ' ';
	char *str = va_arg(ap, char *);

	UNUSED(size);
	UNUSED(plus);
	UNUSED(zero);
	UNUSED(hash);
	UNUSED(space);
	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	if (!precision)
		return (0);
	while (str[len] != '\0')
		len++;
	if (precision != -1 && precision < len)
		return (write(1, str, precision));
	if (width && (width > len))
	{
		for (; i < width - len; i++)
			array[i] = padd;
		if (minus)
			return (write(1, str, len) + write(1, &array[0], width - len));
		return (write(1, &array[0], width - len) + write(1, str, len));
	}
	return (write(1, str, len));
}
/**
 * print_percent - Print the percent symbol
 * @ap: The variable argument feedin by user/call of _printf()
 * @array: Of no use here
 * @minus: Flag character minus
 * @plus: Flag character plus
 * @zero: Flag character zero
 * @hash: Flag character hash
 * @space: Flag char invisible plus sign
 * @size: Determine the type of numbers to be used
 * @width: Flag character width
 * @precision: Flag character precision
 *
 * Return: Number of characters printed
 */
int print_percent(va_list ap, char array[], int minus, int plus, int zero,
		  int hash, int space, int size, int width, int precision)
{
	UNUSED(ap);
	UNUSED(array);
	UNUSED(size);
	UNUSED(minus);
	UNUSED(plus);
	UNUSED(zero);
	UNUSED(hash);
	UNUSED(space);
	UNUSED(width);
	UNUSED(precision);
	return (write(1, "%%", 1));
}
/**
 * print_number - Prints out number character to std output
 * @ap: Pointer to the variable argument
 * @array: An array that will store number characters
 * @minus: Flag character minus
 * @plus: Flag character plus
 * @zero: Flag character zero
 * @hash: Flag character hash
 * @space: Flag char invisible plus sign
 * @size: Determine the type of numbers to be used
 * @width: Flag character width
 * @precision: Flag character precision
 *
 * Return: Number of characters and signs printed
 */
int print_number(va_list ap, char array[], int minus, int plus, int zero,
		 int hash, int space, int size, int width, int precision)
{
	long int num = va_arg(ap, long int);
	int i = BUFFER_SIZE - 2;
	int is_ngtive = 0;
	unsigned long int n;

	UNUSED(hash);
	num = cast_number(num, size);
	if (!precision && num == 0)
		return (write(1, " ", width));
	if (num == 0)
		array[i--] = '0';
	array[BUFFER_SIZE - 1] = '\0';
	n = (unsigned long int)num;
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
	return (write_number(is_ngtive, array, i, minus, plus, zero, space,
			     width, precision));
}
/**
 * print_binary - Convert unsigned int argument to binary
 * @ap: The variable argument
 * @array: A buffer to store the binary digits
 * @minus: Flag character minus
 * @plus: Flag character plus
 * @zero: Flag character zero
 * @hash: Flag character hash
 * @space: Flag char invisible plus sign
 * @size: Determine the type of numbers to be used
 * @width: Flag character width
 * @precision: Flag character precision
 *
 * Return: The number of characters printed
 */
int print_binary(va_list ap, char array[], int minus, int plus, int zero,
		 int hash, int space, int size, int width, int precision)
{
	unsigned int u_int_num = va_arg(ap, unsigned int);
	int i = BUFFER_SIZE - 2;
	int printed_digit = 0;

	UNUSED(size);
	UNUSED(minus);
	UNUSED(plus);
	UNUSED(zero);
	UNUSED(hash);
	UNUSED(space);
	UNUSED(width);
	UNUSED(precision);
	array[BUFFER_SIZE - 1] = '\0';
	if (u_int_num != 0)
	{
		while (u_int_num)
		{
			array[i] = (u_int_num % 2) + '0';
			i--;
			u_int_num /= 2;
		}
		i++;
	}
	else
	{
		array[i] = '0';
	}
	while (i < (BUFFER_SIZE - 1))
	{
		printed_digit += _putchar(array[i]);
		i++;
	}
	return (printed_digit);
}
