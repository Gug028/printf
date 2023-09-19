#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);

#endif /* MAIN_H */
