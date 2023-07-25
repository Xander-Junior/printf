#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom implementation of printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
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
			putchar(*format);
			count++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					count++;
					break;

				case 's':
					count += fputs(va_arg(args, char *), stdout);
					break;

				case '%':
					putchar('%');
					count++;
					break;

				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		format++;
	}

	va_end(args);

	return count;
}
