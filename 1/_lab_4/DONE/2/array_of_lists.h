#ifndef _ARRAY_OF_LISTS_H
#define _ARRAY_OF_LISTS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void	clear_all(t_list **array, void (*del)(void *));
void	print_all(t_list **array);
int		add_to_empty_list(t_list **array, void *data);
int 	add_to_list(t_list **array, void *data_ref, void *data, int (*cmp)(void *, void *));
int 	add_to_list_before(t_list **array, void *data_ref, void *data, int (*cmp)(void *, void *));
int 	delete_element_from_list(t_list **array, void *data_ref, void (*del)(void *), int (*cmp)());
int 	delete_element_from_array(t_list **array, int i, void (*del)(void *));
t_list	*search_elem(t_list **array, void *data_ref, int (*cmp)(void *, void *));


#endif
