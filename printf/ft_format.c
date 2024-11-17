#include "libftprintf.h"

int ft_format(const char **fr, va_list args) {
    int count = 0;

    (*fr)++;
    if (**fr == 'd')
        ft_putnbr(va_arg(args, int), &count);
    else if (**fr == 's')
        count += ft_putstr(va_arg(args, char *));
    else if (**fr == 'c')
        count += ft_putchar((char)va_arg(args, int));
    else if(**fr == 'u')
        count += ft_decimal(va_arg(args, unsigned int), &count);
    else if (**fr == '%')
        count += ft_putchar('%');
    else
        count += ft_putchar('%') + ft_putchar(**fr);
    (*fr)++;
    return count;
}

/*int ft_format(const char **fr, va_list args)
{
    int count = 0;
    while (*fr)
    {
        if (*fr == '%')
        {
            fr++;

            if (*fr == 'd')
                count += ft_putnbr(va_arg(args, int));
            else if (*fr == 's')
                count += ft_putstr(va_arg(args, char *));
            else if (*fr == 'c')
                count += ft_putchar((char)va_arg(args, int));
            else if (*fr == '%')
                count += ft_putchar('%');
            else
            {
                count += ft_putchar('%');
                count += ft_putchar(*fr);
            }
        }
        else
            count += putchar(*fr);
        fr++;
    }
    return count;
}*/