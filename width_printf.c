#include "main.h"

/**
 * width_print - function that finds the width for printing
 * @format: Formatted string
 * @n:  arguments to be printed.
 * @arg_num: list of arguments.
 *
 * Return: width.
 */
int width_print(const char *format, int *n, va_list arg_num)
{
	int curr_n;
	int width = 0;

	for (curr_n = *n + 1; format[curr_n] != '\0'; curr_n++)
	{
		if (is_digit(format[curr_n]))
		{
			width *= 10;
			width += format[curr_n] - '0';
		}
		else if (format[curr_n] == '*')
		{
			curr_n++;
			width = va_arg(arg_num, int);
			break;
		}
		else
			break;
	}

	*n = curr_n - 1;

	return (width);
}
