#include "sort.h"

void	ft_init(t_list **list)
{
	*list = malloc(sizeof(t_list));
	if (list == NULL)
		return ;

	(*list)->data = -1;
	(*list)->prev = *list;
	(*list)->next = *list;
}

void	ft_lstadd_back(t_list **list, char *data)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return ;

	new->data = data;
	new->prev = (*list)->prev;
	new->next = *list;
	(*list)->prev->next = new;
	(*list)->prev = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*next;

	if (*lst == NULL)
		return ;

	next = (*lst)->next;
	while (next != *lst)
	{
		tmp = next;
		tmp->data = -1;
		next = next->next;
		free(tmp);
	}
	free(*lst);
	*lst = NULL;
}
