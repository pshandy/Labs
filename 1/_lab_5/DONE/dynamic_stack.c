#include "dynamic_stack.h"

t_stack	*create_element(void *data) {
   t_stack	*elem;

   elem = malloc(sizeof(t_stack));
   if (elem == NULL)
	   return (NULL);
   elem->data = data;
   elem->next = NULL;
   return (elem);
}

void	push(t_stack **stack, void *data) {
	t_stack *new;

	new = create_element(data);
	if (*stack) {
		new->next = *stack;
		*stack = new;
	}
	else
		*stack = new;
}

int is_empty(t_stack *stack) {
	return (stack == NULL ? 1 : 0);
}

int	pop(t_stack **stack) {
	t_stack	*tmp;

	if (is_empty(*stack))
		return (-1);
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	tmp = NULL;
	return (1);
}

void	*get(t_stack **stack) {
	t_stack	*tmp;

	if (is_empty(*stack))
		return (NULL);
	tmp = *stack;
	*stack = (*stack)->next;
	return (tmp);
}

void	clear(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*l;

 	l = *head;
 	while (l)
 	{
 		if (l->next)
 			tmp = l->next;
 		else
 			tmp = NULL;
 		free(l);
 		l = tmp;
	}
 	*head = NULL;
}
