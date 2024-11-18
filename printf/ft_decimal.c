#include "libftprintf.h"

void	ft_decimal(unsigned int n, int *cn)
{
	if(n > 9)
	{
		ft_decimal((n / 10), cn);
		ft_decimal((n % 10), cn);
	}
	else
		*cn += ft_putchar(n + '0');
}