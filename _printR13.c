#include "main.h"

/**
 * _printR13 - prints prints the rot13'ed string
 * @argnum: argument passed onto the function
 * Return: number of characters printed
 */

int _printR13(va_list arg_num)
{
int n, m, p, char_len = 0;
char *fmt = va_arg(arg_num, char*);
char a[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
char b[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

if (fmt == NULL)
{
fmt = "(null)";
}
for (n = 0; fmt[n]; n++)
{
p = 0;
for (m = 0; a[m] && !p; m++)
{
if (fmt[n] == a[m])
{
_putxchar(b[m]);
char_len++;
p++;
}
}
if (!p)
{
_putxchar(fmt[n]);
char_len++;
}
}
return (char_len);
}
