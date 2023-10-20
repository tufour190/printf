#include "main.h"

/**
 * _printD - function that prints integers
 * @arg_num: argument to be printed
 * Return: number of bytes printed
 */

int _printD(va_list arg_num)

{
int a = va_arg(arg_num, int);
int my_num, num = a % 10, digit, e = 1, n = 1;

a = a / 10;
my_num = a;

if (num < 0)
{
_putxchar('-');
my_num = -my_num;
a = -a;
num = -num;
n++;
}
if (my_num > 0)
{
while (my_num / 10 != 0)
{
e = e * 10;
my_num = my_num / 10;
}
my_num = a;
while (e > 0)
{
digit = my_num / e;
_putxchar(digit + '0');
my_num = my_num - (digit *e);
e = e / 10;
n++;
}
}
_putxchar(num + '0');
return (n);
}
