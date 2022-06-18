#ifndef _STATIC_LIST_P_H
#define _STATIC_LIST_P_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

#define SIZE 6

typedef struct	s_record {
	char	data;
	int		next;
}				t_record;

int del(int idx);
int get_pos(int idx);
int	search();
int	find_char(char to_find);
int add(char c, int idx, char flag);
void print();
void init();

#endif
