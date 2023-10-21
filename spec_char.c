#include "main.h"

/**
 * _printable - function that checks whether a char is printable
 * @m: Char to be checked.
 *
 * Return: 1 if character is printable,  otherwise 0
 */
int _printable(char m)
{
	if (m >= 32 && m < 127)
		return (1);

	return (0);
}

/**
 * add_hexaCode - function that append ascci in hexadecimal to buffer
 * @holder: buffer array of characters
 * @n: the index at which appending starts.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int add_hexaCode(char ascii_code, char holder[], int n)
{
	char link_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	holder[n++] = '\\';
	holder[n++] = 'x';

	holder[n++] = link_to[ascii_code / 16];
	holder[n] = link_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
