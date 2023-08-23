#include "main.h"
/**
 * print_unsigned - Print each digit of unsigned number
 * @size: Determine the type of numbers to be used
 * @ap: Pointer to variable arguments
 * @array: A buffer to store digit of the argument
 *
 * Return: The number of digits in each unsigned number
 */
int print_unsigned(va_list ap, char array[], int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(ap, unsigned long int);

	num = cast_unsigned(num, size);
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
	return (write_unsigned(array, i, size));
}
/**
 * print_octal - Print numbers in octal number system
 * @ap: Pointer to the variable argument
 * @array: A buffer to store each digit of octal number
 * @size: Specifier for type casting
 *
 * Return: Number of octal digit printed
 */
int print_octal(va_list ap, char array[], int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(ap, unsigned long int);

	num = cast_octal(num, size);
	array[BUFFER_SIZE - 1] = '\0';
	if (num == 0)
		array[i] = '0';
	while (num > 0)
	{
		array[i] = (num % 8) + '0';
		i--;
		num = num / 8;
		if (num == 0)
			i++;
	}
	return (write_octal(array, i, size));
}
