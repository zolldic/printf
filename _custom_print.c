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
	write(STDOUT, "%", 1);
}

