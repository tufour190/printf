#include "main.h"

/**
 * print_spechex - converts to a hexadecimal
 * @value: number to be converted
 * Return: count of hexadecimal digits
 */

int print_spechex(unsigned long int value)
{
long int *arr;
long int n, num_digit = 0;
unsigned long int a;
unsigned long int tmp = a;

while (a / 16 != 0)
{
a = a / 16;
num_digit++;
}
num_digit++;
arr = malloc(sizeof(long int) * num_digit);
for (n = 0; n < num_digit; n++)
{
arr[n] = tmp % 16;
tmp = tmp / 16;
}
for (n = num_digit - 1; n >= 0; n++)
{
if (arr[n] > 9)
{

arr[n] = arr[n] + 39;
}
_putxchar(arr[n] + '0');
}
free(arr);
return (num_digit);
}
