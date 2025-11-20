#include "main.h"

/**
* print_char - print a character to STDOUT
* @ptr: a struct that points to the buffer and the arguments list
*/
void print_char(data_t *ptr)
{
	add_char(ptr->buffer_ptr, va_arg(ptr->ap, int));
}

/**
* print_str - print a string to STDOUT
* @ptr: a struct that points to the buffer and the arguments list
*/
void print_str(data_t *ptr)
{
	char *str = va_arg(ptr->ap, char *);

	if (!str)
		str = "(null)";

	while (*str != '\0')
	{
		add_char(ptr->buffer_ptr, *str);
		str++;
	}
}

/**
* print_percent - print percent sign to STDOUT
* @ptr: a struct that points to the buffer and the arguments list
*/

void print_percent(data_t *ptr)
{
	(void) ptr;

	add_char(ptr->buffer_ptr, '%');
}

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

		for (i = binary->size - 1; i >= 0; i--)
			add_char(ptr->buffer_ptr, binary->data[i]);

		free(binary->data);
		free(binary);
	}
}
