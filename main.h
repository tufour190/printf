#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAG specifiers */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZE specifiers */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int format_printf(const char *fmt, int *n,
va_list arg_num, char holder[], int flagchar,
		int width, int precision, int size);
int printChar(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size);
int printStr(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size);
int printPerC(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size);
int printDec(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size);
int print_bin(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size);
int unsignedInt(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size);
int printOct(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size);
int printhex(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size);
int printHEX(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size);

int print_hexaDigit(va_list arg_num, char link_to[],
char holder[], int flagchar, char flag_ch, int width, int precision, int size);

int spec_string(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size);
int printPtr(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size);

int flags_printf(const char *format, int *n);
int width_printf(const char *format, int *n, va_list arg_num);
int precision_printf(const char *format, int *n, va_list arg_num);
int size_printf(const char *format, int *n);

int printRev(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size);

int printR13(va_list arg_num, char holder[],
	int flagchar, int width, int precision, int size);

/* functions that control width  */
int writeChar(char f, char holder[],
	int flagchar, int width, int precision, int size);
int writeNumber(int is_neg, int index, char holder[],
	int flagchar, int width, int precision, int size);
int writeNum(int index, char holder[], int flagchar, int width, int prec,
	int num_len, char mee, char spec_c);
int writePtr(char holder[], int index, int num_len,
	int width, int flagchar, char mee, char spec_c, int mee_start);

int writeUnsign(int is_neg, int index, char holder[], int flagchar,
			int width, int precision, int size);

int _printable(char m);
int add_hexaCode(char ascii_code, char holder[], int n);
int is_digit(char c);
int _putxchar (char c);
long int convert_numSize(long int number, int size);
long int convert_unsignSize(unsigned long int number, int size);
int _strlen(char *s);


#endif
