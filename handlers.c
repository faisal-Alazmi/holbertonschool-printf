#include "main.h"
/**
 * print_char - prints a single character
 * @c: character (promoted int)
 * Return: 1 on success, -1 on error
 */
int print_char(int c)
{
if (_putchar((char)c) == -1)
return (-1);
return (1);
}
/**
 * print_str - prints a C string (prints "(null)" if s is NULL)
 * @s: string pointer
 * Return: number of characters printed, or -1 on error
 */
int print_str(const char *s)
{
int i = 0;
const char *nil = "(null)";
if (s == 0)
s = nil;
while (s[i] != '\0')
{
if (_putchar(s[i]) == -1)
return (-1);
i++;
}
return (i);
}
