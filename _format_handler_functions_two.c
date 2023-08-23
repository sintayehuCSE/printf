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
/**
 * print_hexa_lower - print number in lowercase hexadecimal number system
 * @ap: Pointer to the variable argument
 * @array: Buffer to store the lowercase hexa digit
 * @size: Type casting specifier
 *
 * Return: Number of printed lowercase hexadigit
 */
int print_hexa_lower(va_list ap, char array[], int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(ap, unsigned long int);
	char base_digit_lower[] = "0123456789abcdef";

	num = cast_hexa_lower(num, size);
	array[BUFFER_SIZE - 1] = '\0';
	if (num == 0)
		array[i] = '0';
	while (num > 0)
	{
		array[i] = base_digit_lower[num % 16];
		i--;
		num = num / 16;
		if (num == 0)
			i++;
	}
	return (write_hexa_lower(array, i, size));
}
/**
 * print_hexa_upper - print number in uppercase hexadecimal number system
 * @ap: Pointer to the variable argument
 * @array: Buffer to store the uppercase hexa digit
 * @size: Type casting specifier
 *
 * Return: Number of printed uppercase hexa digit
 */
int print_hexa_upper(va_list ap, char array[], int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(ap, unsigned long int);
	char base_digit_upper[] = "0123456789ABCDEF";

	num = cast_hexa_upper(num, size);
	array[BUFFER_SIZE - 1] = '\0';
	if (num == 0)
		array[i] = '0';
	while (num > 0)
	{
		array[i] = base_digit_upper[num % 16];
		i--;
		num = num / 16;
		if (num == 0)
			i++;
	}
	return (write_hexa_upper(array, i, size));
}
