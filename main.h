#ifndef MAIN_H
#define MAIN_H

/* .........USED TO SILENCE COMPILER UNUSED VARIABLE WARNING........ */
#define UNUSED(x) (void)(x)

/* .................SET BUFFER ARRAY OF SIZE 1024................... */
#define BUFFER_SIZE 1024

/* ..................USED TO SPECIFY A VARIABLE TYPE CASTING....... */
#define LONG_SIZE 2
#define SHORT_SIZE 1

/* ..................STD LIBRARIES FOR USE IN THIS CODE ............ */
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
/**
 * struct print_type - A structure to hold fmt and function specifier.
 * @fmt: Pointer to specified format character
 * @func: Pointer to function that handle the specified formating
 */
struct print_type
{
	char fmt;
	int (*func)(va_list, char[], int, int, int, int, int, int, int, int);
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
int print_format(const char *format, int *ind, va_list arg_list, char array[],
		 int minus, int plus, int zero, int hash, int space, int size
		 , int width, int precision);

/* ................LIST OF FUNCTION TO HANDLE FORMATING.............. */
int print_char(va_list, char[], int, int, int, int, int, int, int, int);
int print_string(va_list, char[], int, int, int, int, int, int, int, int);
int print_percent(va_list, char[], int, int, int, int, int, int, int, int);
int print_number(va_list, char[], int, int, int, int, int, int, int, int);
int print_binary(va_list, char[], int, int, int, int, int, int, int, int);
int print_unsigned(va_list, char[], int, int, int, int, int, int, int, int);
int print_octal(va_list, char[], int, int, int, int, int, int, int, int);
int print_hexa_lower(va_list, char[], int, int, int, int, int, int, int, int);
int print_hexa_upper(va_list, char[], int, int, int, int, int, int, int, int);
int print_non_printable(va_list, char[], int, int, int, int, int, int, int,
			int);
int print_address(va_list, char[], int, int, int, int, int, int, int, int);
int print_reverse(va_list, char[], int, int, int, int, int, int, int, int);

/* .............LIST OF FUNCTION TO HANDLE WRITE TO STD OUTPUT........*/
int write_char(char[], int, int);
int write_number(int, char[], int, int, int, int, int, int, int);
int write_unsgnd(char[], int, int, int, int, int);
int write_octal(int, char[], int, int, int, int, int, int);
int write_hexa_lower(int, char[], int, int, int, int, int, int);
int write_hexa_upper(int, char[], int, int, int, int, int, int);
int write_non_printable(char[]);
int write_address(char[], int);
int write_reverse(char[], int);

/* .............LIST OF FUNCTIONS TO DETERMINE SPECIFIERS OPTIONS........... */
int get_size(const char *format, int *index);
int get_minus(const char *fmt, int *index);
int get_plus(const char *fmt, int *index);
int get_zero(const char *fmt, int *index);
int get_hash(const char *fmt, int *index);
int get_space(const char *fmt, int *index);
int get_width(const char *fmt, int *index, va_list ap);
int get_precision(const char *fmt, int *index, va_list ap);

/* ............LIST OF FUNCTION FOR TYPE CASTING NUMBERS..................*/
long int cast_number(long int num, int size);
long int cast_unsgnd(unsigned long int num, int size);
long int cast_octal(unsigned long int num, int size);
long int cast_hexa_lower(unsigned long int num, int size);
long int cast_hexa_upper(unsigned long int num, int size);

/* ..................FUNCTIONS FOR NON-PRINTABLE CHARACTERS...............*/
int check_printable(char c);
void add_hexa_code(char array[], int *index, char c);


#endif /* MAIN_H */
