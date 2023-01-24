#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024
void print_int_number(int);
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
#endif/*MAIN_H*/
