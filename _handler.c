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
	int x;

	spec_t spec[6] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		/*
		 * {'d', print_integer},
		 * {'i', print_integer},
		 * {'b', print_binary}
		*/
	};

	for (x = 0; x < 3; x++)
	{
		if (spec[x].name == data->specifier)
			spec[x].func(data);
	}
}
