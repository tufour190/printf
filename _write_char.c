#include "main.h"

/**
 * writeChar - function that writes a string
 * @f: char types.
 * @holder: Buffer array to handle print
 * @flagchar:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int writeChar(char f, char holder[],
	int flagchar, int width, int precision, int size)
{
	int n = 0;
	char mee = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flagchar & F_ZERO)
		mee = '0';

	holder[n++] = f;
	holder[n] = '\0';

	if (width > 1)
	{
		holder[BUFF_SIZE - 1] = '\0';
		for (n = 0; n < width - 1; n++)
			holder[BUFF_SIZE - n - 2] = mee;

		if (flagchar & F_MINUS)
			return (write(1, &holder[0], 1) +
					write(1, &holder[BUFF_SIZE - n - 1], width - 1));
		else
			return (write(1, &holder[BUFF_SIZE - n - 1], width - 1) +
					write(1, &holder[0], 1));
	}

	return (write(1, &holder[0], 1));
}
