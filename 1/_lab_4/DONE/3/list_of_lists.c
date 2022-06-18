#include "list_of_lists.h"
#include "dynamic_list.c"

t_list_main	*ft_lstnew_main(void *data)
{
	t_list_main	*t;

	t = malloc(sizeof(*t));
	if (t == NULL)
		return (NULL);
	t->data = data;
	t->next = NULL;
	t->sublist = NULL;
	return (t);
}

void	ft_lstadd_back_main(t_list_main **lst, void *data)
{
	t_list_main		*begin;

	begin = *lst;
	if (begin == NULL)
		*lst = ft_lstnew_main(data);
	else
	{
		while (begin->next)
			begin = begin->next;
		begin->next = ft_lstnew_main(data);
	}
}

int add_to_empty_list(t_list_main **list, void *data)
{
	ft_lstadd_back_main(list, data);
	return (1);
}

int 	add_to_list(t_list_main **list, void *data_ref, void *data, int (*cmp)(void *, void *))
{
	t_list_main	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (cmp(data_ref, tmp->data) == 0)
		{
			tmp->sublist = ft_lstnew(data);
			return (1);
		}
		if (ft_lstadd_after(&(tmp->sublist), data_ref, data, cmp))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int 	add_to_list_before(t_list_main **list, void *data_ref, void *data, int (*cmp)(void *, void *))
{
	t_list_main	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (cmp(data_ref, tmp->data) == 0)
		{
			tmp->sublist = ft_lstnew(data);
			return (1);
		}
		if (ft_lstadd_before(&(tmp->sublist), data_ref, data, cmp))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int 	delete_element_from_list(t_list **list, void *data_ref, void (*del)(void *), int (*cmp)())
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (ft_lstdelone((t_list **)&(tmp->data), data_ref, del, cmp))
		{
			if (tmp->data == NULL)
			{
				t_list *head;

				head = *list;
				if (head == tmp)
					*list = tmp->next;
				else
				{
					while (head->next != tmp)
						head = head->next;
					head->next = tmp->next;
				}
				free(tmp);
			}
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	print_all(t_list_main **list)
{
	t_list_main	*tmp;

	tmp = *list;
	while (tmp)
	{
		printf("Список %c: ", *(char *)(tmp->data));
		ft_lstiter((tmp->sublist), &ft_print_char);
		tmp = tmp->next;
		printf("\n");
	}
}

void	ft_lstclear_main(t_list_main **lst, void (*del)(void *))
{
	t_list_main	*tmp;
	t_list_main	*l;

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

void	clear_all(t_list_main **list, void (*del)(void *))
{
	t_list_main	*tmp;

	tmp = *list;
	while (tmp)
	{
		ft_lstclear(&(tmp->sublist), del);
		tmp = tmp->next;
	}
	ft_lstclear_main(list, del);
}

int 	delete_element_from_array(t_list_main **list, void *data_ref, void (*del)(void *), int (*cmp)(void *, void *))
{
	t_list_main	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (cmp(data_ref, tmp->next->data) == 0)
		{
			if (tmp->sublist != NULL)
				ft_lstclear(&tmp->sublist, del);
			tmp->next = tmp->next->next;
			free(tmp);
			return (1);
		}
	}
	return (0);
}

//--------------------------Программа-------------------------

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

/*
 * _getnumber()
 * Считывает с консоли число и возвращает его.
 * Не обрабатывает неверный ввод.
 */

static int _getnumber()
{
 	char	c;
 	char	m[sizeof(char)*10];

 	scanf("%s", m);
 	while ((c = getchar()) != EOF && c != '\n');
 	return (atoi(m));
}

int main()
{
	char flag = '1';

	printf("\
	0 - Выход.\n \
	1 - Вывести все списки на экран.\n \
	2 - Добавить элемент в пустой список.\n \
	3 - Добавить элемент до заданного.\n \
	4 - Добавить элемент после заданного.\n \
	5 - Удалить элемент\n \
	6 - Удалить список.\n");

	printf("Введите номер операции:\n");

	t_list_main *main;
	main = NULL;

	t_list *lst;
	lst = NULL;

	while(1) {
		flag = _getchar();
		if (flag == '0') {
			clear_all(&main, &ft_delchar);
			exit(0);
		} else if (flag == '1') {
			printf("Вывожу списки:\n");
			print_all(&main);
		} else if (flag == '2') {
			char	*ch;

			printf("Введите, что добавить:\n");
			ch = malloc(sizeof(char));
			*ch = _getchar();
			if (!add_to_empty_list(&main, ch))
			{
				printf("Не добавлено!\n");
				free(ch);
			}
			else
				printf("Добавлено!\n");
		} else if (flag == '3') {
			char	*ch;
			char	ch2;

			printf("Введите, что добавить:\n");
			ch = malloc(sizeof(char));
			*ch = _getchar();
			printf("Введите до чего добавить:\n");
			ch2 = _getchar();
			if (!add_to_list_before(&main, (void *)&ch2, (void *)ch, &ft_compare))
			{
				printf("Не добавлено!\n");
				free(ch);
			}
			else
				printf("Добавлено!\n");
		} else if (flag == '4') {
			char	*ch;
			char	ch2;

			printf("Введите, что добавить:\n");
			ch = malloc(sizeof(char));
			*ch = _getchar();
			printf("Введите после чего добавить:\n");
			ch2 = _getchar();
			if (!add_to_list(&main, (void *)&ch2, (void *)ch, &ft_compare))
			{
				printf("Не добавлено!\n");
				free(ch);
			}
			else
				printf("Добавлено!\n");
		} else if (flag == '5') {
			char ch;

			printf("Введите что удалить:\n");
			ch = _getchar();
			if (!delete_element_from_list(&main, (void *)&ch, &ft_delchar, &ft_compare, &ft_delchar))
				printf("Не удалось удалить!\n");
			else
				printf("Удалено!\n");
		} else if (flag == '6') {
			printf("Введите какой список удалить:\n");
			if (delete_element_from_array(&main, _getchar(), &ft_delchar, &ft_delchar))
				printf("Список удалён.\n");
			else
				printf("Список не удалён.\n");
		}
	}
}

// int main()
// {
// 	printf("Started\n");
//
// 	t_list *list;
// 	list = NULL;
//
// 	add_to_empty_list(&list, "6");
// 	add_to_empty_list(&list, "7");
// 	add_to_empty_list(&list, "8");
// 	add_to_list(&list, "8", "a", &ft_compare);
// 	add_to_list_before(&list, "a", "m", &ft_compare);
// 	delete_element_from_list(&list, "8", &ft_delchar, &ft_compare);
// 	// printf("%c\n", *(char *)(((t_list *)(list->data))->data));
// 	// printf("%p\n", *(char *)((((t_list *)(list->data))->next)->data));
// 	// printf("%c\n", *(char *)(((t_list *)(list->next->data))->data));
// 	print_all(&list);
// 	printf("End.");
// }
