#include "main.h"

/**
* _handler - a function that match specifier passed to _printf
*	with its custom functions
* @specifier: specifier passed in the custom _printf
* @ap: list of unknown arguments
* Return: the count of the bytes printed in STDOUT
*/

int _handler(char specifier, va_list ap)
{
	int x;
	int count = 0;

	spec_t spec[5] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{'d', print_integer},
		{'i', print_integer}
	};

	for (x = 0; x < 5; x++)
	{
		if (spec[x].name == specifier)
			count += spec[x].func(ap);
	}

	return (count);
}
