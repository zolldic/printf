#include "main.h"

/**
 * _printf - a custom implementation of (printf) function
 * @format: a string passed to the function
 * Return: the number of bytes written to the STDOUT 
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list ap;

	if (!format)
		return (count);
	
	va_start(ap, format);

	while (*format != '\0')
	{
		count += write(STDOUT, format, 1);
		++format;
	}

	va_end(ap);
	return (count);
}
