#include "main.h"

/**
 * writePtr - funtion that writes a memory address
 * @holder: buffer array of chars
 * @index: The index at which the number starts in the buffer
 * @num_len: Number length
 * @width: Width specifier
 * @flagchar: Flagchar specifier
 * @mee: Char representing the padding
 * @spec_c: Character representing extra char
 * @mee_start: the index at which padding should start
 *
 * Return: Number of written chars.
 */
int writePtr(char holder[], int index, int num_len,
	int width, int flagchar, char mee, char spec_c, int mee_start)
{
	int n;

	if (width > num_len)
	{
		for (n = 3; n < width - num_len + 3; n++)
			holder[n] = mee;
		holder[n] = '\0';
		if (flagchar & F_MINUS && mee == ' ')
		{
			holder[--index] = 'x';
			holder[--index] = '0';
			if (spec_c)
				holder[--index] = spec_c;
			return (write(1, &holder[index], num_len) + write(1, &holder[3], n - 3));
		}
		else if (!(flagchar & F_MINUS) && mee == ' ')
		{
			holder[--index] = 'x';
			holder[--index] = '0';
			if (spec_c)
				holder[--index] = spec_c;
			return (write(1, &holder[3], n - 3) + write(1, &holder[index], num_len));
		}
		else if (!(flagchar & F_MINUS) && mee == '0')
		{
			if (spec_c)
				holder[--mee_start] = spec_c;
			holder[1] = '0';
			holder[2] = 'x';
			return (write(1, &holder[mee_start], n - mee_start) +
				write(1, &holder[index], num_len - (1 - mee_start) - 2));
		}
	}
	holder[--index] = 'x';
	holder[--index] = '0';
	if (spec_c)
		holder[--index] = spec_c;
	return (write(1, &holder[index], BUFF_SIZE - index - 1));
}
