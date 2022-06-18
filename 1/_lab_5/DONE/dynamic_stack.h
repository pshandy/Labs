#ifndef _DYNAMIC_STACK_H
#define _DYNAMIC_STACK_H

# include <stdio.h>
# include <time.h>
# include <stdlib.h>

typedef struct	s_stack {
	void	*data;
	struct	s_stack *next;
}				t_stack;

t_stack	*create_element(void *data);
void	push(t_stack **stack, void *data);
int 	is_empty(t_stack *stack);
int		pop(t_stack **stack);
void	clear(t_stack **head);
void	*get(t_stack **stack);

#endif
