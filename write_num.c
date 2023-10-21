#include "main.h"

/**
 * writeNum - function that write a number using a bufffer
 * @index: the index at which the number starts on the buffer
 * @holder: Buffer array
 * @flagchar: Flag characters
 * @width: width
 * @prec: specifies precision
 * @num_len: length of number
 * @mee: Pading char
 * @spec_c: An extra char
 *
 * Return: Number of printed chars.
 */
int writeNum(int index, char holder[],
	int flagchar, int width, int prec,
	int num_len, char mee, char spec_c)
{
	int n, mee_start = 1;

	if (prec == 0 && index == BUFF_SIZE - 2 && holder[index] == '0' && width == 0)
		return (0);
	if (prec == 0 && index == BUFF_SIZE - 2 && holder[index] == '0')
		holder[index] = mee = ' ';
	if (prec > 0 && prec < num_len)
		mee = ' ';
	while (prec > num_len)
		holder[--index] = '0', num_len++;
	if (spec_c != 0)
		num_len++;
	if (width > num_len)
	{
		for (n = 1; n < width - num_len + 1; n++)
			holder[n] = mee;
		holder[n] = '\0';
		if (flagchar & F_MINUS && mee == ' ')
		{
			if (spec_c)
				holder[--index] = spec_c;
			return (write(1, &holder[index], num_len) + write(1, &holder[1], n - 1));
		}
		else if (!(flagchar & F_MINUS) && mee == ' ')
		{
			if (spec_c)
				holder[--index] = spec_c;
			return (write(1, &holder[1], n - 1) + write(1, &holder[index], num_len));
		}
		else if (!(flagchar & F_MINUS) && mee == '0')
		{
			if (spec_c)
				holder[--mee_start] = spec_c;
			return (write(1, &holder[mee_start], n - mee_start) +
				write(1, &holder[index], num_len - (1 - mee_start)));
		}
	}
	if (spec_c)
		holder[--index] = spec_c;
	return (write(1, &holder[index], num_len));
}
