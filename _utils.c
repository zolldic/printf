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

/**
 * itobase - converts integer to string representation in specified base
 * @d: pointer to int_t structure containing number, base, and conversion flags
 * Return: dynamically allocated string containing converted digits,
 *         or NULL on allocation failure
 */
char *itobase(int_t *d)
{
	int x;
	char digits[16] = "0123456789abcdef";
	char *result = (char *) malloc(sizeof(char) * 64);

	if (!result)
		return (NULL);

	if (d->is_cap == 1)
		for (x = 10; x < 16; x++)
			digits[x] = digits[x] - 32;

	x = 0;
	while (d->number != 0)
	{
		result[x] = digits[d->number % d->base];
		d->number /= d->base;
		x++;
	}
	d->size = x;
	return (result);
}

/**
 * int_to_buffer - writes converted integer string to buffer
 * @d: pointer to int_t structure containing result string and size
 */
void int_to_buffer(int_t *d)
{
	int x;

	for (x = (d->size - 1); x >= 0; x--)
		add_char(d->buffer, d->result[x]);

	free(d->result);
}

/**
 * _strlen - calculates the length of a null-terminated string
 * @str: pointer to string
 * Return: number of characters in string (excluding null terminator)
 */
int _strlen(char *str)
{
	int x = 0;

	while (*str != '\0')
	{
		x++;
		str++;
	}
	return (x - 1);
}
