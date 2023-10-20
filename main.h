#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int _printf(const char *format, ...);
int _putxchar (char c);
int _less(char *c);
int _printDec(va_list arg_num);
int _printD(va_list arg_num);
int int_bin(va_list arg_num);
int _unsignedInt(va_list arg_num);
int _printOct(va_list arg_num);
int _printhex(va_list arg_num);
int _printHEX(va_list arg_num);
int _specstring(va_list arg_num);
int print_spec_HEX(unsigned int value);



#endif
