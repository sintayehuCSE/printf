#include "main.h"
/**
 * check_printable - Check if character in argument is non printable or not
 * @c: Character to be checked
 *
 * Return: 1 if printable 0 otherwise
 */
int check_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * add_hexa_code - add a hexa value for the non printable character
 * @array: A buffer to hold the hexa value of non printable char
 * @index: Index at which to store the hexa code
 * @c: The non-printable characteer
 *
 * Return: Nothing
 */
void add_hexa_code(char array[], int *index, char c)
{
	char base_16[] = "0123456789ABCDEF";
	int i = 0;
	char hexa[2];

	if (c < 0)
		c *= -1;
	array[*index] = '\\';
	*index += 1;
	array[*index] = 'x';
	*index += 1;
	if (c <= 15)
	{
		array[*index] = '0';
		*index += 1;
	}
	if (c == 0)
	{
		hexa[i] = '0';
	}
	while (c)
	{
		hexa[i] = base_16[c % 16];
		i++;
		c = c / 16;
		if (c == 0)
			i--;
	}
	while (i >= 0)
	{
		array[*index] = hexa[i];
		i--;
		if ((i != 0) && (i != -1))
			*index += 1;
	}
}
