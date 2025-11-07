#include "main.h"

/**
* print_char - print a character to STDOUT
* @ap: list of unkown arguments passed to _printf
* Return: count of bytes printed in STDOUT
*/
int print_char(va_list ap)
{
	char c =  va_arg(ap, int);

	return (write(STDOUT, &c, 1));
}

/**
* print_str - print a string to STDOUT
* @ap: list of unkown arguments passed to _printf
* Return: count of bytes printed in STDOUT
*/
int print_str(va_list ap)
{
	int count = 0;
	char *str = va_arg(ap, char *);
	if (!str)
		str = "(null)";

	while (*str != '\0')
	{
		count += write(STDOUT, str, 1);
		str++;
	}

	return (count);
}

/**
* print_percent - print percent sign to STDOUT
* @ap: list of unkown arguments passed to _printf
* Return: count of bytes printed in STDOUT
*/
int print_percent(va_list ap)
{
	(void) ap;

	return (write(STDOUT, "%", 1));
}
