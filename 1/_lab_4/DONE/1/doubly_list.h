#ifndef _DOUBLY_LIST_H
#define _DOUBLY_LIST_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	void 	*data;
	struct 	s_list *prev;
	struct 	s_list *next;
}				t_list;

t_list	*ft_search(t_list **list, void *to_find, int (*cmp)(void *, void *));
t_list	*ft_search_rev(t_list **list, void *to_find, int (*cmp)(void *, void *));
int		ft_lstadd(t_list **list, void *data, void *to_find, int (*cmp)(void *, void *));
int		ft_lstadd_before(t_list **list, void *data, void *to_find, int (*cmp)(void *, void *));
int		ft_lstdel(t_list **list, void *to_find, void (*del)(void *), int (*cmp)(void *, void *));
int		cmp(void *a, void *b);
void	ft_print(t_list **list, void (*p)(void *));
void	ft_print_rev(t_list **list, void (*p)(void *));
void	ft_lstiter(t_list **lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	p(void *a);
void	ft_delchar(void *data);
void	ft_lstadd_front(t_list **list, void *data);

#endif
