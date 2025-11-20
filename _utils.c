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
 * handle_positive_binary - converts unsigned int to binary representation
 * @nmbr: the number to convert
 *
 * Return: pointer to binary_t structure containing binary data
 */
binary_t *handle_positive_binary(unsigned int nmbr)
{
	binary_t *tmp;

	tmp = (binary_t *)malloc(sizeof(binary_t));

	tmp->size = 0;
	tmp->data = (char *)malloc(sizeof(char) * 32);
	while (nmbr != 0)
	{
		tmp->data[tmp->size] = (nmbr % 2) + '0';
		nmbr = nmbr / 2;
		tmp->size++;
	}

	return (tmp);
}
