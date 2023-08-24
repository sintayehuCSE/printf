#include "main.h"
/**
 * print_address - print the memory address of a pointer
 * @ap: The pointer to the variable argument
 * @array: A buffer to store each digit of an address
 * @size: A type casting specifier
 *
 * Return: The number of characters printed
 */
int print_address(va_list ap, char array[], int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long num;
	void *address = va_arg(ap, void *);
	char base_16[] = "0123456789abcdef";

	UNUSED(size);
	if (address == NULL)
		return (write(1, "(null)", 6));
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
