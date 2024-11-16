#include "libftprintf.h"

int ft_printf(char *format, ...)
{
    va_list arg;

    va_start(arg, format);

    int i = 0;
    int luck = 0;
    while (format[i] != '\0')
    {
        if(format[i] == '%')
        {
            ft_format(format, va_start);
            luck++;
            break;
        }
            
        i++;
    }
    if (luck == 0)
            return (ft_putstr(format), i);
    return 0;
}
int main()
{
    ft_printf("hello hi");
}