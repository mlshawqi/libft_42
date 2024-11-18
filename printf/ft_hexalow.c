#include "libftprintf.h"

void    ft_hexalow(unsigned long nbr, int *count)
{
        char base[] = "0123456789abcdef";

        if(nbr >= 16)
        {
            ft_hexalow((nbr / 16), count);
            ft_hexalow((nbr % 16), count);
        }
        else
            *count += ft_putchar(base[nbr]);
}