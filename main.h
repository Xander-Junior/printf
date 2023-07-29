#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUFF 1024

int _printf(const char *format, ...);
int _print_str(char *str);
int _putchar(char c);
int _print_int(int n);
int _print_octal(unsigned int num);
int _print_hex(unsigned int num, int uppercase);
int _print_unsigned(unsigned int num);
int _print_address(void *ptr);

#endif /* MAIN_H */
