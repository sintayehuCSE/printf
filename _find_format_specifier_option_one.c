#include "main.h"
/**
 * get_minus - Determine the flag minus option for formating
 * @fmt: The pointer to the formating argument
 * @index: Pointer to the index where need to look for formating arise
 *
 * Return: Ascii value of minus char
*/
int get_minus(const char *fmt, int *index)
{
	int nxt_indx = *index + 1;
	char flag_in_chr[] = {'-', '+', '0', '#'}, del;
	int flag = 0, i = nxt_indx, space = 1;

	for (i = 0; i < 4; i++)
	{
		if ((fmt[*index + 2] == flag_in_chr[i]) && fmt[i] != '\0')
		{
			space = 0;
			break;
		}
	}
	i = nxt_indx;
	if (fmt[i] == ' ')
	{
		del = fmt[*index + 2];
		if (space && (del != 'i' || del != 'd'))
			return (flag);
	}
	for (; fmt[i] > 31 && fmt[i] < 65;)
	{
		del = fmt[i];
		if ((del > 64 && del < 91) || (del > 96 && del < 123)
		    || del == '\0' || del == '.')
			break;
		if (fmt[i] == 45)
		{
			flag = 45;
			break;
		}
		i++;
	}
	return (flag);
}
/**
 * get_plus - Determine the flag minus option for formating
 * @fmt: The pointer to the formating argument
 * @index: Pointer to the index where need to look for formating arise
 *
 * Return: Ascii value of plus char
 */
int get_plus(const char *fmt, int *index)
{
	int nxt_indx = *index + 1;
	char flag_in_chr[] = {'-', '+', '0', '#'}, del;
	int flag = 0, i = nxt_indx, space = 1;

	for (i = 0; i < 4; i++)
	{
		if ((fmt[*index + 2] == flag_in_chr[i]) && fmt[i] != '\0')
		{
			space = 0;
			break;
		}
	}
	i = nxt_indx;
	if (fmt[i] == ' ')
	{
		del = fmt[*index + 2];
		if (space && (del != 'd' || del != 'i'))
			return (flag);
	}
	for (; fmt[i] > 31 && fmt[i] < 65;)
	{
		del = fmt[i];
		if ((del > 64 && del < 91) || (del > 96 && del < 123)
		    || del == '\0' || del == '.')
			break;
		if (fmt[i] == 43)
		{
			flag = 43;
			break;
		}
		i++;
	}
	return (flag);
}
/**
 * get_zero - Searches for the presence of zero flag
 * @fmt: Pointer t the formating option
 * @index: Index to the format specifier marker
 *
 * Return: Ascii value of zero char
 */
int get_zero(const char *fmt, int *index)
{
	int nxt_indx = *index + 1;
	char flag_in_chr[] = {'-', '+', '0', '#'}, del;
	int flag = 0, i = nxt_indx, space = 1;

	for (i = 0; i < 4; i++)
	{
		if ((fmt[*index + 2] == flag_in_chr[i]) && fmt[i] != '\0')
		{
			space = 0;
			break;
		}
	}
	i = nxt_indx;
	if (fmt[i] == ' ')
	{
		del = fmt[*index + 2];
		if (space && (del != 'd' || del != 'i'))
			return (flag);
	}
	for (; fmt[i] > 31 && fmt[i] < 65;)
	{
		del = fmt[i];
		if ((del > 64 && del < 91) || (del > 96 && del < 123)
		    || del == '\0' || del == '.')
			break;
		if (fmt[i] == 48)
		{
			flag = 48;
			break;
		}
		i++;
	}
	return (flag);
}
/**
 * get_hash - Looks up for the presence of hash specifier option
 * @fmt: Pointer tot the formating string
 * @index: Locate the format specifier mark
 *
 * Return: The ascii value of hash character
 */
int get_hash(const char *fmt, int *index)
{
	int nxt_indx = *index + 1;
	char flag_in_chr[] = {'-', '+', '0', '#'}, del;
	int flag = 0, i = nxt_indx, space = 1;

	for (i = 0; i < 4; i++)
	{
		if ((fmt[*index + 2] == flag_in_chr[i]) && fmt[i] != '\0')
		{
			space = 0;
			break;
		}
	}
	i = nxt_indx;
	if (fmt[i] == ' ')
	{
		del = fmt[*index + 2];
		if (space && (del != 'd' || del != 'i'))
			return (flag);
	}
	for (; fmt[i] > 31 && fmt[i] < 65;)
	{
		del = fmt[i];
		if ((del > 64 && del < 91) || (del > 96 && del < 123)
		    || del == '\0' || del == '.')
			break;
		if (fmt[i] == 35)
		{
			flag = 35;
			break;
		}
		i++;
	}
	return (flag);
}
/**
 * get_space - Searches for the invisible plus sign
 * @fmt: Pointer to the formating string
 * @index: Locate the format specifier marker
 *
 * Return: Ascii value of space
 */
int get_space(const char *fmt, int *index)
{
	int nxt_indx = *index + 1;
	char flag_in_chr[] = {'-', '+', '0', '#'}, del;
	int flag = 0, i, space = 1;

	for (i = 0; i < 4; i++)
	{
		if ((fmt[*index + 2] == flag_in_chr[i]) && fmt[i] != '\0')
			space = 0;
	}
	i = nxt_indx;
	if (fmt[i] == ' ')
	{
		flag = check_space(fmt, i);
		if (flag == 32)
			return (flag);
		if (space)
			return (flag);
	}
	for (; fmt[i] > 31 && fmt[i] < 65;)
	{
		del = fmt[i];
		if ((del > 64 && del < 91) || (del > 96 && del < 123)
		    || del == '\0' || del == '.')
			break;
		if (fmt[i] == 32)
		{
			flag = 32;
			break;
		}
		i++;
	}
	return (flag);
}
