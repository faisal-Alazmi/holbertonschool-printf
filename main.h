#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/*
 * File: main.h
 * Desc: Prototypes for holbertonschool-printf (Task 0+1).
 *       Supports %c, %s, %%, %d, %i.
 */

/* Core */
int _printf(const char *format, ...);
int _putchar(char c);

/* Handlers */
int print_char(int c);
int print_str(const char *s);
int print_int(int n);
int print_bin(unsigned int n);

#endif /* MAIN_H */
