#include "main.h"

/**
 * writeNumber - function that writes a string
 * @is_neg: arguments
 * @index: char
 * @holder: buffer array to handle write function
 * @flagchar:  calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: specifies size
 *
 * Return: Number of chars printed.
 */
int writeNumber(int is_neg, int index, char holder[],
	int flagchar, int width, int precision, int size)
{
	int form_len = BUFF_SIZE - index - 1;
	char mee = ' ', spec_ch = 0;

	UNUSED(size);

	if ((flagchar & F_ZERO) && !(flagchar & F_MINUS))
		mee = '0';
	if (is_neg)
		spec_ch = '-';
	else if (flagchar & F_PLUS)
		spec_ch = '+';
	else if (flagchar & F_SPACE)
		spec_ch = ' ';

	return (writeNum(index, holder, flagchar, width, precision,
		form_len, mee, spec_ch));
}
