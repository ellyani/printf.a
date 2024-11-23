#include "ft_printf.h"

int print_unsigned(unsigned int nbr) 
{
    int count = 0;
    if (nbr < 10)
        count += print_char(nbr + '0');
    else {
        count += print_unsigned(nbr / 10);
        count += print_unsigned(nbr % 10);
    }
    return count;
}