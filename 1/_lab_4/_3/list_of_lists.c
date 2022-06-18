#include "list_of_lists.h"
#include "doubly_list.c"

int		is_main_list_empty(t_list_main *list)
{
	if (list->next == list && list->prev == list)
		return (1);
	return (0);
}

int		is_sublist_empty(t_list_main *list)
{
	if (list->sublist->next == list->sublist && list->sublist->prev == list->sublist)
		return (1);
	return (0);
}

void	ft_init_main(t_list_main **list)
{
	*list = malloc(sizeof(t_list_main));
	(*list)->sublist = NULL;
	(*list)->data = NULL;
	(*list)->prev = *list;
	(*list)->next = *list;
}

t_list_main	*ft_search_main(t_list_main **list, void *to_find,
								int (*cmp)(void *, void *))
{
	t_list_main	*tmp;

	tmp = (*list)->next;
	while (tmp != *list)
	{
		if (cmp(to_find, tmp->data))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_lstadd_front_main(t_list_main **list, void *data)
{
	t_list_main *new;

	new = malloc(sizeof(t_list_main));
	new->data = data;
	new->next = *list;
	new->prev = *list;
	ft_init(&(new->sublist));
	(*list)->next = new;
	(*list)->prev = new;
}

int		ft_lstadd_main(t_list_main **list, void *data,
						void *to_find, int (*cmp)(void *, void *))
{
	t_list_main	*tmp;
	t_list_main	*new;

	if ((*list)->next == *list && (*list)->prev == *list)
	{
		ft_lstadd_front_main(list, data);
		return (1);
	}

	tmp = ft_search_main(list, to_find, cmp);
	if (tmp == NULL)
		return (0);
	new = malloc(sizeof(t_list_main));

	new->data = data;
	new->next = tmp->next;
	new->prev = tmp;
	ft_init(&(new->sublist));
	tmp->next->prev = new;
	tmp->next = new;
	return (1);
}

int	ft_lstadd_before_main(t_list_main **list, void *data,
							void *to_find, int (*cmp)(void *, void *))
{
	t_list_main	*tmp;
	t_list_main	*new;

	if ((*list)->next == *list && (*list)->prev == *list)
	{
		ft_lstadd_front_main(list, data);
		return (1);
	}

	tmp = ft_search_main(list, to_find, cmp);
	if (tmp == NULL)
		return (0);
	new = malloc(sizeof(t_list_main));

	new->data = data;
	new->next = tmp;
	new->prev = tmp->prev;
	ft_init(&(new->sublist));
	tmp->prev->next = new;
	tmp->prev = new;
	return (1);
}

int	ft_lstdel_main(t_list_main **list, void *to_find,
					void (*del)(void *), int (*cmp)(void *, void *))
{
	t_list_main	*tmp;

	tmp = ft_search_main(list, to_find, cmp);
	if (tmp == NULL)
		return (0);

	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	del(tmp->data);
	ft_lstclear(&tmp->sublist, del);
	free(tmp);
	return (1);
}

void	ft_print_main(t_list_main **list, void (*p)(void *))
{
	t_list_main	*tmp;

	tmp = (*list)->next;
	while (tmp != *list)
	{
		printf("Список ");
		p(tmp->data);
		printf(": ");
		ft_print(&(tmp->sublist), p);
		tmp = tmp->next;
	}
	printf("\n");
}

void	ft_print_rev_main(t_list_main **list, void (*p)(void *))
{
	t_list_main	*tmp;

	tmp = (*list)->prev;
	while (tmp != *list)
	{
		printf("Список ");
		p(tmp->data);
		printf(": ");
		ft_print(&(tmp->sublist), p);
		tmp = tmp->prev;
	}
	printf("\n");
}

void	ft_lstclear_main(t_list_main **lst, void (*del)(void *))
{
	t_list_main	*tmp;
	t_list_main	*next;

	next = (*lst)->next;
	while (next != *lst)
	{
		tmp = next;
		del(tmp->data);
		ft_lstclear(&tmp->sublist, del);
		next = next->next;
		free(tmp);
	}
	free(*lst);
	*lst = NULL;
}

//-------------------------------------------------------------------------

int add_to_empty_list(t_list_main **list, void *data)
{
	t_list_main	*tmp;

	if (is_main_list_empty(*list))
		return (0);
	tmp = (*list)->next;
	while (tmp != *list)
	{
		if (is_sublist_empty(tmp))
		{
			ft_lstadd_front(&(tmp->sublist), data);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int 	add_to_list(t_list_main **list, void *data_ref, void *data, int (*cmp)(void *, void *))
{
	t_list_main	*tmp;

	if (is_main_list_empty(*list))
		return (0);
	tmp = (*list)->next;
	while (tmp != *list)
	{
		if (ft_lstadd(&(tmp->sublist), data, data_ref, cmp))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int 	add_to_list_before(t_list_main **list, void *data_ref, void *data, int (*cmp)(void *, void *))
{
	t_list_main	*tmp;

	if (is_main_list_empty(*list))
		return (0);
	tmp = (*list)->next;
	while (tmp != *list)
	{
		if (ft_lstadd_before(&(tmp->sublist), data, data_ref, cmp))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int 	delete_element_from_list(t_list_main **list, void *data_ref, void (*del)(void *), int (*cmp)(void *, void *))
{
	t_list_main	*tmp;

	if (is_main_list_empty(*list))
		return (0);
	tmp = (*list)->next;
	while (tmp != *list)
	{
		if (ft_lstdel(&(tmp->sublist), data_ref, del, cmp))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
