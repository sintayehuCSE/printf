#include "main.h"
/**
 * print_address - print the memory address of a pointer
 * @ap: The pointer to the variable argument
 * @array: A buffer to store each digit of an address
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
int print_address(va_list ap, char array[], int minus, int plus, int zero,
		  int hash, int space, int size, int width, int precision)
{
	int i = BUFFER_SIZE - 2;
	unsigned long num;
	void *address = va_arg(ap, void *);
	char base_16[] = "0123456789abcdef";

	UNUSED(minus);
	UNUSED(plus);
	UNUSED(zero);
	UNUSED(hash);
	UNUSED(space);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (address == NULL)
		return (write(1, "(nil)", 5));
	num = (unsigned long)address;
	array[BUFFER_SIZE - 1] = '\0';
	while (num > 0)
	{
		array[i] = base_16[num % 16];
		i--;
		num = num / 16;
		if (num == 0)
			i++;
	}
	return (write_address(array, i));

}
/**
 * print_reverse - Format string to printed in reverse
 * @ap: Pointer to variable arguments
 * @array: A buffer to store the digit of the argument
 * @minus: Specify the minus flag character
 * @plus: Specify the plus flag character
 * @zero: Specify the zero flag character
 * @hash: Specify the hash flag character
 * @space: Specify the invisible plus sign flag character
 * @size: Specify the type casting mode
 * @width: Specify the field width option
 * @precision: Specify the field precision option
 *
 * Return: The number of character printed
 */
int print_reverse(va_list ap, char array[], int minus, int plus, int zero,
		  int hash, int space, int size, int width, int precision)
{
	int i = BUFFER_SIZE - 2;
	int len = 0, j = 0;
	char *str = va_arg(ap, char *);

	UNUSED(minus);
	UNUSED(plus);
	UNUSED(zero);
	UNUSED(hash);
	UNUSED(space);
	UNUSED(size);
	UNUSED(width);
	UNUSED(precision);
	if (!str)
		return (write(1, "(null)", 6));
	while (str && str[len])
		len++;
	array[BUFFER_SIZE - 1] = '\0';
	for (len = len - 1; len >= 0; len--)
	{
		array[i--] = str[j];
		j++;
	}
	i++;
	return (write_reverse(array, i));
}
/**
 * print_rot13 - Format a string to be printed with rot13 algorithm
 * @ap: Pointer to the variable argument
 * @array: The buffer to store rot13'd string character
 * @minus: Specify the minus flag
 * @plus: Specify the plus flag
 * @zero: Specify the zero flag
 * @hash: Specify the hash flag
 * @space: Specify the space flag
 * @size: Specify the type casting flag
 * @width: Specify the field width option
 * @precision: Specify the field precision option
 *
 * Return: The number of characters printed
 */
int print_rot13(va_list ap, char array[], int minus, int plus, int zero,
		int hash, int space, int size, int width, int precision)
{
	int len = 0, i, status;
	int ind = BUFFER_SIZE - 2;
	char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot_13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str = va_arg(ap, char *);

	UNUSED(minus);
	UNUSED(plus);
	UNUSED(zero);
	UNUSED(hash);
	UNUSED(space);
	UNUSED(size);
	UNUSED(width);
	UNUSED(precision);
	if (!str)
		return (write(1, "(null)", 6));
	while (str && str[len])
		len++;
	array[BUFFER_SIZE - 1] = '\0';
	for (len = len - 1; len >= 0; len--)
	{
		status = 0;
		for (i = 0; i < 52; i++)
		{
			if (str[len] == alphabet[i])
			{
				array[ind--] = rot_13[i];
				status = 1;
				break;
			}
		}
		if (!status)
			array[ind--] = str[len];
	}
	ind++;
	return (write_rot13(array, ind));
}
