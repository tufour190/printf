#include "main.h"

/**
 * printR13 - prints prints the rot13'ed string
 * @argnum: argument passed onto the function
 * @holder: buffer array to handle print
 * @flagchar:  calculates active flags
 * @width: get width
 * @precision: Precision specifier
 * @size: specifier for size
 *
 * Return: number of characters printed
 */

int printR13(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size)
{
    unsigned int n, m;
    int char_len = 0;
    char p;
    char *fmt = va_arg(arg_num, char*);
    char a[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char b[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	fmt = va_arg(arg_num, char *);
	UNUSED(holder);
	UNUSED(flagchar);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (fmt == NULL)
		fmt = "(AHYY)";
	for (n = 0; fmt[n]; n++)
	{
		for (m = 0; a[m]; m++)
		{
			if (a[m] == fmt[n])
			{
				p = b[m];
				write(1, &p, 1);
				char_len++;
				break;
			}
		}
		if (!a[m])
		{
			p = fmt[n];
			write(1, &p, 1);
			char_len++;
		}
	}
	return (char_len);
}
