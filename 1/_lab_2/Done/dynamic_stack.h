#ifndef _DYNAMIC_STACK_H
#define _DYNAMIC_STACK_H

# include <stdio.h>
# include <time.h>
# include <stdlib.h>

typedef struct	s_stack {
	char	data;
	struct	s_stack *next;
}				t_stack;

t_stack	*create_element(char data);
void	push(t_stack **stack, char data);
void	print(t_stack *stack);
int 	is_empty(t_stack *stack);
int		pop(t_stack **stack);
void	clear(t_stack **head);
void	add_random_d(t_stack **stack, int n);
void 	move(t_stack **stack_a, t_stack **stack_b);

#endif
