#include "main.h"
/**
 * format_print - function that prints
 * an argument based on its type
 * @fmt: Format string
 * @arg_num: List of arguments to be printed.
 * @index: index.
 * @holder: buffer array that handle print.
 * @flagchar: finds active flags
 * @width: get width.
 * @precision: specifier for Precision
 * @size: Sspecifier for size
 * Return: 1 or 2;
 */
int format_print(const char *fmt, int *index, va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size)
{
	int n, form_len = 0, char_len = -1;
	fmt_t fmt_types[] = {
		{'c', printChar}, {'s', printStr}, {'%', printPerC},
		{'i', printDecd}, {'d', printDecd}, {'b', print_bin},
		{'u', unsignedInt}, {'o', printOct}, {'x', printhex},
		{'X', printHEX}, {'p', printPtr}, {'S', spec_string},
		{'r', printRev}, {'R', printR13}, {'\0', NULL}
	};
	for (n = 0; fmt_types[n].fmt != '\0'; n++)
		if (fmt[*index] == fmt_types[n].fmt)
			return (fmt_types[n].fn(arg_num, holder, flagchar, width, precision, size));

	if (fmt_types[n].fmt == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		form_len += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			form_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
				--(*index);
			if (fmt[*index] == ' ')
				--(*index);
			return (1);
		}
		form_len += write(1, &fmt[*index], 1);
		return (form_len);
	}
	return (char_len);
}
