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
* @ap: list of unknown arguments passed to _printf
* Return: count of bytes printed to STDOUT
*/

void print_integer(data_t *ptr)
{
	extract_digits(ptr, va_arg(ptr->ap, int));
}

/**
* print_digit - print the digit to STDOUT
* @nmbr: the number to print
* Return: count of bytes printed to STDOUT
*/

void extract_digits(data_t *ptr, long nmbr)
{

	if (nmbr < 0)
	{
		add_char(ptr->buffer_ptr, '-');
		nmbr = nmbr * (-1);
	}

	if (nmbr < 10)
	{
		nmbr = nmbr + '0';
		add_char(ptr->buffer_ptr, nmbr);
	}
	else
	{
		extract_digits(ptr, nmbr / 10);
		nmbr = (nmbr % 10) + '0';
		add_char(ptr->buffer_ptr, nmbr);
	}
}
