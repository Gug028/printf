#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * struct fmt - Struct op
 *
 * @fmt: the format
 * @fn: the function associated
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: the format
 * @fm_t: the function associated
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);

#endif /* MAIN_H */
