#include "main.h"
/**
 * cast_number - Casts a signed number to the required type
 * @num: The signed number to be casted
 * @size: The type of casting specifier
 *
 * Return: The number in the form of reequired type
 */
long int cast_number(long int num, int size)
{
	if (size == LONG_SIZE)
		return (num);
	else if (size == SHORT_SIZE)
		return ((short)num);
	return ((int)num);
}
/**
 * cast_unsgnd - casts a number to the required type
 * @num: The unsigned number to be casted
 * @size: The type of casting specifier
 *
 * Return: The number in the form of required type
 */
long int cast_unsgnd(unsigned long int num, int size)
{
	if (size == LONG_SIZE)
		return (num);
	else if (size == SHORT_SIZE)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
/**
 * cast_octal - casts a number to the required type
 * @num: The unsigned number to be casted
 * @size: The type of casting specifier
 *
 * Return: The number in the form of required type
 */
long int cast_octal(unsigned long int num, int size)
{
	if (size == LONG_SIZE)
		return (num);
	else if (size == SHORT_SIZE)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
/**
 * cast_hexa_lower - casts a number to the required type
 * @num: The unsigned number to be casted
 * @size: The type of casting specifier
 *
 * Return: The number in the form of required type
 */
long int cast_hexa_lower(unsigned int num, int size)
{
	if (size == LONG_SIZE)
		return (num);
	else if (size == SHORT_SIZE)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
/**
 * cast_hexa_upper - casts a number to the required type
 * @num: The unsigned number to be casted
 * @size: The type of casting specifier
 *
 * Return: The number in the form of required type
 */
long int cast_hexa_upper(unsigned int num, int size)
{
	if (size == LONG_SIZE)
		return (num);
	else if (size == SHORT_SIZE)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
