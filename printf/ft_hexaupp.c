#include "libftprintf.h"

void    ft_hexaupp(unsigned int nbr, int *count)
{
        char base[] = "0123456789ABCDEF";
        unsigned int len = 16;

        if(nbr >= len)
        {
            ft_hexaupp((nbr / len), count);
            ft_hexaupp((nbr % len), count);
        }
        else
            *count += ft_putchar(base[nbr]);
}