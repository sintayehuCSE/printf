#include "main.h"
/**
 * write_char - Prints a char string
 * @c: The character to be printed
 *
 * Return: Number of characters printed
 */
int write_char(char c)
{
	return (write(1, &c, 1));
}
/**
 * write_number - Write each digit in number to std output
 * @is_ngtive: Check if the number is negative
 * @array: Pointer to the array that will hold the number's
 * digit as characters
 * @ind: Index to the first element of array pointer
 * @plus: Specify the plus flag
 * @space: Specify the space flag
 *
 * Return: Number of digits and signs printed
 */
int write_number(int is_ngtive, char array[], int ind, int plus, int space)
{
	int i = 0;

	if (is_ngtive)
	{
		_putchar('-');
		i++;
	}
	else if (space && !plus)
		array[--ind] = ' ';
	else if ((space && plus) || plus)
		array[--ind] = '+';
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
 * @size: Value to specify the type of the unsinged number
 *
 * Return: The number of digit and fillables printed
 */
int write_unsgnd(char array[], int index, int size)
{
	int len = (BUFFER_SIZE - index) - 1;

	UNUSED(size);
	return (write(1, &array[index], len));
}
/**
 * write_octal - Output each digit of octal number
 * @num_case: Specify if a number if zero or not
 * @array: Buffer that store each digit of octal number
 * @index: An index to first digit of octal number
 * @size: Type casting specifier
 * @hash: Specify the hash flag
 *
 * Return: The number of base digit printed
 */
int write_octal(int num_case, char array[], int index, int size, int hash)
{
	int len = (BUFFER_SIZE - index) - 1;

	UNUSED(size);
	if (hash && !num_case)
	{
		array[--index] = '0';
		len++;
	}
	return (write(1, &array[index], len));
}
/**
 * write_hexa_lower - printout each digit of lowercase hexadecimal
 * @num_case: Specify if a number is zero or not
 * @array: Buffer that will store each lower case hexa digit
 * @index: Index of the first hexa digit
 * @size: Type casting specifier
 * @hash: Specify the hash flag
 *
 * Return: Number of lowercase hexa digit printed
 */
int write_hexa_lower(int num_case, char array[], int index, int size, int hash)
{
	int len = (BUFFER_SIZE - index) - 1;

	UNUSED(size);
	if (hash && !num_case)
	{
		array[--index] = 'x';
		array[--index] = '0';
		len += 2;
	}
	return (write(1, &array[index], len));
}
