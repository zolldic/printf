#include "main.h"
#include <stdlib.h>

/**
 * _printf - custom implementation of printf function
 * @format: format string containing text and format specifiers
 *
 * Description: Produces output according to a format string.
 * Supports specifiers: c, s, %, d, i, b, u, o, x, X, S, r, p
 * Uses buffered output for efficiency.
 *
 * Return: number of characters printed (excluding null byte),
 *         or -1 if format is NULL
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
