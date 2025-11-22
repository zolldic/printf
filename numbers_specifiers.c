#include "main.h"

/**
* print_integer - extracts and prints an integer from va_list
* @ptr: pointer to data structure containing buffer and arguments
*/

void print_integer(data_t *ptr)
{
	extract_digits(ptr, va_arg(ptr->ap, int));
}

/**
* print_unsigned - convert an print number as unsigned int
* @ptr: pointer to data structure containing buffer and arguments
*/
void print_unsigned(data_t *ptr)
{

	unsigned int n;

	n = va_arg(ptr->ap, int);

	extract_digits(ptr, n);
}
