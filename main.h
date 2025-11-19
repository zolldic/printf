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
 * @array: dynamically allocated array storing binary digits
 * @size: number of binary digits in the array
 * @is_negative: flag indicating if original number was negative (1) or not (0)
 *
 * Description: This structure stores the binary representation of an integer.
 */
typedef struct binary_data
{
	int *array;	
	int size;
	int is_negative;
} binary_t;



/* main entry point */
int _printf(const char *format, ...);


/* custom print functions */

int print_str(va_list ap);
int print_percent(va_list ap);
int print_integer(va_list ap);
int print_binary(va_list ap);


binary_t *convert_to_binary(int n, unsigned int size);
int print_digit(long nmbr);

/* __utils__ */
int _check_specifier(char c);
void add_char(buffer_t *buff, char c);
void flush_buffer(buffer_t *buff);

#endif
