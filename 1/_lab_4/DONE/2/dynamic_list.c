#include "dynamic_list.h"

t_list	*ft_lstnew(void *data)
{
	t_list	*t;

	t = malloc(sizeof(*t));
	if (t == NULL)
		return (NULL);
	t->data = data;
	t->next = NULL;
	return (t);
}

int	ft_lstadd_before(t_list **begin_list, void *data_ref, void *data, int (*cmp)(void *, void *))
{
	t_list	*tmp;
	t_list	*head;

	if (*begin_list == NULL)
		return (0);
	// {
	// 	*begin_list = ft_lstnew(data);
	// 	return (1);
	// }
	if (cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = ft_lstnew(data);
		tmp->next = *begin_list;
		*begin_list = tmp;
		return (1);
	}
	head = *begin_list;
	while (head)
	{
		if (head->next == NULL)
			return (0);
		if (cmp(head->next->data, data_ref) == 0)
		{
			tmp = ft_lstnew(data);
			tmp->next = head->next;
			head->next = tmp;
			return (1);
		}
		head = head->next;
	}
	return (0);
}

int	ft_lstadd_after(t_list **begin_list, void *data_ref, void *data, int (*cmp)())
{
	t_list	*tmp;
	t_list	*head;

	if (*begin_list == NULL)
		return (0);
	// {
	// 	*begin_list = ft_lstnew(data);
	// 	return (1);
	// }
	head = *begin_list;
	while (head)
	{
		if (cmp(head->data, data_ref) == 0)
		{
			tmp = ft_lstnew(data);
			tmp->next = head->next;
			head->next = tmp;
			return (1);
		}
		head = head->next;
	}
	return (0);
}

int ft_lstdelone(t_list **begin_list, void *data_ref, void (*del)(void *), int (*cmp)())
{
	t_list	*tmp;
	t_list	*head;

	if (del == NULL || cmp == NULL || data_ref == NULL || *begin_list == NULL)
		return (0);
	if (cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		del(tmp->data);
		free(tmp);
		return (1);
	}
	head = *begin_list;
	while (head)
	{
		if (head->next == NULL)
			return (0);
		if ((*cmp)(head->next->data, data_ref) == 0)
		{
			tmp = head->next;
			head->next = head->next->next;
			del(tmp->data);
			free(tmp);
			return (1);
		}
		head = head->next;
	}
	return (0);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		f(lst->data);
		lst = lst->next;
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*l;

	if (del == NULL)
		return ;
	l = *lst;
	while (l)
	{
		if (l->next)
			tmp = l->next;
		else
			tmp = NULL;
		del(l->data);
		free(l);
		l = tmp;
	}
	*lst = NULL;
}

int	ft_move(t_list **begin_list, t_list **stack, void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*tmp;
	t_list	*head;

	if (cmp == NULL || data_ref == NULL || *begin_list == NULL)
		return (0);
	if (cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
	 	tmp->next = *stack;
		*stack = tmp;
		return (1);
	}
	head = *begin_list;
	while (head)
	{
		if (head->next == NULL)
			return (0);
		if ((*cmp)(head->next->data, data_ref) == 0)
		{
			tmp = head->next;
			head->next = head->next->next;
			tmp->next = *stack;
			*stack = tmp;
			return (1);
		}
		head = head->next;
	}
	return (0);
}

t_list *ft_search(t_list **head, void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (cmp(tmp->data, data_ref) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

/*
 * Функции-обработчики войдовских значений.
*/

int		ft_compare(void *a, void *b)
{
	if (a == NULL || b == NULL)
		return (1);
	if (*((char *)a) == *((char *)b))
		return (0);
	return (1);
}

void	ft_print_char(void *data)
{
	printf("%c ", *((char *)data));
}

void	ft_delchar(void *data)
{
	free(data);
}
