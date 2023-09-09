#include "main.h"
/**
 * write_hexa_upper - printout each digit of uppercase hexadecimal
 * @num_case: Specify whether a number is zero or not
 * @array: Buffer that will store each upper case hexa digit
 * @index: Index of the first hexa digit
 * @minus: Specify the minus flag
 * @zero: Specify the zero flag
 * @hash: Specify the hash flag
 * @width: Specify the field width option
 *
 * Return: Number of uppercase hexa digit printed
 */
int write_hexa_upper(int num_case, char array[], int index, int minus, int zero
		     , int hash, int width)
{
	int len = (BUFFER_SIZE - index) - 1;
	char padd = ' ';
	int i = 0;

	if (hash && !num_case)
	{
		array[--index] = 'X';
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
/**
 * write_non_printable - Write the string with non_printable characters
 * @array: A buffer that holds the arguments character
 *
 * Return: Number of printed characters
 */
int write_non_printable(char array[])
{
	int i = 0;
	int len = 0;

	while (array[i] != '\0')
	{
		len++;
		i++;
	}
	return (write(1, array, len));
}
/**
 * write_address - Printout the memory address of a variable
 * @array: A buffer to store each hexa digit of the address
 * @index: The index to the first hexa digit
 *
 * Return: Number of character printed
 */
int write_address(char array[], int index)
{
	int len = (BUFFER_SIZE - index - 1) + 2;

	array[--index] = 'x';
	array[--index] = '0';
	return (write(1, &array[index], len));
}
