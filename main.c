#include "ft_printf.h"

int print_char(int c){
    return (write(1, &c ,1));
}

int print_digit(int nbr)
{
    int count;

    count = 0;
    if (nbr < 0)
    {
        count += write(1,"-",1);
        nbr *= -1;
    }
    if (nbr < 10)
        count += print_char(nbr + '0');
    else 
    {
        count += print_digit(nbr / 10);
        count += print_digit(nbr % 10);
    }
    return (count);
}

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


int print_str(char *str){
    int count;
    count = 0;
    while (*str){
        print_char((int )*str);
        ++count;
        ++str;
    }
    return (count);
}

static int print_ptr_hex(unsigned long nbr)
{
    int count;
    char *symboles = "0123456789abcdef";

    count = 0;
    if (nbr >= 16)
    {
        count += print_ptr_hex(nbr / 16);
        count += print_ptr_hex(nbr % 16);
    }
    else 
       count += print_char(symboles[nbr % 16]);
    return (count);

}
int print_ptr(unsigned long nbr)
{
	int count;

    count = 0;
	count += write(1,"0x",2);
	if (nbr == 0)
		count += write(1,"0",1);
	else
	{
		count += print_ptr_hex(nbr);
	}
	return (count);
}
int	print_hexa(unsigned int nbr, char specifier)
{
	int count;
	char *symboles;
	char *symbolesU;

	count = 0;
	symboles = "0123456789abcdef";
	symbolesU = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		count += print_hexa(nbr / 16, specifier);
		count += print_hexa(nbr % 16, specifier);
	}	
	else
	{
		if (specifier == 'X')
			count += print_char(symbolesU[nbr]);
		else 
			count += print_char(symboles[nbr]);
	}
	return (count);
}

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
        count += print_hexa( (long)va_arg(ap , unsigned int), specifier);
    else if (specifier == 'p')
        count += print_ptr(va_arg(ap, unsigned long));
    else 
        write(1, &specifier, 1);
    return  (count);    
}
int ft_printf(const char *format , ...){
    va_list ap;
    int     count;

    va_start (ap ,format);
    count = 0 ;
    while (*format)
    {
        if (*format  == '%')
        
            count +=print_format(*(++format) , ap);
        else 
            count += write(1,&format ,1);
    ++format;
    }
    va_end(ap);
    return (count);

}
int main() {
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Character: %c\n", 'A');
    ft_printf("Decimal: %d\n", -42);
    ft_printf("Unsigned: %u\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);
    return 0;
}



