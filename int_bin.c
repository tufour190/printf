#include "main.h"

/**
 * int_bin - converts unsigned int arg to binary
 *
 * Return: integer
 */

int int_bin(va_list arg_num)
{
int flag = 0; // tracking 0 flags
int num_bit = 0; //bit size
int n, m = 1, c; // c-value of current bit , n for looping, m
unsigned int a = va_arg(arg_num, unsigned int);
unsigned int temp;  //temporary stores result of bitwise operation

for (n = 0; n < 32; n++) //unsigned int is 32 byte
{
temp = ((m << (32 - n)) & a);
if (temp >> (31 - n))
{
flag = 1;
}
if (flag)
{
c = temp >> (31 - n);
_putxchar(c + 48);
num_bit++;
}
}
if (num_bit == 0)
{
num_bit++;
_putxchar('0');
}
return (num_bit);
}
