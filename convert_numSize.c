#include "main.h"

/**
 * convert_numSize - function that casts a number to the specified size
 * @number: number to be casted.
 * @size: This indicates the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_numSize(long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((short)number);

	return ((int)number);
}

/**
 * convert_unsignSize - function that casts a number to the specified size
 * @number: number to be casted
 * @size: This indicates the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_unsignSize(unsigned long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((unsigned short)number);

	return ((unsigned int)number);
}
