#include "main.h"
/**
 * _putchar - writes a character to stdout
 * @c: the character
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
ssize_t w = write(1, &c, 1);
return (w == 1 ? 1 : -1);
}
