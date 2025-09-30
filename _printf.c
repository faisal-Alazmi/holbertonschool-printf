#include "main.h"
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
const char *p;
int count = 0, rc;
if (format == 0)
return (-1);
va_start(ap, format);
for (p = format; *p != '\0'; p++)
{
if (*p != '%')
{
if (_putchar(*p) == -1)
{
va_end(ap);
return (-1);
}
count++;
continue;
}
p++;
if (*p == '\0')
{
va_end(ap);
return (-1);
}
if (*p == 'c')
{
rc = print_char(va_arg(ap, int));
if (rc == -1)
{
va_end(ap);
return (-1);
}
count += rc;
}
else if (*p == 's')
{
rc = print_str(va_arg(ap, char *));
if (rc == -1)
{
va_end(ap);
return (-1);
}
count += rc;
}
else if (*p == '%')
{
if (_putchar('%') == -1)
{
va_end(ap);
return (-1);
}
count++;
}
else
{
if (_putchar('%') == -1 || _putchar(*p) == -1)
{
va_end(ap);
return (-1);
}
count += 2;
}
}
va_end(ap);
return (count);
}
