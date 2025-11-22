#ifndef PRINT_H
#define PRINT_H

#define BUFFER_SIZE 1024
#define SEPC_SIZE 3
#define STDOUT 1
#define INVALID -1

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * struct s_buffer - buffer structure for efficient output
 * @buffer: character array to store output temporarily
 * @index: current position in buffer (0 to BUFFER_SIZE-1)
 * @total_count: total number of characters printed to stdout
 *
 * Description: This structure implements buffered output for _printf.
 */
typedef struct s_buffer
{
	char buffer[BUFFER_SIZE];
	unsigned int index;
	unsigned int total_count;
} buffer_t;


/**
 * struct binary_data - holds binary representation of an integer
 * @size: number of binary digits in the array
 * @data: dynamically allocated array storing binary digits as characters
 *
 * Description: This structure stores the binary representation of an integer.
 */
typedef struct binary_data
{
	int size;
	char *data;
} binary_t;


/**
 * struct s_data - data structure for printf processing
 * @ap: variable argument list
 * @specifier: format specifier character
 * @buffer_ptr: pointer to output buffer structure
 *
 * Description: This structure holds data needed during printf processing.
 */
typedef struct s_data
{
	va_list ap;
	char specifier;
	buffer_t *buffer_ptr;
} data_t;

/**
 * struct s_specifiers - a two member struct for
 *	specifiers and custom functions
 * @name: name of the specifier
 * @func: the specifier custom function
 *
 * Description: this struct is used to match the specifier
 * with its custom function in the _handler function
 */
typedef struct s_specifiers
{
	char name;
	void (*func)(data_t *ptr);
} spec_t;


/**
 * struct s_integer_data - structure for integer base conversion
 * @num: unsigned integer value to be converted
 * @base: numerical base for conversion (2, 8, 10, or 16)
 * @is_negative: flag indicating if original number was negative (1 or 0)
 * @size: number of digits in the converted result
 * @res: dynamically allocated string holding converted digits
 *
 * Description: This structure holds data needed for converting integers
 */
typedef struct s_integer_data
{
	unsigned int num;
	int base;
	int size;
	char *res;
} integer_t;


/* __main_entry_point__ */
int _printf(const char *format, ...);
void _handler(data_t *data);

/* __utils__ */
void handle_integers(data_t *ptr);
void _convert(integer_t *data, buffer_t *buff);
void extract_digits(data_t *ptr, long nmbr);

/* __buffer_utils__ */
void add_char(buffer_t *buff, char c);
void flush_buffer(buffer_t *buff);
void int_to_buffer(integer_t *d, buffer_t *buff);


/* __custom_prints */
void print_char(data_t *ptr);
void print_str(data_t *ptr);
void print_percent(data_t *ptr);
void print_integer(data_t *ptr);
void print_binary(data_t *ptr);
void print_unsigned(data_t *ptr);


binary_t *handle_positive_binary(unsigned int nmbr);

#endif
