#include "main.h"

/**
 * _less - prints string
 * @c:  string to be printed
 *
 * Return: number of bytes printes
 * excluding the terminal Null
 */

int _less(char *c)
{
int char_len = 0;
if (c)
{
for (char_len = 0; c[char_len] != '\0'; char_len++)
{
_putxchar(c[char_len]);
}
}
return (char_len);
}
