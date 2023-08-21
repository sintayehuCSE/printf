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
