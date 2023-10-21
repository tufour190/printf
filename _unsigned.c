#include "main.h"

/**
 * unsignedInt - function that prints integers
 * @arg_num: argument to be printed
 * @holder: buffer array to handle print
 * @flagchar:  calculates active flags
 * @width: get width
 * @precision: Specifier for precision
 * @size: Specifier for size
 *
 * Return: number of bytes printed
 */

int unsignedInt(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size)
{
	int n = BUFF_SIZE - 2;

	unsigned long int number = va_arg(arg_num, unsigned long int);

	number = convert_unsignSize(number, size);

	if (number == 0)
		holder[n--] = '0';

	holder[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		holder[n--] = (number % 10) + '0';
		number /= 10;
	}

	n++;

	return (writeUnsign(0, n, holder, flagchar, width, precision, size));
}
