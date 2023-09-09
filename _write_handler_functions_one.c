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
 * @array: Pointer to the array that will hold the number's
 * digit as characters
 * @ind: Index to the first element of array pointer
 * @minus: Specify the minus flag
 * @plus: Specify the plus flag
 * @zero: Specify the zero flag
 * @space: Specify the space flag
 * @width: Specify the field width option
 *
 * Return: Number of digits and signs printed
 */
int write_number(int is_ngtive, char array[], int ind, int minus, int plus,
		 int zero, int space, int width)
{
	int i = 0, j = 0;
	char padd = ' ';
	int len;

	if (is_ngtive)
		array[--ind] = '-';
	else if (space && !plus)
		array[--ind] = ' ';
	else if ((space && plus) || plus)
		array[--ind] = '+';
	len = (BUFFER_SIZE - ind) - 1;
	if (width > len)
	{
		if (zero && !minus)
			padd = '0';
		for (; j < (width - len); j++)
			array[j] = padd;
		if (minus)
			return (write(1, &array[ind], len) + write(1, &array[0], width - len));
		else if (padd)
		{
			if (padd == '0' && is_ngtive)
			{
				_putchar(array[ind]);
				i++;
				ind++;
				return (i + write(1, &array[0], width - len)
					+ write(1, &array[ind], len - 1));
			}
			return (write(1, &array[0], width - len) + write(1, &array[ind], len));
		}
	}
	while (*(array + ind))
	{
		_putchar(*(array + ind));
		i++;
		ind++;
	}
	return (i);
}
/**
 * write_unsgnd - Prints each digit within unsigned numbers
 * @array: The buffer that store each digit of unsinged number
 * @index: Index of first digit of the unsigned number
 * @minus: Specify the minus flag
 * @zero: Specify the zero flag
 * @width: Specify the field width option
 *
 * Return: The number of digit and fillables printed
 */
int write_unsgnd(char array[], int index, int minus, int zero, int width)
{
	int len = (BUFFER_SIZE - index) - 1;
	char padd = ' ';
	int i = 0;

	if (zero && !minus)
		padd = '0';
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
 *
 * Return: The number of base digit printed
 */
int write_octal(int num_case, char array[], int index, int minus, int zero,
		int hash, int width)
{
	int len = (BUFFER_SIZE - index) - 1;
	char padd = ' ';
	int i = 0;

	if (hash && !num_case)
	{
		array[--index] = '0';
		len++;
	}
	if (zero && !minus)
		padd = '0';
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
 *
 * Return: Number of lowercase hexa digit printed
 */
int write_hexa_lower(int num_case, char array[], int index, int minus,
		     int zero, int hash, int width)
{
	int len = (BUFFER_SIZE - index) - 1;
	char padd =  ' ';
	int i = 0;

	if (hash && !num_case)
	{
		array[--index] = 'x';
		array[--index] = '0';
		len += 2;
	}
	if (zero && !minus)
		padd = '0';
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
