#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/*
 * File: main.h
 * Desc: Prototypes for holbertonschool-printf (Task 0).
 *       Supports %c, %s, and %%.
 */

/* Core */
int _printf(const char *format, ...);
int _putchar(char c);

/* Handlers for Task 0 */
int print_char(int c);         /* handles %c */
int print_str(const char *s);  /* handles %s */

#endif
