#include "main.h"
#include <unistd.h>

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
		exit(EXIT_FAILURE);

	va_start(ap, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(format + 1) != '\0')
				count += _handler(*(++format), ap);
			else
				exit(EXIT_FAILURE);
		}
		else
			count += write(STDOUT, format, 1);
		format++;
	}

	va_end(ap);
	return (count);
}
