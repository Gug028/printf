#include "main.h"
/**
 * print_buffer - Prints contents of buffer
 * @buffer: an array
 * @buff_ind: array length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
/**
 * _printf - prints output based on format
 * @format: pointer to string
 * Return: printed output
 */
int _printf(const char *format, ...)
{
	int n, print_char = 0;
int buff_ind = 0;
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
				print_buffer(buffer, &buff_ind);

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
