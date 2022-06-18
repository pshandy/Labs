#include "array_of_lists.h"
#include "dynamic_list.c"

void	print_all(t_list **array)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (array[i] != NULL)
		{
			printf("Список %d: ", i);
			ft_lstiter(array[i], &ft_print_char);
			printf("\n");
		}
	}
	printf("Списки напечатаны.\n");
}

int	add_to_empty_list(t_list **array, void *data)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (array[i] == NULL) {
			array[i] = ft_lstnew(data);
			return (1);
		}
	}
	return (0);
}

int add_to_list(t_list **array, void *data_ref, void *data, int (*cmp)(void *, void *))
{
	for (int i = 0; i < SIZE; i++)
	{
		if (ft_lstadd_after(&array[i], data_ref, data, cmp))
			return (1);
	}
	return (0);
}

int add_to_list_before(t_list **array, void *data_ref, void *data, int (*cmp)(void *, void *))
{
	for (int i = 0; i < SIZE; i++)
	{
		if (ft_lstadd_before(&array[i], data_ref, data, cmp))
			return (1);
	}
	return (0);
}

int delete_element_from_list(t_list **array, void *data_ref, void (*del)(void *), int (*cmp)())
{
	for (int i = 0; i < SIZE; i++)
	{
		if (ft_lstdelone(&array[i], data_ref, del, cmp))
			return (1);
	}
	return (0);
}

int delete_element_from_array(t_list **array, int i, void (*del)(void *))
{
	if (i >= 0 && i <= SIZE && array[i] != NULL)
	{
		ft_lstclear(&array[i], del);
		return (1);
	}
	return (0);
}

void	clear_all(t_list **array, void (*del)(void *))
{
	for (int i = 0; i < SIZE; i++)
		delete_element_from_array(array, i, del);
}

t_list	*search_elem(t_list **array, void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*tmp;

	for (int i = 0; i < SIZE; i++)
	{
		tmp = ft_search(&array[i], data_ref, cmp);
		if (tmp)
			return (tmp);
	}
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

	t_list *array[SIZE];
	for (int i = 0; i < SIZE; i++)
		array[i] = NULL;

	while(1) {
		flag = _getchar();
		if (flag == '0') {
			clear_all(array, &ft_delchar);
			exit(0);
		} else if (flag == '1') {
			printf("Вывожу списки:\n");
			print_all(array);
		} else if (flag == '2') {
			char	*ch;

			printf("Введите, что добавить:\n");
			ch = malloc(sizeof(char));
			*ch = _getchar();
			if (!add_to_empty_list(array, ch))
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
			if (!add_to_list_before(array, (void *)&ch2, (void *)ch, &ft_compare))
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
			if (!add_to_list(array, (void *)&ch2, (void *)ch, &ft_compare))
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
			if (!delete_element_from_list(array, (void *)&ch, &ft_delchar, &ft_compare))
				printf("Не удалось удалить!\n");
			else
				printf("Удалено!\n");
		} else if (flag == '6') {
			printf("Введите какой список удалить:\n");
			if (delete_element_from_array(array, _getnumber(), &ft_delchar))
				printf("Список удалён.\n");
			else
				printf("Список не удалён.\n");
		}
	}
}

// int main()
// {
// 	printf("Compiled!\n");
// 	t_list *array[SIZE];
// 	for (int i = 0; i < SIZE; i++)
// 		array[i] = NULL;
// 	// add_to_empty_list(array, "0");
// 	add_to_empty_list(array, "1");
// 	add_to_empty_list(array, "2");
// 	add_to_empty_list(array, "3");
// 	add_to_empty_list(array, "4");
// 	add_to_list(array, "4", "m", &ft_compare);
// 	add_to_list_before(array, "0", "a", &ft_compare);
// 	add_to_list_before(array, "0", "a", &ft_compare);
// 	add_to_list_before(array, "0", "a", &ft_compare);
// 	// ft_lstdelone(array, "0", &ft_delchar, &ft_compare);
// 	delete_element_from_array(array, 0, &ft_delchar);
// 	print_all(array);
// 	printf("End.");
// }
