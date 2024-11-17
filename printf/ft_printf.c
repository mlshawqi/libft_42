#include "libftprintf.h"



int ft_printf(const char *format, ...)
{
    va_list arg;

    va_start(arg, format);

    int count = 0;
    while (*format)
    {
        if(*format == '%')
            count += ft_format(&format, arg);
        else
        {
            count += ft_putchar(*format);
            format++;       
        }

    }
    return count;
}
int main()
{
    int i = ft_printf("hel%d, %d %s %c %d %z", 300, 4000000, "helllllllllll", 't', -2147483648 );
    printf("\n %d \n", i);
    int t = printf("hel%d, %d %s %c %d %z", 300, 4000000, "helllllllllll", 't', -2147483648 );
    printf("\n %d \n", t);
}