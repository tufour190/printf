#include "main.h"

/**
 * printHEX - converts a number into a HEXAdecimal
 * @arg_num: number to be converted
 * @holder: buffer array to handle print
 * @flagchar:  calculates active flags
 * @width: get width
 * @precision: Precision specifier
 * @size: Size specification
 *
 * Return: count of HEXAdecimal digits
 */

int printHEX(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size)
{
	return (print_hexaDigit(arg_num, "0123456789ABCDEF", holder,
		flagchar, 'X', width, precision, size));
}
