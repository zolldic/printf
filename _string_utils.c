#include "main.h"
#include <stddef.h>

/**
 * _chars - Adds a char to the buffer
 * @d: a str_t data structure
 */
void _chars(str_t *d)
{
	add_char(d->buffer, d->c);
}

/**
 * _strings - Adds a string to the buffer
 * @d: a str_t data structure
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
 * _custom_str - Handles %S specifier, prints non-printable chars as \xHH
 * @d: a str_t data structure
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
 * _reverse_str - Reverses a string to the buffer
 * @d: a str_t data structure
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

