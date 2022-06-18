#include "doubly_list.h"

void	ft_init(t_list **list)
{
	*list = malloc(sizeof(t_list));
	if (list == NULL)
		return ;
	(*list)->data = NULL;
	(*list)->prev = *list;
	(*list)->next = *list;
}

t_list	*ft_search(t_list **list, void *to_find, int (*cmp)(void *, void *))
{
	t_list	*tmp;

	tmp = (*list)->next;
	while (tmp != *list)
	{
		if (cmp(to_find, tmp->data))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_list	*ft_search_rev(t_list **list, void *to_find, int (*cmp)(void *, void *))
{
	t_list	*tmp;

	tmp = (*list)->prev;
	while (tmp != *list)
	{
		if (cmp(to_find, tmp->data))
			return (tmp);
		tmp = tmp->prev;
	}
	return (NULL);
}

void	ft_lstadd_front(t_list **list, void *data)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return ;

	new->data = data;
	new->next = *list;
	new->prev = *list;
	(*list)->next = new;
	(*list)->prev = new;
}

int	ft_lstadd(t_list **list, void *data, void *to_find, int (*cmp)(void *, void *))
{
	t_list	*tmp;
	t_list	*new;

	tmp = ft_search(list, to_find, cmp);
	if (tmp == NULL)
		return (0);
	new = malloc(sizeof(t_list));

	new->data = data;
	new->next = tmp->next;
	new->prev = tmp;
	tmp->next->prev = new;
	tmp->next = new;
	return (1);
}

int	ft_lstadd_before(t_list **list, void *data, void *to_find, int (*cmp)(void *, void *))
{
	t_list	*tmp;
	t_list	*new;

	tmp = ft_search(list, to_find, cmp);
	if (tmp == NULL)
		return (0);
	new = malloc(sizeof(t_list));

	new->data = data;
	new->next = tmp;
	new->prev = tmp->prev;
	tmp->prev->next = new;
	tmp->prev = new;
	return (1);
}

int	ft_lstdel(t_list **list, void *to_find, void (*del)(void *), int (*cmp)(void *, void *))
{
	t_list	*tmp;

	tmp = ft_search(list, to_find, cmp);
	if (tmp == NULL)
		return (0);

	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	del(tmp->data);
	free(tmp);
	return (1);
}

void	ft_print(t_list **list, void (*p)(void *))
{
	t_list	*tmp;

	tmp = (*list)->next;
	while (tmp != *list)
	{
		p(tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void	ft_print_rev(t_list **list, void (*p)(void *))
{
	t_list	*tmp;

	tmp = (*list)->prev;
	while (tmp != *list)
	{
		p(tmp->data);
		tmp = tmp->prev;
	}
	printf("\n");
}

void	ft_lstiter(t_list **lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = (*lst)->next;
	while (tmp != *lst)
	{
		f(tmp->data);
		tmp = tmp->next;
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	next = (*lst)->next;
	while (next != *lst)
	{
		tmp = next;
		del(tmp->data);
		next = next->next;
		free(tmp);
	}
	free(*lst);
	*lst = NULL;
}

void	ft_delchar(void *data)
{
	free(data);
}

int	cmp(void *a, void *b)
{
	if (*(char *)a == *(char *)b)
		return (1);
	return (0);
}

void	p(void *a)
{
	printf("%c ", *(char *)a);
}
