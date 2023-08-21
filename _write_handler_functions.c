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
