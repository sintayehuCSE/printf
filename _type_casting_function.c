#include "main.h"
/**
 * cast_unsigned - casts a number to the required type
 * @num: The unsigned number to be casted
 * @size: The type of casting specifier
 *
 * Return: The number in the form of required type
 */

long int cast_unsigned(unsigned long int num, int size)
{
	if (size == 2)
		return (num);
	else if (size == 1)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
