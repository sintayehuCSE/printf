#include "main.h"
/**
 * write_char - Prints a char string
 * @array: The buffer that store the character to be stored
 * @index: The index at which the character is stored
 * @width: Specify the field width option
 *
 * Return: Number of characters printed
 */
int write_char(char array[], int index, int width)
{
	int len = (BUFFER_SIZE - index) - 1;
	char padd = ' ';
	int i = 0;

	if (width > len)
	{
		for (; i < width - len; i++)
			array[i] = padd;
		return (write(1, &array[0], width - len) + write(1, &array[index], len));
	}
	return (write(1, &array[index], len));
}
/**
 * write_number - Write each digit in number to std output
 * @is_ngtive: Check if the number is negative
 * @a: Pointer to the array that will hold the number's
 * digit as characters
 * @id: Index to the first element of array pointer
 * @minus: Specify the minus flag
 * @plus: Specify the plus flag
 * @zero: Specify the zero flag
 * @space: Specify the space flag
 * @width: Specify the field width option
 * @precision: Specify the precision oprion
 *
 * Return: Number of digits and signs printed
 */
int write_number(int is_ngtive, char a[], int id, int minus, int plus,
		 int zero, int space, int width, int precision)
{
	int i = 0, j = 0, len, assgnd = 0;
	char padd = ' ';

	if (!precision)
		return (0);
	if (is_ngtive)
		a[--id] = '-';
	else if (space && !plus)
		a[--id] = ' ';
	else if ((space && plus) || plus)
		a[--id] = '+';
	len = (BUFFER_SIZE - id) - 1;
	if ((zero && !minus) || precision > width)
		padd = '0', width = precision, assgnd = 1;
	if (width > len)
	{
		for (; j < (width - len); j++)
			a[j] = padd;
		if (minus)
			return (write(1, &a[id], len) + write(1, &a[0], width - len));
		else if (padd)
		{
			if ((padd == '0' && is_ngtive) || (padd == '0' && assgnd))
			{
				if (is_ngtive || space)
				{
					_putchar(a[id]), i++, id++;
					if (precision)
						_putchar('0'), i++;
					return (i + write(1, &a[0], width - len) + write(1, &a[id], len - 1));
				}
				return (write(1, &a[0], width - len) + write(1, &a[id], len));
			}
			return (write(1, &a[0], width - len) + write(1, &a[id], len));
		}
	}
	return (write(1, &a[id], len));
}
/**
 * write_unsgnd - Prints each digit within unsigned numbers
 * @array: The buffer that store each digit of unsinged number
 * @index: Index of first digit of the unsigned number
 * @minus: Specify the minus flag
 * @zero: Specify the zero flag
 * @width: Specify the field width option
 * @precision: Specify the precision option
 *
 * Return: The number of digit and fillables printed
 */
int write_unsgnd(char array[], int index, int minus, int zero, int width,
		 int precision)
{
	int len = (BUFFER_SIZE - index) - 1;
	char padd = ' ';
	int i = 0;

	if (!precision)
		return (0);
	if ((zero && !minus) || (precision > width))
		padd = '0';
	if (width < precision)
		width = precision;
	if (width > len)
	{
		for (; i < width - len; i++)
			array[i] = padd;
		if (minus)
			return (write(1, &array[index], len) + write(1, &array[0], width - len));
		else
			return (write(1, &array[0], width - len) + write(1, &array[index], len));
	}
	return (write(1, &array[index], len));
}
/**
 * write_octal - Output each digit of octal number
 * @num_case: Specify if a number if zero or not
 * @array: Buffer that store each digit of octal number
 * @index: An index to first digit of octal number
 * @minus: Specify the minus flag
 * @zero: Specify the zero flag
 * @hash: Specify the hash flag
 * @width: Specify the field width option
 * @precision: Specify the precision option
 *
 * Return: The number of base digit printed
 */
int write_octal(int num_case, char array[], int index, int minus, int zero,
		int hash, int width, int precision)
{
	int len = (BUFFER_SIZE - index) - 1;
	char padd = ' ';
	int i = 0;

	if (!precision)
		return (0);
	if (hash && !num_case)
	{
		array[--index] = '0';
		len++;
	}
	if ((zero && !minus) || (precision > width))
		padd = '0';
	if (width < precision)
		width = precision;
	if (width > len)
	{
		for (; i < width - len; i++)
			array[i] = padd;
		if (minus)
			return (write(1, &array[index], len) + write(1, &array[0], width - len));
		else
			return (write(1, &array[0], width - len) + write(1, &array[index], len));
	}
	return (write(1, &array[index], len));
}
/**
 * write_hexa_lower - printout each digit of lowercase hexadecimal
 * @num_case: Specify if a number is zero or not
 * @array: Buffer that will store each lower case hexa digit
 * @index: Index of the first hexa digit
 * @minus: Specify the minus flag
 * @zero: Specify the zero flag
 * @hash: Specify the hash flag
 * @width: Specify the field width option
 * @precision: Specify the precision option
 *
 * Return: Number of lowercase hexa digit printed
 */
int write_hexa_lower(int num_case, char array[], int index, int minus,
		     int zero, int hash, int width, int precision)
{
	int len = (BUFFER_SIZE - index) - 1;
	char padd =  ' ';
	int i = 0;

	if (!precision)
		return (0);
	if (hash && !num_case)
	{
		array[--index] = 'x';
		array[--index] = '0';
		len += 2;
	}
	if ((zero && !minus) || (precision > width))
		padd = '0';
	if (precision > width)
		width = precision;
	if (width > len)
	{
		for (; i < width - len; i++)
			array[i] = padd;
		if (minus)
			return (write(1, &array[index], len) + write(1, &array[0], width - len));
		else
			return (write(1, &array[0], width - len) + write(1, &array[index], len));
	}
	return (write(1, &array[index], len));
}
