#include "main.h"
#include <stdlib.h>


/**
 * _convert - converts unsigned integer to string in specified base
 * @d: pointer to int_t structure containing number, base, and buffer
 */
void _convert(int_t *d)
{
	int_t ptr;

	ptr.number = d->number;
	ptr.base = d->base;
	ptr.buffer = d->buffer;
	ptr.is_cap = d->is_cap;

	ptr.result = itobase(&ptr);
	if (!ptr.result)
		return;

	int_to_buffer(&ptr);
}

/**
 * _extract_signed - converts signed integer to decimal string
 * @d: pointer to int_t structure containing number and buffer
 */
void _extract_signed(int_t *d)
{
	int x = 0;
	long int n = (long int) d->number;
	unsigned int digit;

	d->result = (char *) malloc(sizeof(char) * 1024);

	if (!d->result)
		return;

	if (n < 0)
	{
		add_char(d->buffer, '-');
		n =  n * (-1);
	}

	while (n > 0)
	{
		digit = n % 10;
		d->result[x] = digit + '0';
		n /= 10;
		x++;
	}

	d->size = x;

	int_to_buffer(d);
}

/**
 * _extract_u - converts unsigned integer to decimal string
 * @d: pointer to int_t structure containing number and buffer
 */
void _extract_u(int_t *d)
{
	int x = 0;
	unsigned long int n = d->number;
	unsigned int digit;

	d->result = (char *) malloc(sizeof(char) * 1024);

	if (!d->result)
		return;

	while (n > 0)
	{
		digit = n % 10;
		d->result[x] = digit + '0';
		n /= 10;
		x++;
	}

	d->size = x;

	int_to_buffer(d);
}

/**
 * _extract_address - converts pointer address to hexadecimal string
 * @d: pointer to int_t structure containing address value and buffer
 */
void _extract_address(int_t *d)
{
	add_char(d->buffer, '0');
	add_char(d->buffer, 'x');

	d->result = itobase(d);

	int_to_buffer(d);
}
