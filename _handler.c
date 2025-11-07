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
	int invalid = INVALID;

	spec_t spec[3] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
	};

	for (x = 0; x < 3; x++)
	{
		if (spec[x].name == specifier)
		{
			count += spec[x].func(ap);
			invalid = 0;
		}
	}
	
	if (invalid == INVALID)
		return (INVALID);

	return (count);
}
