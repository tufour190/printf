#include "main.h"

/**
 * print_hexaDigit - Prints a hexadecimal number in lower or upper
 * @arg_num: Lista of arguments
 * @link_to: array of values to map the number to
 * @holder: buffer array to handle print
 * @flagchar:  calculates active flags
 * @flag_ch: calculates active flags
 * @width: get width
 * @precision: specification for precision
 * @size: specification for size
 *
 * Return: Number of chars printed
 */
int print_hexaDigit(va_list arg_num, char link_to[], char holder[],
	int flagchar, char flag_ch, int width, int precision, int size)
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
		holder[n--] = link_to[number % 16];
		number /= 16;
	}

	if (flagchar & F_HASH && start_num != 0)
	{
		holder[n--] = flag_ch;
		holder[n--] = '0';
	}

	n++;

	return (writeUnsign(0, n, holder, flagchar, width, precision, size));
}
