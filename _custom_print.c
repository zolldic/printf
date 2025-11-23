#include "main.h"

/**
* print_percent - print percent sign to STDOUT
* @ptr: a struct that points to the buffer and the arguments list
*/

void print_percent(data_t *ptr)
{
	(void) ptr;

	add_char(ptr->buffer_ptr, '%');
}


