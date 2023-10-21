#include "main.h"

/**
 * print_bin - converts unsigned int arg to binary
 * @arg_num: int to be converted to binary
 * @holder: buffer array to handle print
 * @flagchar:  calculates active flags
 * @width: get width.
 * @precision: specifier for precision
 * @size: specifier for size
 *
 * Return: integer
 */

int print_bin(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size)
{
	int num_bit = 0; /*bit size */
	unsigned int i, n, a;
	unsigned int temp;  /*temporary stores result of bitwise operation */
	unsigned int b[32];

	UNUSED(holder);
	UNUSED(flagchar);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	a = va_arg(arg_num, unsigned int);
	n = 2147483648;
	b[0] = a / n;
	for (i = 1; i < 32; i++)
	{
		n /= 2;
		b[i] = (a / n) % 2;
	}
	for (i = 0, temp = 0, num_bit = 0; i < 32; i++)
	{
		temp += b[i];
		if (temp || i == 31)
		{
			char c = '0' + b[i];

			write(1, &c, 1);
			num_bit++;
		}
	}
	return (num_bit);
}
