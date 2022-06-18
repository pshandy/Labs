#ifndef _STATIC_LIST_H
#define _STATIC_LIST_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

#define SIZE 64

typedef struct	s_list {
	char	array[SIZE];
	int		size;
}				t_list;

int		add(t_list *list, char c, int index, char flag);
int		add_cmp(t_list *list, char c);
int		search(t_list *list, char to_find);
int		del(t_list *list, int index);
void 	print(t_list *list);
void 	init(t_list *list);

#endif
