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
    int a = '42';
    int *g = &a;
    int i = ft_printf("%p", g);
    printf("\n %d \n", i);
    int t = printf("%p", g);
    printf("\n %d \n", t);
}