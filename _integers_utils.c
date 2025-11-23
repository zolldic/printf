#include "main.h"
#include <stdlib.h>

/**
 * _convert - converts integer data to string representation
 * @d: pointer to integer_t struct containing number and base info
 * @buff: pointer to buffer_t struct for output
 */
void _convert(integer_t *d, buffer_t *buff)
{
	integer_t ptr;
	int x = 0;
	char digits[16] = "0123456789abcdef";

	if (d->is_cap == 1)
		for (x = 10; x < 16; x++)
			digits[x] = digits[x] - 32;
	x = 0;

	ptr.num = d->num;
	ptr.base = d->base;

	ptr.res = (char *) malloc(sizeof(char) * 64);

	if (!ptr.res)
		return;
	while (ptr.num != 0)
	{
		ptr.res[x] = digits[ptr.num % ptr.base];
		ptr.num /= ptr.base;
		x++;
	}
	ptr.size = x;

	int_to_buffer(&ptr, buff);
}

