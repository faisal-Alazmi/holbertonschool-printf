#include "main.h"

/**
 * print_percent - prints a percent sign
 *
 * Return: 1 on success, -1 on error
 */
static int print_percent(void)
{
	if (_putchar('%') == -1)
	{
		return (-1);
	}
	return (1);
}

/**
 * handle_conv - handles one conversion (Task 0+1)
 * @spec: conversion specifier
 * @ap:   active variadic list
 *
 * Return: printed length, or -1 on error
 */
static int handle_conv(char spec, va_list ap)
{
	if (spec == 'c')
	{
		return (print_char(va_arg(ap, int)));
	}
	if (spec == 's')
	{
		return (print_str(va_arg(ap, char *)));
	}
	if (spec == 'd' || spec == 'i')
	{
		return (print_int(va_arg(ap, int)));
	}
	if (spec == '%')
	{
		return (print_percent());
	}
	if (spec == 'b')
	{
		return (print_bin(va_arg(ap, unsigned int)));
	}

	/* Unknown: print literally as %<char> */
	if (_putchar('%') == -1)
	{
		return (-1);
	}
	if (_putchar(spec) == -1)
	{
		return (-1);
	}
	return (2);
}

/**
 * handle_percent - consumes '%' and prints its specifier
 * @pf: pointer to format cursor (points at '%')
 * @ap: variadic list
 *
 * Return: printed length, or -1 on error
 */
static int handle_percent(const char **pf, va_list ap)
{
	(*pf)++;
	if (**pf == '\0')
	{
		return (-1);
	}
	return (handle_conv(**pf, ap));
}

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: printed length, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0, rc;

	if (format == 0)
	{
		return (-1);
	}
	va_start(ap, format);

	for (; *format; format++)
	{
		if (*format != '%')
		{
			if (_putchar(*format) == -1)
			{
				va_end(ap);
				return (-1);
			}
			count++;
		}
		else
		{
			rc = handle_percent(&format, ap);
			if (rc == -1)
			{
				va_end(ap);
				return (-1);
			}
			count += rc;
		}
	}
	va_end(ap);
	return (count);
}
