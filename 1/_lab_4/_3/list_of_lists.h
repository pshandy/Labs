#ifndef _LIST_OF_LISTS_H
#define _LIST_OF_LISTS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list_main
{
	void 	*data;
	struct	s_list	*sublist;
	struct 	s_list_main	*prev;
	struct 	s_list_main	*next;
} t_list_main;

int		is_main_list_empty(t_list_main *list);
int		is_sublist_empty(t_list_main *list);
void	ft_init_main(t_list_main **list);
t_list_main	*ft_search_main(t_list_main **list, void *to_find, int (*cmp)(void *, void *));
void	ft_lstadd_front_main(t_list_main **list, void *data);
int		ft_lstadd_main(t_list_main **list, void *data, void *to_find, int (*cmp)(void *, void *));
int	ft_lstadd_before_main(t_list_main **list, void *data, void *to_find, int (*cmp)(void *, void *));
int	ft_lstdel_main(t_list_main **list, void *to_find, void (*del)(void *), int (*cmp)(void *, void *));
void	ft_print_main(t_list_main **list, void (*p)(void *));
void	ft_print_rev_main(t_list_main **list, void (*p)(void *));
void	ft_lstclear_main(t_list_main **lst, void (*del)(void *));
int add_to_empty_list(t_list_main **list, void *data);
int 	add_to_list(t_list_main **list, void *data_ref, void *data, int (*cmp)(void *, void *));
int 	add_to_list_before(t_list_main **list, void *data_ref, void *data, int (*cmp)(void *, void *));
int 	delete_element_from_list(t_list_main **list, void *data_ref, void (*del)(void *), int (*cmp)(void *, void *));
#endif
