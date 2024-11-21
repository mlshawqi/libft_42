#include "ft_printf.h"

int	ft_printf(const char *argument, ...)
{
	va_list	arg;
	int		count;

	va_start(arg, argument);
	count = 0;
	while (*argument)
	{
		if (*argument == '%')
		{
			ft_format(&argument, arg, &count);
			if (count == -1)
				return (-1);
		}
		else
			ft_putchar(*argument, &count);
		argument++;
	}
	return (count);
}
// #include <limits.h>
// int main()
// {

//     printf("\nlen %d\n", ft_printf(NULL));
// 	printf(" \nlen %d\n", printf(NULL));
// }