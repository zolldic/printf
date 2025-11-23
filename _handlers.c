#include "main.h"

/**
 * _handler - matches format specifier with its corresponding function
 * @data: pointer to data_t struct containing format processing data
 */
void _handler(data_t *data)
{
	int x, valid = -1;

	spec_t spec[13] = {
		{'c', handle_chars},
		{'s', handle_chars},
		{'%', handle_chars},
		{'d', handle_integers},
		{'i', handle_integers},
		{'b', handle_integers},
		{'u', handle_integers},
		{'o', handle_integers},
		{'x', handle_integers},
		{'X', handle_integers},
		{'S', handle_chars},
		{'r', handle_chars},
		{'p', handle_integers}
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


/**
 * handle_chars - handles character and string format specifiers
 * @ptr: pointer to data_t struct containing format data
 */
void handle_chars(data_t *ptr)
{
	str_t string_data;
	int x;
	router_s s[5] = {
		{'c', _chars},
		{'%', _percent},
		{'s', _strings},
		{'S', _custom_str},
		{'r', _reverse_str},
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
 * handle_integers - handles integer format specifiers
 * @ptr: pointer to data_t struct containing argument list and buffer
 */
void handle_integers(data_t *ptr)
{

	#define I_SIZE 5

	int x = 0;
	int_t data;

	router_i specifiers[8] = {
		{'d', 10, _extract_signed},
		{'i', 10, _extract_signed},
		{'u', 10, _extract_u},
		{'o', 8, _convert},
		{'b', 2, _convert},
		{'x', 16, _convert},
		{'X', 16, _convert},
		{'p', 16, _extract_address}
	};

	data.number = 0;

	if (ptr->specifier == 'd' || ptr->specifier == 'i')
		data.number = (int) va_arg(ptr->ap, int);
	else if (ptr->specifier == 'p')
		data.number = (unsigned long int) va_arg(ptr->ap, void *);
	else
		data.number =  va_arg(ptr->ap, unsigned int);

	data.buffer = ptr->buffer_ptr;

	if (data.number == 0)
	{
		add_char(ptr->buffer_ptr, '0');
		return;
	}

	while (x < 8)
	{
		if (specifiers[x].name == ptr->specifier)
		{
			data.base = specifiers[x].base;
			if (specifiers[x].name == 'X')
				data.is_cap = 1;
			else
				data.is_cap = 0;
			specifiers[x].func(&data);
			return;
		}
		x++;
	}
}
