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
 *
 * Return: Number of digits and signs printed
 */
int write_number(int is_ngtive, char array[], int ind)
{
	int i = 0;

	if (is_ngtive)
	{
		_putchar('-');
		i++;
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
 * write_unsigned - Prints each digit within unsigned numbers
 * @array: The buffer that store each digit of unsinged number
 * @index: Index of first digit of the unsigned number
 * @size: Value to specify the type of the unsinged number
 *
 * Return: The number of digit and fillables printed
 */
int write_unsigned(char array[], int index, int size)
{
	int len = (BUFFER_SIZE - index) - 1;

	UNUSED(size);
	return (write(1, &array[index], len));
}
/**
 * write_octal - Output each digit of octal number
 * @array: Buffer that store each digit of octal number
 * @index: An index to first digit of octal number
 * @size: Type casting specifier
 *
 * Return: The number of base digit printed
 */
int write_octal(char array[], int index, int size)
{
	int len = (BUFFER_SIZE - index) - 1;

	UNUSED(size);
	return (write(1, &array[index], len));
}
/**
 * write_hexa_lower - printout each digit of lowercase hexadecimal
 * @array: Buffer that will store each lower case hexa digit
 * @index: Index of the first hexa digit
 * @size: Type casting specifier
 *
 * Return: Number of lowercase hexa digit printed
 */
int write_hexa_lower(char array[], int index, int size);
{
	int len = (BUFFER_SIZE - index) - 1;

	UNUSED(size);
	return (write(1, &array[index], len));
}
