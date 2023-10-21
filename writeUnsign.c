#include "main.h"

/**
 * writeUnsign - function that writes an unsigned number
 * @is_neg: indiates whether a num is negative
 * @index: Index at which the number starts in the buffer
 * @holder: An buffer array of characters
 * @flagchar: Flag characters
 * @width: Width specifier
 * @precision: Specifies precision
 * @size: Specifies size
 *
 * Return: Number of written chars.
 */
int writeUnsign(int is_neg, int index,
	char holder[],
	int flagchar, int width, int precision, int size)
{
	int num_len = BUFF_SIZE - index - 1, n = 0;
	char mee = ' ';

	UNUSED(is_neg);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && holder[index] == '0')
		return (0);
	if (precision > 0 && precision < num_len)
		mee = ' ';

	while (precision > num_len)
	{
		holder[--index] = '0';
		num_len++;
	}

	if ((flagchar & F_ZERO) && !(flagchar & F_MINUS))
		mee = '0';

	if (width > num_len)
	{
		for (n = 0; n < width - num_len; n++)
			holder[n] = mee;

		holder[n] = '\0';

		if (flagchar & F_MINUS)
		{
			return (write(1, &holder[index], num_len) + write(1, &holder[0], n));
		}
		else
		{
			return (write(1, &holder[0], n) + write(1, &holder[index], num_len));
		}
	}

	return (write(1, &holder[index], num_len));
}
