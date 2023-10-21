#include "main.h"

void print_buffer(char holder[], int *buff_index);

/**
 * _printf - Printf function that mimics stdout function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int n, form_len = 0, printed_chars = 0;
	int flagchar, width, precision, size, buff_index = 0;
	va_list arg_num;
	char holder[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(arg_num, format);

	for (n = 0; format && format[n] != '\0'; n++)
	{
		if (format[n] != '%')
		{
			holder[buff_index++] = format[n];
			if (buff_index == BUFF_SIZE)
				print_buffer(holder, &buff_index);

			printed_chars++;
		}
		else
		{
			print_buffer(holder, &buff_index);
			flagchar = flags_printf(format, &n);
			width = width_printf(format, &n, arg_num);
			precision = precision_printf(format, &n, arg_num);
			size = size_printf(format, &n);
			++n;
			form_len = format_printf(format, &n, arg_num, holder,
				flagchar, width, precision, size);
			if (form_len == -1)
				return (-1);
			printed_chars += form_len;
		}
	}

	print_buffer(holder, &buff_index);

	va_end(arg_num);

	return (printed_chars);
}

/**
 * print_buffer - function that
 * Prints the contents of the buffer if it exist
 * @holder: buffer array of chars
 * @buff_index: Index at which next char is added
 * , represents the length.
 */
void print_buffer(char holder[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &holder[0], *buff_index);

	*buff_index = 0;
}
