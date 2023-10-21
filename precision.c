#include "main.h"

/**
 * precision-printf - function that defines the precision for printing
 * @format: Format string
 * @n: argument
 * @arg_num: list of arguments.
 *
 * Return: Precision.
 */
int precision_printf(const char *format, int *n, va_list arg_num)
{
	int curr_n = *n + 1;
	int precision = -1;

	if (format[curr_n] != '.')
		return (precision);

	precision = 0;

	for (curr_n += 1; format[curr_n] != '\0'; curr_n++)
	{
		if (is_digit(format[curr_n]))
		{
			precision *= 10;
			precision += format[curr_n] - '0';
		}
		else if (format[curr_n] == '*')
		{
			curr_n++;
			precision = va_arg(arg_num, int);
			break;
		}
		else
			break;
	}

	*n = curr_n - 1;

	return (precision);
}
