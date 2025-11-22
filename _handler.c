#include "main.h"

/**
* _handler - a function that match specifier passed to _printf
*	with its custom functions
* @data: a pointer to a struct that holds the following:
*	- ap: list of arguments
*	- buffer_ptr: pointer to the buffer
*/

void _handler(data_t *data)
{
	int x, valid = -1;

	spec_t spec[8] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{'d', print_integer},
		{'i', print_integer},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', handle_integers}
	};

	for (x = 0; x < 8; x++)
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
