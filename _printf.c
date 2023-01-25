#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define BUFFSIZE 1024

void print_buffer(char buffer[], int *buff_ind);
/**
 * _strlen - finds the string length
 * @s: character
 * @l: string length
 * Return: return l
 */
int _strlen(char *s)
{
	int l;

	l = 0;

	if (!s)
		return (0);
	while (*s != '\0')
	{
		++l;
		++s;
	}
	return (l);
}
/**
 * _printf - to print
 * @format: character string
 * Return: Printed characters
 */
int _printf(const char *format, ...)
{
	int i, len, buff_index = 0, pc = 0;
	char c, *s;/*temp char value*/
	va_list list;
	char buffer[BUFFSIZE];

	va_start(list, format);

	if (format == NULL)
		return (-1);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFFSIZE)
				print_buffer(buffer, &buff_index);
					pc++;
		} /*end if*/
		else
		{
			print_buffer(buffer, &buff_index);
			i++;/* check next character after "%"*/
			switch (format[i])
			{
				case 'c':
					c = va_arg(list, int);
					write(1, &c, 1);
					pc++;
					break;
				case ' ':/* if just "%"*/
					c = va_arg(list, int);
					write(1, "%%", 1);
					pc++;
					break;
				case 's':
					s = va_arg(list, char *);
					len = _strlen(s);
					print_buffer(s, &len);
					pc += _strlen(s);
					break;
				case 'i':
				case 'd':
					printnt_int_number(va_arg(list, int));
					pc++;
					break;
				default:
					break;
			} /*end switch*/
		} /*end else*/
	} /*end for*/
	print_buffer(buffer, &buff_index);
	va_end(list);
	/*return (printed_chars);*/
	return (pc);
} /*end _printf()*/
/**
 * print_buffer - to print the variables in a buffer
 * @buffer: array of characters
 * @buff_ind: buffer index
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
/**
 * print_int_number - handles integer number printing
 * @n: int parameter
 */
void print_int_number(int n)
{
	unsigned int n1;
	char temp;

	n1 = n;
	if (n < 0)
	{
		write(1, "-", 1);
		n1 = -n;
	}
	if (n1 / 10 != 0)
	{
		print_int_number(n1 / 10);
	}
	temp = ((n1 % 10) + '0');
	write(1, &temp, 1);
}
