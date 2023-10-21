#include "main.h"

/**
 * printRev - prints a string in reverse
 * @arg_num: argument passed to the function
 * @holder: buffer array to handle print
 * @flagchar:  calculates active flags
 * @width: get width
 * @precision: specifier for precision
 * @size: specifier for size
 *
 * Return: the reverse printed string
 */

int printRev(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size)
{
	char *s;
	int n, str_len = 0;

	UNUSED(holder);
	UNUSED(flagchar);
	UNUSED(width);
	UNUSED(size);

	s = va_arg(arg_num, char *);

	if (s == NULL)
	{
		UNUSED(precision);

		s = ")Null(";
	}
	for (n = 0; s[n]; n++)
		;

	for (n = n - 1; n >= 0; n--)
	{
		char a = s[n];

		write(1, &a, 1);
		str_len++;
	}
	return (str_len);
}
