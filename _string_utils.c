#include "main.h"
#include <stddef.h>

/**
 * _chars - adds a single character to the buffer
 * @d: pointer to str_t structure containing character and buffer
 */
void _chars(str_t *d)
{
	add_char(d->buffer, d->c);
}

/**
 * print_percent - prints a literal percent sign
 * @ptr: pointer to data_t struct (unused)
 */
void _percent(str_t *d)
{
	(void) d;

	add_char(d->buffer, '%');
}

/**
 * _strings - adds a null-terminated string to the buffer
 * @d: pointer to str_t structure containing string pointer and buffer
 */
void _strings(str_t *d)
{
	int x = 0;

	while (d->ptr[x])
	{
		add_char(d->buffer, d->ptr[x]);
		x++;
	}
}

/**
 * _custom_str - handles %S specifier with non-printable character escaping
 * @d: pointer to str_t structure containing string pointer and buffer
 */
void _custom_str(str_t *d)
{
	unsigned char ch;
	char hex[5];
	char digits[] = "0123456789ABCDEF";

	while (*d->ptr)
	{
		ch = (unsigned char)*d->ptr;

		if (ch < 32 || ch >= 127)
		{
			hex[0] = '\\';
			hex[1] = 'x';
			hex[2] = digits[(ch >> 4) & 15];
			hex[3] = digits[ch & 15];
			hex[4] = '\0';

			add_char(d->buffer, hex[0]);
			add_char(d->buffer, hex[1]);
			add_char(d->buffer, hex[2]);
			add_char(d->buffer, hex[3]);
		}
		else
		{
			add_char(d->buffer, ch);
		}
		d->ptr++;
	}
}

/**
 * _reverse_str - prints a string in reverse order
 * @d: pointer to str_t structure containing string pointer and buffer
 */
void _reverse_str(str_t *d)
{
	int len;

	len = _strlen(d->ptr);

	while (len >= 0)
	{
		add_char(d->buffer, d->ptr[len]);
		len--;
	}
}

