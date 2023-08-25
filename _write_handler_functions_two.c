#include "main.h"
/**
 * write_hexa_upper - printout each digit of uppercase hexadecimal
 * @array: Buffer that will store each upper case hexa digit
 * @index: Index of the first hexa digit
 * @size: Type casting specifier
 *
 * Return: Number of uppercase hexa digit printed
 */
int write_hexa_upper(char array[], int index, int size)
{
	int len = (BUFFER_SIZE - index) - 1;

	UNUSED(size);
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
