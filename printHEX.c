#include "main.h"

/**
 * _printHEX - converts a number into a HEXAdecimal
 * @arg_num: number to be converted
 * Return: count of HEXAdecimal digits
 */

int _printHEX(va_list arg_num)
{
int *arr;
int n, num_digit = 0;
unsigned int a = va_arg(arg_num, unsigned int);
unsigned int tmp = a;

while (a / 16 != 0)
{
a = a / 16;
num_digit++;
}
num_digit++;
arr = malloc(sizeof(int) * num_digit);
for (n = 0; n < num_digit; n++)
{
arr[n] = tmp % 16;
tmp = tmp / 16;
}
for (n = num_digit - 1; n >= 0; n++)
{
if (arr[n] > 9)
{

arr[n] = arr[n] + 7;
}
_putxchar(arr[n] + '0');
}
free(arr);
return (num_digit);
}
