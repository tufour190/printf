#include "main.h"

/**
 * flags_printf - finds active flags
 * @format: the Format string arguments
 * @n: take a parameter.
 * Return: flags:
 */
int flags_printf(const char *format, int *n)
{

	int m, curr_n;
	int flagchar = 0;
	const char FLAG_Char[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_Arr[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_n = *n + 1; format[curr_n] != '\0'; curr_n++)
	{
		for (m = 0; FLAG_Char[m] != '\0'; m++)
			if (format[curr_n] == FLAG_Char[m])
			{
				flagchar |= FLAG_Arr[m];
				break;
			}

		if (FLAG_Char[m] == 0)
			break;
	}

	*n = curr_n - 1;

	return (flagchar);
}
