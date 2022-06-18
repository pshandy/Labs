#ifndef _STATIC_QUEUE_H
#define _STATIC_QUEUE_H

# include <stdio.h>
# include <time.h>
# include <stdlib.h>

#define SIZE 5

typedef struct s_queue {
	int first;
	int last;
	int n;
	char array[SIZE];
} t_queue;

int		is_full(t_queue *queue);
int		is_empty(t_queue *queue);
int 	add(t_queue *queue, char c);
int 	del(t_queue *queue);
void 	print(t_queue *queue);
void	clear(t_queue *queue);

#endif
