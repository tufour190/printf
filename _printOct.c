#include "main.h"

/**
 * printOct - converts an unsigned number into a octadecimal
 * @arg_num: number to be converted to octadecimal
 * @holder: buffer array to handle print
 * @flagchar:  calculates active flags
 * @width: get width
 * @precision: specifier for precision
 * @size: specifier for size
 *
 * Return: count of octal digits
 */

int printOct(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size)
{
	int n = BUFF_SIZE - 2;
	unsigned long int number = va_arg(arg_num, unsigned long int);
	unsigned long int start_num = number;

	UNUSED(width);

	number = convert_unsignSize(number, size);

	if (number == 0)
		holder[n--] = '0';

	holder[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		holder[n--] = (number % 8) + '0';
		number /= 8;
	}

	if (flagchar & F_HASH && start_num != 0)
		holder[n--] = '0';

	n++;

	return (writeUnsign(0, n, holder, flagchar, width, precision, size));
}
