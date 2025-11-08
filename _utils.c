#include "main.h"

/**
* print_digit - print the digit to STDOUT
* @nmbr: the number to print
* Return: count of bytes printed to STDOUT
*/

int print_digit(long nmbr)
{
	int count = 0;

	if (nmbr < 0)
	{
		count += write(STDOUT, "-", 1);
		nmbr = nmbr * (-1);
	}

	if (nmbr < 10)
	{
		nmbr = nmbr + '0';
		count += write(STDOUT, &nmbr, 1);
	}
	else
	{
		count += print_digit(nmbr / 10);
		nmbr = (nmbr % 10) + '0';
		count += write(STDOUT, &nmbr, 1);
	}

	return (count);
}
