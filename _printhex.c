#include "main.h"

/**
 * printhex - converts a number into a hexadecimal
 * @arg_num: number to be converted
 * @holder: buffer array to handle print
 * @flagchar:  calculates active flags
 * @width: get width
 * @precision: specifier for precision
 * @size: specifier for size
 *
 * Return: count of hexadecimal digits
 */

int printhex(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size)
{
	return (print_hexaDigit(arg_num, "0123456789abcdef", holder,
		flagchar, 'x', width, precision, size));
}
