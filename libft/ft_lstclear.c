#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;

	if (lst == NULL || del == NULL || *lst == NULL)
		return ;
	p = *lst;
	while (*lst != NULL)
	{
		del(p->content);
		p = p->next;
		free(*lst);
		*lst = p;
	}
	*lst = NULL;
}