#include "ft_printf.h"

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
int main(){
    int count ;
    count = ft_printf("hello %s\n", "jhon");
    ft_printf("The char written are %%d\n", count);
    printf("\n%u\n",144);
    ft_printf("\n%u",144);
    count = ft_printf("%d\n",42);
    ft_printf("the chars written are %d\n" , count);

     count = ft_printf("%x\n",10);
    ft_printf("the chars written are %x\n" , count);

    count = ft_printf("Char-> %c\n", 'a');
	ft_printf("\n%dchars\n", count);

    count =ft_printf("Nbr-> %d\n", -42);
	ft_printf("\n%d chars\n", count);

    count = ft_printf("Hex-> %x\n", -1);
	ft_printf("\n%d chars\n", count);

    ft_printf("\n\n");
	puts("REAL PRINTF");
}



