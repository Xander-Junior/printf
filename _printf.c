#include "main.h"
#include <stdio.h>
#include <stdint.h>

/**
 * _putchar - A function that prints a character to stdout
 * @c: The character to print
 *
 * Return: The number of characters printed (always 1)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _printf - Custom implementation of printf function
 * @format: The format string
 *
 * Return: The number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					count += _print_str(va_arg(args, char *));
					break;
				case 'd':
				case 'i':
					count += _print_int(va_arg(args, int));
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				case 'u':
					count += _print_unsigned(va_arg(args, unsigned int));
					break;
				case 'o':
					count += _print_octal(va_arg(args, unsigned int));
					break;
				case 'p':
					count += _print_address(va_arg(args, void *));
					break;
				case 'x':
				case 'X':
					count += _print_hex(va_arg(args, unsigned int), (*format == 'X'));
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
		}
		format++;
	}

	va_end(args);
	return (count);
}



/**
 * _print_str - Print a string to stdout
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
int _print_str(char *str)
{
	int len = 0;

	while (str && str[len])
	{
		_putchar(str[len]);
		len++;
	}
	return (len);
}


/**
 * _print_int - Print an integer to stdout
 * @num: The integer to print
 *
 * Return: The number of characters printed
 */
int _print_int(int num)
{
	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}

	if (num / 10)
		count += _print_int(num / 10);

	_putchar('0' + num % 10);
	count++;

	return (count);
}

/**
 * _print_unsigned - Print an unsigned integer to stdout
 * @num: The unsigned integer to print
 *
 * Return: The number of characters printed
 */

int _print_unsigned(unsigned int num)
{
	int count = 0;

	if (num / 10)
		count += _print_unsigned(num / 10);

	_putchar('0' + num % 10);
	count++;


	return (count);
}


/**
 * _print_octal - Print an unsigned integer in octal format to stdout
 * @num: The unsigned integer to print
 *
 * Return: The number of characters printed
 */
int _print_octal(unsigned int num)
{
	int count = 0;
	char buffer[BUFF];
	int len = 0;


	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num != 0)
	{
		buffer[len] = (num % 8) + '0';
		num /= 8;
		len++;
	}

	while (len > 0)
	{
		len--;
		_putchar(buffer[len]);
		count++;
	}

	return (count);
}

/**
 * _print_hex - Print an unsigned integer in hexadecimal format to stdout
 * @num: The unsigned integer to print
 * @uppercase: A flag indicating whether to use uppercase hex digits (1) or lowercase (0)
 *
 * Return: The number of characters printed
 */

int _print_hex(unsigned int num, int uppercase)
{
	int count = 0;
	char buffer[BUFF];
	int len = 0;
	char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num != 0)
	{
		buffer[len] = digits[num % 16];
		num /= 16;
		len++;
	}

	while (len > 0)
	{
		len--;
		_putchar(buffer[len]);
		count++;
	}

	return (count);
}



/**
 * _print_address - Print a memory address in hexadecimal format to stdout
 * @ptr: The pointer to print the address of
 *
 * Return: The number of characters printed
 */
int _print_address(void *ptr)
{
	int len = 0;
	int count = 0;
	uintptr_t address = (uintptr_t)ptr;
	char buffer[BUFF];

	if (ptr == NULL)
		return (_print_str("(nil)"));

	count += _putchar('0');
	count += _putchar('x');

	/* Convert the address to hexadecimal and store it in the buffer */
	while (address != 0)
	{
		buffer[len] = "0123456789abcdef"[address % 16];
		address /= 16;
		len++;
	}

	/* Print the address in reverse order (hexadecimal representation) */
	while (len > 0)
	{
		len--;
		_putchar(buffer[len]);
		count++;
	}

	return (count);
}

