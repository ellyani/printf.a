#ifndef FT_PRINTF
# define FT_PRINTF 
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *format , ...);
int print_char(int c);
int print_digit(int nbr);
int print_format(char specifier , va_list ap);
int	print_hexa(unsigned int nbr, char specifier);
int print_ptr(unsigned long nbr);
int print_str(char *str);
int print_unsigned(unsigned int nbr);

#endif