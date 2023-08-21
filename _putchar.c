#include "main.h"
/**
 * _putchar - write each character to the std output
 * @c: character to be writen
 * Return: Number of character to writen which is 1 here
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
