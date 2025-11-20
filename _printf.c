#include "main.h"
#include <stdlib.h>

/**
 * _printf - a custom implementation of (printf) function
 * @format: a string passed to the function
 * Return: the number of bytes written to the STDOUT
 */

int _printf(const char *format, ...)
{
	buffer_t buffer;
	data_t data;

	buffer.index = 0;
	buffer.total_count = 0;

	data.buffer_ptr = &buffer;

	if (!format)
		return (-1);

	va_start(data.ap, format);

	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) != '\0')
			{
				data.specifier = *(format + 1);
				_handler(&data);
				format++;
			}
			else
				exit(EXIT_FAILURE);
		}
		else
			add_char(&buffer, *format);

		format++;
	}

	flush_buffer(&buffer);

	va_end(data.ap);
	return (buffer.total_count);
}
