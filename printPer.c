#include "main.h"

/**
 * printPerC - print percent sign
 * @arg_num: arguments
 * @holder: Buffer array to handle print
 * @flagchar:  calculates active flags
 * @width: get width.
 * @precision: Specifier for precision
 * @size: Specifier for size
 *
 * Return: number of bytes printed
 */

int printPerC(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size)
{
	UNUSED(arg_num);
	UNUSED(holder);
	UNUSED(flagchar);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
