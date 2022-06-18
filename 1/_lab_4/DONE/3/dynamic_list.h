#ifndef _DYNAMIC_LIST_H
#define _DYNAMIC_LIST_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
} t_list;

t_list	*ft_lstnew(void *data);
t_list	*ft_search(t_list **head, void *data_ref, int (*cmp)(void *, void *));
int		ft_lstadd_before(t_list **begin_list, void *data_ref, void *data, int (*cmp)(void *, void *));
int		ft_lstadd_after(t_list **begin_list, void *data_ref, void *data, int (*cmp)());
int 	ft_lstdelone(t_list **begin_list, void *data_ref, void (*del)(void *), int (*cmp)());
int		ft_move(t_list **begin_list, t_list **stack, void *data_ref, int (*cmp)(void *, void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, void *data);

int		ft_compare(void *a, void *b);
void	ft_print_char(void *data);
void	ft_delchar(void *data);

#endif
