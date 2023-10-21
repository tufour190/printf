#include "main.h"

/**
 * printDec - function that prints integers
 * @arg_num: arguments to be printed
 * @holder: buffer array to handle print
 * @flagchar:  calculates active flags
 * @width: get width.
 * @precision: specifier for precision
 * @size: specifier for size
 *
 * Return: number of bytes printed
 */

int printDec(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size)
{
	int n = BUFF_SIZE - 2;
	int is_neg = 0;
	long int a = va_arg(arg_num, long int);
	unsigned long int number;

	a = convert_numSize(a, size);

	if (a == 0)
		holder[n--] = '0';

	holder[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)a;

	if (a < 0)
	{
		number = (unsigned long int)((-1) * a);
		is_neg = 1;
	}

	while (number > 0)
	{
		holder[n--] = (number % 10) + '0';
		number /= 10;
	}

	n++;

	return (writeNumber(is_neg, n, holder, flagchar, width, precision, size));
}

