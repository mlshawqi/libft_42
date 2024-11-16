#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tp;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	tp = ft_lstlast(*lst);
	tp->next = new;
}