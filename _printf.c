#include "main.h"
#include <stdio.h>
#include <stdarg.h>

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Prints output
 * @format: pointer to string
 * Return: characters printed.
 */
int _printf(const char *format, ...)
{
	int print_char = 0;
	int n, buff_ind = 0;
	va_list mylist;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(mylist, format);

	for (n = 0; format && format[n] != '\0'; n++)
	{
		if (format[n] != '%')
		{
			buffer[buff_ind++] = format[n];
			if (buff_ind == BUFFER_SIZE)
			{
				print_buffer(buffer, &buff_ind);
			}

			print_char++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			++n;

			if (format[n] == '\0')
				return (-1);
			if (format[n] == '%')
			{
				buffer[buff_ind++] = format[n];
				print_char++;
			}
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(mylist);
	return (print_char);
}

/**
 * print_buffer - Prints contents of buffer
 * @buffer: array of characters
 * @buff_ind: array length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
	}
	*buff_ind = 0;
}
