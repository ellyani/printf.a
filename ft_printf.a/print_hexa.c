#include "ft_printf.h"

int	print_hexa(unsigned int nbr, char specifier)
{
	int count;
	char *symboles;
	char *symbolesU;

	count = 0;
	symboles = "0123456789abcdef";
	symbolesU = "0123456789ABCDEF";
	if (nbr > 16)
	{
		count += print_hexa(nbr / 16, specifier);
		count += print_hexa(nbr % 16, specifier);
	}	
	else
	{
		if (specifier == 'X')
			count += print_char(symbolesU[nbr % 16]);
		else 
			count += print_char(symboles[nbr % 16]);
	}
	return (count);
}