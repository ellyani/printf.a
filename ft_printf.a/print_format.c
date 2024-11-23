#include "ft_printf.h"

int print_format(char specifier , va_list ap){

    int count ;
    count = 0;
    if(specifier == 'c')
        count += print_char(va_arg(ap, int));
    else if (specifier == 's')
        count += print_str(va_arg(ap, char *));
    else if (specifier == 'd' || specifier =='i')
        count += print_digit( (long) va_arg(ap , int));
    else if (specifier == 'u')
        count += print_unsigned(va_arg(ap, unsigned int));
    else if (specifier == 'x' || specifier == 'X')
        count += print_hexa( (long)va_arg(ap , unsigned int), 16);
    else if (specifier == 'p')
        count += print_ptr(va_arg(ap, unsigned long));
    else 
        write(1, &specifier, 1);
    return  (count);    
}