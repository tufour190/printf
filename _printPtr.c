#include "main.h"

/**
 * _printPtr - prints address allocated in memory
 * @arg_num: argument whose address is to be printed
 * Return: number of bytes
 */

int _printPtr(va_list arg_num)
{
void *ptr;
char *a = "nil";
int n, p;
long int m;

ptr = va_arg(arg_num, void*);
if (ptr == NULL)
{
for (n = 0; a[n] != '\0'; n++)
{
_putxchar(a[n]);
}
return (n);
}
m = (unsigned long int)ptr;
_putxchar('0');
_putxchar('x');
p = print_spechex(m);
return (p + 2);
}
