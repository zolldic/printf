#include "main.h"
#include <stdlib.h>

/**
 * add_char - adds a character to the buffer
 * @buff: pointer to buffer structure
 * @c: character to add
 */
void add_char(buffer_t *buff, char c)
{
	buff->buffer[buff->index] = c;
	buff->index++;
	buff->total_count++;

	if (buff->index == BUFFER_SIZE)
		flush_buffer(buff);
}

/**
 * flush_buffer - writes buffer contents to stdout and resets index
 * @buff: pointer to buffer structure
 */
void flush_buffer(buffer_t *buff)
{
	if (buff->index > 0)
		write(STDOUT, buff->buffer, buff->index);

	buff->index = 0;
}

/**
 * extract_digits - recursively extracts and prints digits
 * @ptr: pointer to data structure containing buffer
 * @nmbr: the number to print
 */
void extract_digits(data_t *ptr, long nmbr)
{

	if (nmbr < 0)
	{
		add_char(ptr->buffer_ptr, '-');
		nmbr = nmbr * (-1);
	}

	if (nmbr < 10)
	{
		nmbr = nmbr + '0';
		add_char(ptr->buffer_ptr, nmbr);
	}
	else
	{
		extract_digits(ptr, nmbr / 10);
		nmbr = (nmbr % 10) + '0';
		add_char(ptr->buffer_ptr, nmbr);
	}
}

/**
* int_to_buffer - a function to add integer into the buffer.
* @d: pointer to the integer_t structure
* @buff: pointer to the buffer_t structure
*
*/
void int_to_buffer(integer_t *d, buffer_t *buff)
{
	int x;

	for (x = (d->size - 1); x >= 0; x--)
		add_char(buff, d->res[x]);

	free(d->res);
}
