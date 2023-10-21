#include "main.h"

/**
 * _putxchar - prints the character c to standard output
 * @c: The character to be printed
 *
 * Return: On success 1 and -1 when there is error
 */

int _putxchar(char c)
{
	return (write(1, &c, 1));
}
