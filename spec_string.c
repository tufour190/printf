#include "main.h"

/**
 * spec_string - prints a string of special char
 * @arg_num: special charater to be printed
 * @holder: buffer array to handle print
 * @flagchar:  calculates active flags
 * @width: get width
 * @precision: specifier for precision
 * @size: specifier for size
 *
 * Return: number of bytes printed
 */

int spec_string(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size)
{
	int n = 0, p = 0;
	char *s = va_arg(arg_num, char *);

	UNUSED(flagchar);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		return (write(1, "(null)", 6));

	while (s[n] != '\0')
	{
		if (_pintable(s[n]))
			holder[n + p] = s[n];
		else
			p += add_hexaCode(s[n], holder, n + p);

		n++;
	}

	holder[n + p] = '\0';

	return (write(1, holder, n + p));
}
