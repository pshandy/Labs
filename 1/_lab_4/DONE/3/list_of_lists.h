#ifndef _LIST_OF_LISTS_H
#define _LIST_OF_LISTS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list_main
{
	void 					*data;
	struct s_list			*sublist;
	struct s_list_main		*next;
} t_list_main;

#endif
