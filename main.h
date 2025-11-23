#ifndef PRINT_H
#define PRINT_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define STDOUT 1

/* ___ CORE STRUCTURES __*/

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
 * struct s_specifiers - maps format specifiers to handler functions
 * @name: format specifier character (e.g., 'c', 's', 'd')
 * @func: pointer to function that handles this specifier
 *
 * Description: This structure is used to match format specifiers
 * with their corresponding handler functions in _handler
 */
typedef struct s_specifiers
{
	char name;
	void (*func)(data_t *ptr);
} spec_t;


/* __ STRING STRUCTURES __*/

/**
 * struct s_string - structure for string/character processing
 * @c: single character (for %c specifier)
 * @ptr: pointer to string (for %s, %S, %r specifiers)
 * @buffer: pointer to output buffer
 *
 * Description: Used for handling string and character format specifiers
 */
typedef struct s_string
{
	char c;
	char *ptr;
	buffer_t *buffer;
} str_t;

/**
 * struct s_router - maps string specifiers to handler functions
 * @name: format specifier character (e.g., 'c', 's', 'S', 'r')
 * @func: pointer to function that handles this string specifier
 *
 * Description: Router for string-related format specifiers
 */
typedef struct s_router
{
	char name;
	void (*func)(str_t *ptr);
} router_s;

/* __ INTEGER STRUCTURES ___ */

/**
 * struct i_int - structure for integer conversion
 * @number: unsigned long integer value to be converted
 * @result: dynamically allocated string holding converted digits
 * @base: numerical base for conversion (2, 8, 10, or 16)
 * @size: number of digits in the converted result
 * @is_cap: flag for uppercase conversion (1 = uppercase, 0 = lowercase)
 * @buffer: pointer to output buffer
 *
 * Description: Primary structure for integer to string conversion
 */
typedef struct i_int
{
	unsigned long int number;
	char *result;
	int base;
	int size;
	int is_cap;
	buffer_t *buffer;
} int_t;

/**
 * struct i_router - maps integer specifiers to handler functions
 * @name: format specifier character (e.g., 'd', 'x', 'o', 'b')
 * @base: numerical base associated with this specifier
 * @func: pointer to function that handles this integer specifier
 *
 * Description: Router for integer-related format specifiers
 */
typedef struct i_router
{
	char name;
	int base;
	void (*func)(int_t *d);
} router_i;

/* __ MAIN ENTRY POINT __ */
int _printf(const char *format, ...);

/* __ CORE HANDLERS __ */
void _handler(data_t *data);
void handle_chars(data_t *ptr);
void handle_integers(data_t *ptr);
void print_percent(data_t *ptr);

/* __ STRING FUNCTIONS __ */
void _chars(str_t *d);
void _strings(str_t *d);
void _custom_str(str_t *d);
void _reverse_str(str_t *data);
int _strlen(char *str);

/* __INTEGER FUNCTIONS __*/

void _convert(int_t *d);
void _extract_signed(int_t *d);
void _extract_u(int_t *d);
void _extract_address(int_t *d);
char *itobase(int_t *d);
void int_to_buffer(int_t *d);

/* __ BUFFER FUNCTIONS __ */
void add_char(buffer_t *buff, char c);
void flush_buffer(buffer_t *buff);

#endif
