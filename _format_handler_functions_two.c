#include "main.h"
/**
* print_unsigned - Print each digit of unsigned number
* @ap: Pointer to variable arguments
* @array: A buffer to store digit of the argument
* @minus: Flag character minus
* @plus: Flag character plus
* @zero: Flag character zero
* @hash: Flag character hash
* @space: Flag char invisible plus sign
* @size: Type casting mode specifier
* @width: Flag character width
* @precision: Flag character precision
*
* Return: The number of digits in each unsigned number
*/
int print_unsigned(va_list ap, char array[], int minus, int plus, int zero,
		   int hash, int space, int size, int width, int precision)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(ap, unsigned long int);

	UNUSED(plus);
	UNUSED(hash);
	UNUSED(space);
	num = cast_unsgnd(num, size);
	if (!precision && num == 0)
		return (0);
	if (num == 0)
	{
		array[i] = '0';
		i--;
	}
	while (num > 0)
	{
		array[i] = (num % 10) + '0';
		i--;
		num = num / 10;
	}
	i++;
	return (write_unsgnd(array, i, minus, zero, width, precision));
}
/**
 * print_octal - Print numbers in octal number system
 * @ap: Pointer to the variable argument
 * @array: A buffer to store each digit of octal number
 * @minus: Flag character minus
 * @plus: Flag character plus
 * @zero: Flag character zero
 * @hash: Flag character hash
 * @space: Flag char invisible plus sign
 * @size: Type casting mode specifier
 * @width: Flag character width
 * @precision: Flag character precision
 *
 * Return: Number of octal digit printed
 */
int print_octal(va_list ap, char array[], int minus, int plus, int zero,
		int hash, int space, int size, int width, int precision)
{
	int i = BUFFER_SIZE - 2, num_case = 0;
	unsigned long int num = va_arg(ap, unsigned long int);

	UNUSED(plus);
	UNUSED(space);
	num = cast_octal(num, size);
	if (!precision && num == 0)
		return (0);
	array[BUFFER_SIZE - 1] = '\0';
	if (num == 0)
	{
		array[i] = '0';
		num_case = 1;
	}
	while (num > 0)
	{
		array[i] = (num % 8) + '0';
		i--;
		num = num / 8;
		if (num == 0)
			i++;
	}
	return (write_octal(num_case, array, i, minus, zero, hash, width, precision));
}
/**
 * print_hexa_lower - print number in lowercase hexadecimal number system
 * @ap: Pointer to the variable argument
 * @array: Buffer to store the lowercase hexa digit
 * @minus: Flag character minus
 * @plus: Flag character plus
 * @zero: Flag character zero
 * @hash: Flag character hash
 * @space: Flag char invisible plus sign
 * @size: Type casting mode specifier
 * @width: Flag character width
 * @precision: Flag character precision
 *
 * Return: Number of printed lowercase hexadigit
 */
int print_hexa_lower(va_list ap, char array[], int minus, int plus, int zero,
		     int hash, int space, int size, int width, int precision)
{
	int i = BUFFER_SIZE - 2, num_case = 0;
	unsigned long int num = va_arg(ap, unsigned long int);
	char base_digit_lower[] = "0123456789abcdef";

	UNUSED(plus);
	UNUSED(space);
	num = cast_hexa_lower(num, size);
	if (!precision && num == 0)
		return (0);
	array[BUFFER_SIZE - 1] = '\0';
	if (num == 0)
	{
		array[i] = '0';
		num_case = 1;
	}
	while (num > 0)
	{
		array[i] = base_digit_lower[num % 16];
		i--;
		num = num / 16;
		if (num == 0)
			i++;
	}
	return (write_hexa_lower(num_case, array, i, minus, zero, hash, width,
				 precision));
}
/**
 * print_hexa_upper - print number in uppercase hexadecimal number system
 * @ap: Pointer to the variable argument
 * @array: Buffer to store the uppercase hexa digit
 * @minus: Flag character minus
 * @plus: Flag character plus
 * @zero: Flag character zero
 * @hash: Flag character hash
 * @space: Flag char invisible plus sign
 * @size: Type casting mode specifier
 * @width: Flag character width
 * @precision: Flag character precision
 *
 * Return: Number of printed uppercase hexa digit
 */
int print_hexa_upper(va_list ap, char array[], int minus, int plus, int zero,
		     int hash, int space, int size, int width, int precision)
{
	int i = BUFFER_SIZE - 2, num_case = 0;
	unsigned long int num = va_arg(ap, unsigned long int);
	char base_digit_upper[] = "0123456789ABCDEF";

	UNUSED(plus);
	UNUSED(space);
	num = cast_hexa_upper(num, size);
	if (!precision && num == 0)
		return (0);
	array[BUFFER_SIZE - 1] = '\0';
	if (num == 0)
	{
		array[i] = '0';
		num_case = 1;
	}
	while (num > 0)
	{
		array[i] = base_digit_upper[num % 16];
		i--;
		num = num / 16;
		if (num == 0)
			i++;
	}
	return (write_hexa_upper(num_case, array, i, minus, zero, hash, width,
				 precision));
}
/**
 * print_non_printable - prints the non printable in argument and its chars
 * @ap: Pointer to the variable argument
 * @array: Buffer to store the uppercase hexa digit
 * @minus: Flag character minus
 * @plus: Flag character plus
 * @zero: Flag character zero
 * @hash: Flag character hash
 * @space: Flag char invisible plus sign
 * @size: Type casting mode specifier
 * @width: Flag character width
 * @precision: Flag character precision
 *
 * Return: The number of characters printed
 */
int print_non_printable(va_list ap, char array[], int minus, int plus,
			int zero, int hash, int space, int size,
			int width, int precision)
{
	int i = 0;
	int j = 0;
	char *str = va_arg(ap, char *);

	UNUSED(minus);
	UNUSED(plus);
	UNUSED(zero);
	UNUSED(hash);
	UNUSED(space);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*(str + i) != '\0')
	{
		if (check_printable(str[i]))
		{
			array[j] = str[i];
		}
		else
		{
			add_hexa_code(array, &j, str[i]);
		}
		j++;
		i++;
	}
	array[j] = '\0';
	return (write_non_printable(array));
}
