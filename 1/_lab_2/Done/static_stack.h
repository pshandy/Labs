#ifndef _STATIC_STACK_H
#define _STATIC_STACK_H

# include <stdio.h>
# include <time.h>
# include <stdlib.h>

#define SIZE 64

typedef struct	s_stack {
	char	array[SIZE];
 	int		spos;
}				t_stack;

int 	is_full(t_stack *stack);
int 	is_empty(t_stack *stack);
int		push(t_stack *stack, char i);
int		pop(t_stack *stack);
void 	print_stack(t_stack *stack) ;
void	clear_stack(t_stack *stack);
void	add_random(t_stack *stack, int n);

#endif
