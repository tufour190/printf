#include "main.h"

/**
 * printChar - prints a character
 * @arg_num: argument to be printed
 * @holder: Buffer array to handle print
 * @flagchar:  calculates active flags
 * @width: Width
 * @precision: Precision specifier
 * @size: Specifier for size
 *
 * Return: number of bytes printed
 */

int printChar(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size)
{
	char m;

	m = va_arg(arg_num, int);
	return (writeChar(m, holder, flagchar, width, precision, size));
}
