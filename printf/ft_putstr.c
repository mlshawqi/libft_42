#include "ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i], len);
		i++;
	}
	len += i;
}