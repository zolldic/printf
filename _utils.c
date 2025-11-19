#include "main.h"

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

