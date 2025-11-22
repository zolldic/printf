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
* print_binary - converts and prints unsigned int as binary
* @ptr: pointer to data structure containing buffer and arguments
*/
void print_binary(data_t *ptr)
{
	int num;
	unsigned int un;
	int i;
	binary_t *binary;

	num = va_arg(ptr->ap, int);

	if (num == 0)
	{
		add_char(ptr->buffer_ptr, '0');
		return;
	}

	if (num < 0)
	{
		un = (unsigned int)num;
		for (i = 31; i >= 0; i--)
		{
			if ((un >> i) & 1)
				add_char(ptr->buffer_ptr, '1');
			else
				add_char(ptr->buffer_ptr, '0');
		}
	}
	else
	{
		un = (unsigned int)num;
		binary = handle_positive_binary(un);
		if (!binary)
			return;

		for (i = binary->size - 1; i >= 0; i--)
			add_char(ptr->buffer_ptr, binary->data[i]);

		free(binary->data);
		free(binary);
	}
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
