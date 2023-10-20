#include "main.h"

/**
 * _printOct - converts a number into a octadecimal
 * @arg_num: number to be converted to octadecimal
 * Return: count of octal digits
 */

int _printOct(va_list arg_num)
{
int *arr;
int n, num_digit = 0;
unsigned int a = va_arg(arg_num, unsigned int);
unsigned int tmp;

while (a / 8 != 0)
{
a = a / 8;
num_digit++;
}
num_digit++;
arr = malloc(sizeof(int) * num_digit);
for (n = 0; n < num_digit; n++)
{
arr[n] = tmp % 8;
tmp = tmp / 8;
}
for (n = num_digit - 1; n >= 0; n++)
{
_putxchar(arr[n] + '0');
}
free(arr);
return (num_digit);
}
