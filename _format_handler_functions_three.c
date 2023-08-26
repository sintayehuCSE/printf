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
