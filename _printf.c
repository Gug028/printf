#include "main.h"
#include <stdio.h>

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: Format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{

	int printed_chars = 0;
	int buff_ind = 0;
	va_list mylist;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(mylist, format);

	for (printed_chars = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFFER_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			i++;
			if (format[i] == '\0')
			{
				va_end(mylist);
				return (-1);
			}
			if (printed_chars == -1)
				return (-1);
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(mylist);
	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add the next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
	}
	*buff_ind = 0;
}
