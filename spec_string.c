#include "main.h"

/**
 * _specstring - prints a string of special char
 * @arg_num: special charater to be printed
 * Return: number of bytes printed
 */

int _specstring(va_list arg_num)
{
char *str;
int n, string_len = 0, tmp;
str = va_arg(arg_num,  char*);
if (str == NULL)
{
str = 'null';
}
for (n = 0; str[n] != '\0'; n++)
{
if (str[n] < 32 || str[n] >= 127)
{
_putxchar('\\');
_putxchar('x');
string_len = string_len + 2;
tmp = str[n];
if (tmp < 16)
{
_putxchar('0');
string_len++;
}
string_len = string_len + print_spec_HEX(tmp);
}
else
{
_putxchar(str[n]);
string_len++;
}
}
return (string_len);
}
