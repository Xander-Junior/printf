#include "main.h"

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
