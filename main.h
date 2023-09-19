#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * struct fmt - Struct op
 *
 * @fmt: format.
 * @fn: function associated
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - struct op
 *
 * @fmt: format
 * @fm_t: function associated
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *n, va_list mylist, char buffer[]);
void print_buffer(char buffer[], int *buff_ind);

#endif /* MAIN_H */
