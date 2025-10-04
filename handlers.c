#include "main.h"

/*
 * File: handlers.c
 * Desc: Handlers for %c, %s, %d, %i.
 */

/**
 * print_char - prints a single character
 * @c: character (promoted int)
 *
 * Return: 1 on success, -1 on error
 */
int print_char(int c)
{
	if (_putchar((char)c) == -1)
	{
		return (-1);
	}
	return (1);
}

/**
 * print_str - prints a C string (prints "(null)" if s is NULL)
 * @s: string pointer
 *
 * Return: number of chars printed, or -1 on error
 */
int print_str(const char *s)
{
	int i = 0;
	const char *nil = "(null)";

	if (s == 0)
	{
		s = nil;
	}

	while (s[i] != '\0')
	{
		if (_putchar(s[i]) == -1)
		{
			return (-1);
		}
		i++;
	}
	return (i);
}

/**
 * print_unsigned_dec - prints an unsigned long in base 10
 * @u: number to print
 *
 * Return: number of chars printed, or -1 on error
 */
static int print_unsigned_dec(unsigned long u)
{
	char buf[21];
	int i = 0, j, count = 0;

	if (u == 0)
	{
		if (_putchar('0') == -1)
		{
			return (-1);
		}
		return (1);
	}

	while (u > 0)
	{
		buf[i++] = (char)('0' + (u % 10));
		u /= 10;
	}

	for (j = i - 1; j >= 0; j--)
	{
		if (_putchar(buf[j]) == -1)
		{
			return (-1);
		}
		count++;
	}
	return (count);
}

/**
 * print_int - prints a signed decimal integer
 * @n: integer value
 *
 * Return: number of chars printed, or -1 on error
 */
int print_int(int n)
{
	long ln = n;
	unsigned long u;
	int count = 0, rc;

	if (ln < 0)
	{
		if (_putchar('-') == -1)
		{
			return (-1);
		}
		count++;
		u = (unsigned long)(-ln);
	}
	else
	{
		u = (unsigned long)ln;
	}

	rc = print_unsigned_dec(u);
	if (rc == -1)
	{
		return (-1);
	}
	return (count + rc);
}
/**
 * print_bin - prints an unsigned int in binary
 * @n: value to print
 *
 * Return: number of chars printed, or -1 on error
 */
int print_bin(unsigned int n)
{
	char buf[sizeof(unsigned int) * 8];
	int i = 0;
	int j;
	int count = 0;

	if (n == 0)
	{
		if (_putchar('0') == -1)
		{
			return (-1);
		}
		return (1);
	}

	while (n > 0)
	{
		buf[i] = (char)('0' + (n & 1));
		i++;
		n >>= 1;
	}

	for (j = i - 1; j >= 0; j--)
	{
		if (_putchar(buf[j]) == -1)
		{
			return (-1);
		}
		count++;
	}
	return (count);
}
