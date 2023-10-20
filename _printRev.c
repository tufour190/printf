#include "main.h"

/**
 * printRev - prints a string in reverse
 * @arg_num: argument passed to the function
 * Return: the reverse printed string
 */

int printRev(va_list arg_num)
{
char *fmt = va_arg(arg_num, char*);
int n, m = 0;

if (fmt == NULL)
{
fmt = "(null)";
}
while (fmt[m] != '\0')
{
m++;
}
for (n = m - 1; n >= 0; n--)
{
_putxchar(fmt[n]);
}
return (m);
}
