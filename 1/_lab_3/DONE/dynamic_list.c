#include "dynamic_list.h"

t_list	*ft_lstnew(void *data)
{
	t_list	*t;

	t = malloc(sizeof(*t));
	if (t == NULL)
		return (NULL);
	t->data = data;
	t->next = NULL;
	return (t);
}

int	ft_lstadd_before(t_list **begin_list, void *data_ref, void *data, int (*cmp)(void *, void *))
{
	t_list	*tmp;
	t_list	*head;

	if (*begin_list == NULL)
	{
		*begin_list = ft_lstnew(data);
		return (1);
	}
	if (cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = ft_lstnew(data);
		tmp->next = *begin_list;
		*begin_list = tmp;
		return (1);
	}
	head = *begin_list;
	while (head)
	{
		if (head->next == NULL)
			return (0);
		if (cmp(head->next->data, data_ref) == 0)
		{
			tmp = ft_lstnew(data);
			tmp->next = head->next;
			head->next = tmp;
			return (1);
		}
		head = head->next;
	}
	return (0);
}

int	ft_lstadd_after(t_list **begin_list, void *data_ref, void *data, int (*cmp)())
{
	t_list	*tmp;
	t_list	*head;

	if (*begin_list == NULL)
	{
		*begin_list = ft_lstnew(data);
		return (1);
	}
	head = *begin_list;
	while (head)
	{
		if (cmp(head->data, data_ref) == 0)
		{
			tmp = ft_lstnew(data);
			tmp->next = head->next;
			head->next = tmp;
			return (1);
		}
		head = head->next;
	}
	return (0);
}

int ft_lstdelone(t_list **begin_list, void *data_ref, void (*del)(void *), int (*cmp)())
{
	t_list	*tmp;
	t_list	*head;

	if (del == NULL || cmp == NULL || data_ref == NULL || *begin_list == NULL)
		return (0);
	if (cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		del(tmp->data);
		free(tmp);
		return (1);
	}
	head = *begin_list;
	while (head)
	{
		if (head->next == NULL)
			return (0);
		if ((*cmp)(head->next->data, data_ref) == 0)
		{
			tmp = head->next;
			head->next = head->next->next;
			del(tmp->data);
			free(tmp);
			return (1);
		}
		head = head->next;
	}
	return (0);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		f(lst->data);
		lst = lst->next;
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*l;

	if (del == NULL)
		return ;
	l = *lst;
	while (l)
	{
		if (l->next)
			tmp = l->next;
		else
			tmp = NULL;
		del(l->data);
		free(l);
		l = tmp;
	}
	*lst = NULL;
}

int	ft_move(t_list **begin_list, t_list **stack, void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*tmp;
	t_list	*head;

	if (cmp == NULL || data_ref == NULL || *begin_list == NULL)
		return (0);
	if (cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
	 	tmp->next = *stack;
		*stack = tmp;
		return (1);
	}
	head = *begin_list;
	while (head)
	{
		if (head->next == NULL)
			return (0);
		if ((*cmp)(head->next->data, data_ref) == 0)
		{
			tmp = head->next;
			head->next = head->next->next;
			tmp->next = *stack;
			*stack = tmp;
			return (1);
		}
		head = head->next;
	}
	return (0);
}

t_list *ft_search(t_list **head, void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (cmp(tmp->data, data_ref) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

/*
 * Функции-обработчики войдовских значений.
*/

int		ft_compare(void *a, void *b)
{
	if (a == NULL || b == NULL)
		return (1);
	if (*((char *)a) == *((char *)b))
		return (0);
	return (1);
}

void	ft_print_char(void *data)
{
	printf("%c ", *((char *)data));
}

void	ft_delchar(void *data)
{
	free(data);
}

//--------------------------Программа

/*
 * _getchar()
 * Считывает с консоли 1 символ и возвращает его.
 * Не обрабатывает неверный ввод.
 */

static char _getchar()
{
	char	c;
	char	m;

	scanf("%c", &m);
	while ((c = getchar()) != EOF && c != '\n');
	return (m);
}

int main()
{
	char flag = '1';

	printf("\
	0 - Выход.\n \
	1 - Добавить элемент в список (до).\n \
	2 - Добавить элемент в список (после).\n \
	3 - Удаление элемента.\n \
	4 - Перемещение элемента в стэк.\n \
	5 - Вывод стэка на экран\n \
	6 - Вывод списка на экран.\n");

	printf("Введите номер операции:\n");

	t_list *list;
	t_list *stack;

	list = NULL;
	stack = NULL;

	while(1) {
		flag = _getchar();

		if (flag == '0') {
			ft_lstclear(&list, &ft_delchar);
			ft_lstclear(&stack, &ft_delchar);
			return (0);

		} else if (flag == '1') {
			char	*ch;
			char	ch2;

			printf("Введите, что добавить:\n");
			ch = malloc(sizeof(char));
			*ch = _getchar();
			printf("Введите до чего добавить:\n");
			ch2 = _getchar();

			if (!ft_lstadd_before(&list, (void *)&ch2, (void *)ch, &ft_compare))
			{
				printf("Не добавлено!\n");
				free(ch);
			}
			else
				printf("Добавлено!\n");

		} else if (flag == '2') {
			char	*ch;
			char	ch2;

			printf("Введите, что добавить:\n");
			ch = malloc(sizeof(char));
			*ch = _getchar();
			printf("Введите после чего добавить:\n");
			ch2 = _getchar();
			if (!ft_lstadd_after(&list, (void *)&ch2, (void *)ch, &ft_compare))
			{
				printf("Не добавлено!\n");
				free(ch);
			}
			else
				printf("Добавлено!\n");

		} else if (flag == '3') {
			char ch;

			printf("Введите что удалить:\n");
			ch = _getchar();
			if (!ft_lstdelone(&list, (void *)&ch, &ft_delchar, &ft_compare))
				printf("Не удалось удалить!\n");
			else
				printf("Удалено!\n");

		} else if (flag == '4') {
			char	ch;

			printf("Введите перемещаемый элемент:\n");
			ch = _getchar();
			if (!ft_move(&list, &stack, (void *)&ch, &ft_compare))
				printf("Не удалось переместить!\n");
			else
				printf("Перемещено!\n");
		} else if (flag == '5') {
			printf("Печатаю стэк: \n->");
			ft_lstiter(stack, &ft_print_char);
			printf("\n");
		} else if (flag == '6') {
			printf("Печатаю: \n->");
			ft_lstiter(list, &ft_print_char);
			printf("\n");
		}
	}
}
