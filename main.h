#ifndef PRINT_H
#define PRINT_H

#define STDOUT 1
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>


/**
 * struct Specifiers - a two memeber struct for
 *	specifiers and custom functions
 *	@name: name of the specifier
 *	@func: the specifier custom funciton
 *
 *	Description: this struct is used to match the spsecifier
 *		with its custom funciton in the _handler funciton
 */

typedef struct Specifiers
{
	char name;
	int (*func)(va_list ap);
} spec_t;

int _printf(const char *format, ...);

int _handler(char specifier, va_list ap);

/* custom print functions */
int print_char(va_list ap);
int print_str(va_list ap);
int print_percent(va_list ap);

#endif
