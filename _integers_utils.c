#include "main.h"

/**
 * handle_integers - handles conversion of integers to different bases
 * @ptr: pointer to data_t struct containing argument list and buffer
 */

void handle_integers(data_t *ptr)
{
	int n;
	integer_t data;


	n = va_arg(ptr->ap, int);

	if (n == 0)
		add_char(ptr->buffer_ptr, '0');

	if (n < 0)
		data.is_negative = 1;
	else
		data.is_negative = 0;

	data.num = abs(n);	
	if (ptr->specifier == 'o')
		data.base = 8;
	else if (ptr->specifier == 'b')
		data.base = 2;
	else if (ptr->specifier == 'x')
		data.base = 16;

	_convert(&data, ptr->buffer_ptr);

}

/**
 * _convert - converts integer data to string representation
 * @data: pointer to integer_t struct containing number and base info
 * @buf: pointer to buffer_t struct for output
  */
void _convert(integer_t *data, buffer_t *buf)
{

	/* handle postive integers */
	if (data->is_negative == 0)
		_postive_conversion(data, buf);

}

/**
 * _postive_conversion - converts positive integer to specified base
 * @d: pointer to integer_t struct with number and base
 * @buff: pointer to buffer_t struct for output
 */

void _postive_conversion(integer_t *d, buffer_t *buff)
{
	
	integer_t ptr;
	int x = 0;

	ptr.num = d->num;
	ptr.base = d->base;

	ptr.res = (char *) malloc(sizeof(char) * 32);

	if (!ptr.res)
		return;
	while (ptr.num != 0)
	{
		ptr.res[x] = (ptr.num % ptr.base) + '0';
		ptr.num /= ptr.base;
		x++;
	}
	ptr.size = x;
	
	int_to_buffer(&ptr, buff);
}

