#include "main.h"

/**
 * printPtr - prints address allocated in memory
 * @arg_num: argument whose address is to be printed
 * @holder: buffer array to handle print
 * @flagchar:  calculates active flags
 * @width: get width
 * @precision: specifier for precision
 * @size: Specifier for size
 *
 * Return: number of bytes
 */

int printPtr(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size)
{
	char spec_c = 0, mee = ' ';
	int index = BUFF_SIZE - 2, length = 2, mee_start = 1;
	unsigned long addrs_num;
	char link_to[] = "0123456789abcdef";
	void *addrs = va_arg(arg_num, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	holder[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	addrs_num = (unsigned long)addrs;

	while (addrs_num > 0)
	{
		holder[index--] = link_to[addrs_num % 16];
		addrs_num /= 16;
		length++;
	}

	if ((flagchar & F_ZERO) && !(flagchar & F_MINUS))
		mee = '0';
	if (flagchar & F_PLUS)
		spec_c = '+', length++;
	else if (flagchar & F_SPACE)
		spec_c = ' ', length++;

	index++;

	return (writePtr(holder, index, length, width, flagchar, mee,
						spec_c, mee_start));
}
