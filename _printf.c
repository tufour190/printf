#include "main.h"

/**
 * _printf - function that prints to standard output
 * @format: constant first argument of the function _printf
 * Return: number of bytes printed excluding the null byte
 */

int _printf(const char *format, ...)
{
unsigned int n; /* looping through the format string */
unsigned int char_count = 0;  /* to count number of bytes printed by _printf */
unsigned int form_len = 0; /* string length count */
va_list arg_num;      /* alias for additional list of arguments */

if ((format == NULL) || ((format[0] == '%') && (format[1] == '\0')))
{
return (-1);
}
va_start(arg_num, format);

for (n = 0; format[n] != '\0'; n++)   /* parsing format specifiers */
{
if (format[n] != '%')
{
_putxchar (format[n]);
}
else if (format[n + 1] == 'c')
{
_putxchar (va_arg(arg_num, int));
n++;
}
else if (format[n + 1] == 's')
{
_less(va_arg(arg_num, char*));
form_len = _less(va_arg(arg_num, char*));
n++;
char_count += (form_len - 1); /* excludes null byte from final Char count*/
}
else if (format[n + 1] == '%')
{
_putxchar ('%');
}
char_count += 1;
}

va_end(arg_num);
return (char_count);
}
