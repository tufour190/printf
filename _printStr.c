#include "main.h"

/**
 * printStr - prints a string
 * @arg_num: argument to be pinted
 * @holder: Buffer array to handle print
 * @flagchar:  calculates active flags
 * @width: get width.
 * @precision: specifies precision
 * @size: Specifies size
 *
 * Return: number of bytes printed
 * excluding the terminal null
 */


int printStr(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size)
{
	int n, form_len = 0;

	char *s = va_arg(arg_num, char*);

	UNUSED(holder);
	UNUSED(flagchar);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}
	while (s[form_len] != '\0')
		form_len++;

	if (precision >= 0 && precision < form_len)
		form_len = precision;

	if (width > form_len)
	{
		if (flagchar & F_MINUS)
		{
			write(1, &s[0], form_len);
			for (n = width - form_len; n > 0; n--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (n = width - form_len; n > 0; n--)
				write(1, " ", 1);
			write(1, &s[0], form_len);
			return (width);
		}
	}

	return (write(1, s, form_len));
}
