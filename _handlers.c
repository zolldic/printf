#include "main.h"

/**
 * _handler - matches format specifier with its corresponding function
 * @data: pointer to data_t struct containing:
 *  - ap: variable argument list
 *  - specifier: format specifier character
 *  - buffer_ptr: pointer to output buffer
 */

void _handler(data_t *data)
{
	int x, valid = -1;

	spec_t spec[13] = {
		{'c', handle_chars},
		{'s', handle_chars},
		{'%', print_percent},
		{'d', handle_integers},
		{'i', handle_integers},
		{'b', handle_integers},
		{'u', handle_integers},
		{'o', handle_integers},
		{'x', handle_integers},
		{'X', handle_integers},
		{'S', handle_chars},
		{'r', handle_chars},
		{'R', handle_chars}
	};

	for (x = 0; x < 13; x++)
	{
		if (spec[x].name == data->specifier)
		{
			spec[x].func(data);
			valid = 0;
		}
	}

	/* handle invalid specifiers */
	if (valid == -1)
	{
		add_char(data->buffer_ptr, '%');
		add_char(data->buffer_ptr, data->specifier);
	}
}

void handle_chars(data_t *ptr)
{
	str_t string_data;
	int x;
	router_s s[5] = {
		{'c', _chars},
		{'s', _strings},
		{'S', _custom_str},
		{'r', _reverse_str},
		/*{'R', _rot} */
	};

	string_data.buffer = ptr->buffer_ptr;
	
	if (ptr->specifier == 'c')
		string_data.c = va_arg(ptr->ap, int);
	else
		string_data.ptr = va_arg(ptr->ap, char *);

	if (!string_data.ptr)
		string_data.ptr = "(null)";

	for (x = 0; x < 5; x++)
	{
		if (ptr->specifier == s[x].name)
			s[x].func(&string_data);
	}
}

/**
 * handle_integers - handles conversion of integers to different bases
 * @ptr: pointer to data_t struct containing argument list and buffer
 */

void handle_integers(data_t *ptr)
{
	integer_t data;

	data.num = va_arg(ptr->ap, unsigned int);

	if (data.num == 0)
	{
		add_char(ptr->buffer_ptr, '0');
		return;
	}

	if (ptr->specifier == 'd' || ptr->specifier == 'i')
	{
		extract_digits(ptr, (int) data.num);
		return;
	}

	if (ptr->specifier == 'u')
	{
		extract_digits(ptr, data.num);
		return;
	}

	if (ptr->specifier == 'o')
		data.base = 8;
	else if (ptr->specifier == 'b')
		data.base = 2;
	else if (ptr->specifier == 'x')
		data.base = 16;
	else if (ptr->specifier == 'X')
	{
		data.base = 16;
		data.is_cap = 1;
	}

	_convert(&data, ptr->buffer_ptr);

}
