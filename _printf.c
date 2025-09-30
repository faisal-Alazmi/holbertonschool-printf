#include "main.h"
/**
 * print_percent - prints a literal percent sign
 *
 * Return: 1 on success, -1 on error
 */
static int print_percent(void)
{
if (_putchar('%') == -1)
return (-1);
return (1);
}
/**
 * handle_conv - handles a single conversion specifier for Task 0
 * @spec: conversion specifier character
 * @ap: active variadic argument list
 *
 * Return: number of characters printed, or -1 on error
 */
static int handle_conv(char spec, va_list ap)
{
if (spec == 'c')
return (print_char(va_arg(ap, int)));
if (spec == 's')
return (print_str(va_arg(ap, char *)));
if (spec == '%')
return (print_percent());
/* Unknown specifier: print literally as %<char> */
if (_putchar('%') == -1)
return (-1);
if (_putchar(spec) == -1)
return (-1);
return (2);
}
/**
 * _printf - produces output according to a format
 * @format: format string with zero or more directives
 *
 * Return: number of characters printed, or -1 on error
 *
 * Description: Task 0 supports %c, %s, and %% only.
 */
int _printf(const char *format, ...)
{
va_list ap;
int count = 0, rc;
if (format == 0)
return (-1);
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
continue;
}
format++;
if (!*format)
{
va_end(ap);
return (-1);
}
rc = handle_conv(*format, ap);
if (rc == -1)
{
va_end(ap);
return (-1);
}
count += rc;
}
va_end(ap);
return (count);
}
