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

	spec_t spec[10] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{'d', handle_integers},
		{'i', handle_integers},
		{'b', handle_integers},
		{'u', handle_integers},
		{'o', handle_integers},
		{'x', handle_integers},
		{'X', handle_integers}
	};

	for (x = 0; x < 10; x++)
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
