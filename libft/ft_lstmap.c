#include "libft.h"

int check(t_list *node, t_list *head, void (*del)(void *))
{
    if (!node)
    {
        ft_lstclear(&head, del);
        return 1;
    }
    if (!node->content)
    {
        free(node);
        ft_lstclear(&head, del);
        return 1;
    }
    return 0;
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *head;
    t_list *current;

    if (!lst || !f || !del)
        return NULL;
    head = NULL;
    while (lst != NULL)
    {
        t_list *node = ft_lstnew(f(lst->content));
        if (check(node, head, del) == 1)
            return NULL;
        if (!head)
            head = node;
        else
            current->next = node;
        current = node;
        lst = lst->next;
    }
    return (head);
}
void del(void *content)
{
    free(content);
}

void *f(void *content)
{
    int *new_content = malloc(sizeof(int));
    if (!new_content)
        return NULL;
    *new_content = *(int *)content + 1;
    return new_content;
}
int main()
{
    t_list *nd = NULL;
    t_list *p = malloc(sizeof(t_list));
    if (!p)
        return 0;
    int a = 2;
    int b = 3;
    int c = 4;
    p->content = &a;
    p->next = NULL;
    nd = p;

    p = malloc(sizeof(t_list));
    if (!p)
        return 0;
    p->content = &b;
    p->next = NULL;
    nd->next = p;

    p = malloc(sizeof(t_list));
    if (!p)
        return 0;
    p->content = &c;
    p->next = NULL;
    nd->next->next = p;

    t_list *m = ft_lstmap(nd, f, del);
}