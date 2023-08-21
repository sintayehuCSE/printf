#ifndef MAIN_H
#define MAIN_H
#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct print_type - A structure to hold fmt and function specifier.
 * @fmt: Pointer to specified format character
 * @func: Pointer to function that handle the specified formating
 */
struct print_type
{
	char fmt;
	int (*func)(va_list);
};
/**
 * typedef struct print_type type - Rename struct to new name type
 *
 * @fmt: The format encountered
 * @func: The function associated with the format specifier
 */
typedef struct print_type type;
int _putchar(char c);
int _printf(const char *format, ...);
int print_format(const char *format, int *ind, va_list arg_list);

/* ................LIST OF FUNCTION TO HANDLE FORMATING.............. */
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);

/* .............LIST OF FUNCTION TO HANDLE WRITE TO STD OUTPUT........*/
int write_char(char c);

#endif /* MAIN_H */
