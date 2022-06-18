#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEYS 10
#define	ARRAY_SIZE 7

typedef struct	s_list
{
	char 	*data;
	struct 	s_list *prev;
	struct 	s_list *next;
}				t_list;

void	ft_init(t_list **list)
{
	*list = malloc(sizeof(t_list));
	if (list == NULL)
		return ;

	(*list)->data = NULL;
	(*list)->prev = *list;
	(*list)->next = *list;
}

void	ft_lstadd_back(t_list **list, char *data)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->data = data;
	new->prev = (*list)->prev;
	new->next = *list;
	(*list)->prev->next = new;
	(*list)->prev = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*next;

	if (*lst == NULL)
		return ;

	next = (*lst)->next;
	while (next != *lst)
	{
		tmp = next;
		free(tmp->data);
		next = next->next;
		free(tmp);
	}
	free(*lst);
	*lst = NULL;
}

void	ft_print(t_list **list)
{
	t_list	*tmp;

	tmp = (*list)->next;
	while (tmp != *list)
	{
		printf("%s ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

static char _getchar() {
	char	c;
	char	m;

	scanf("%c", &m);
	while ((c = getchar()) != EOF && c != '\n');
	return (m);
}

static char *getstring() {
	char	c;
	char	m[sizeof(char)*10];
	char	*str;


	scanf("%s", m);
	while ((c = getchar()) != EOF && c != '\n');
	str = strdup(m);
	return (str);
}

int contains(char *keys[], char *str) {
	for (int i = 0; i < KEYS; i++) {
		if (strcmp(keys[i], str) == 0)
			return (1);
	}
	return (0);
}

int get_hash(char *str) {
    int	code;
	int strLen;

	code = 0;
	strLen = strlen(str);
    for (int i = 0; i < strLen; i++)
        code += str[i];
    code = code % ARRAY_SIZE;
    return code;
}

void add(char **str, t_list **array) {
	int hashcode;
	int compares;

	hashcode = get_hash(*str);
	compares = 0;
	if (array[hashcode]->next == array[hashcode] && array[hashcode]->prev == array[hashcode]) {
		ft_lstadd_back(&array[hashcode], *str);
		printf("Ключ добавлен\n");
	}
	else {
		t_list *tmp;
		int flag = 1;

		tmp = (array[hashcode])->next;
		while (tmp != array[hashcode])
		{
			compares++;
			if (strcmp(tmp->data, *str) == 0) {
				printf("Элемент уже есть в списке\n");
				flag = 0;
				break ;
			}
			tmp = tmp->next;
		}
		if (flag)
			ft_lstadd_back(&array[hashcode], *str);
	}
	printf("Количество сравнений: %d\n", compares);
}

void find(char **str, t_list **array) {
	int hashcode;
	int compares;

	compares = 0;
	hashcode = get_hash(*str);
	if (array[hashcode]->next == array[hashcode] && array[hashcode]->prev == array[hashcode])
		printf("Элемента нет в таблице.\n");
	else {
		t_list *tmp;
		int flag = 1;

		tmp = (array[hashcode])->next;
		while (tmp != array[hashcode])
		{
			compares++;
			if (strcmp(tmp->data, *str) == 0) {
				printf("Элемент есть в списке, его позиция: %d.\n", hashcode);
				flag = 0;
				break ;
			}
			tmp = tmp->next;
		}
		if (flag)
			printf("Элемента нет в списке.\n");
	}
	printf("Количество сравнений: %d\n", compares);
}

void delete(char **str, t_list **array) {
	int hashcode;

	hashcode = get_hash(*str);
	if (array[hashcode]->next == array[hashcode] && array[hashcode]->prev == array[hashcode])
		printf("Элемента нет в таблице.\n");
	else {
		t_list *tmp;
		int flag = 1;

		tmp = (array[hashcode])->next;
		while (tmp != array[hashcode])
		{
			if (strcmp(tmp->data, *str) == 0) {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				printf("Удалено\n");
				free(tmp->data);
				free(tmp);
				flag = 0;
				break ;
			}
			tmp = tmp->next;
		}
		if (flag)
			printf("Элемента нет в списке.\n");
	}
}

int main()
{
	char	*keys[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven",
							"Eight", "Nine", "Ten"};
	char	flag = '1';
	t_list	**array = malloc(sizeof(t_list *) * ARRAY_SIZE);

	for (int i = 0; i < ARRAY_SIZE; i++)
		ft_init(&array[i]);

	printf("\
	Введите команду:\n\
	0 - Выход из программы.\n\
	1 - Добавление элемента в таблицу.\n\
	2 - Поиск элемента.\n\
	3 - Вывод элементов.\n\
	4 - Удаление элемента.\n\
	5 - Заполнение таблицы.\n\
	");

	printf("Введите номер операции:\n");

	while(1) {
		flag = _getchar();
		if (flag == '0') {
			printf("-----------------------------------\n");
			printf("Выход.\n");
			for (int i = 0; i < ARRAY_SIZE; i++)
			//	if (array[i])
					ft_lstclear(&array[i]);
			free(array);
			return (0);
		} else if (flag == '1') {
			char	*str;
			char	c;

			printf("-----------------------------------\n");
			printf("Введите ключ, который нужно добавить:\n");
			str = getstring();
			//while (!contains(keys, str))
			//	str = getstring();
			add(&str, array);
		} else if (flag == '2') {
			char	*str;
			char	c;

			printf("-----------------------------------\n");
			printf("Введите ключ, который нужно найти:\n");
			str = getstring();
			//while (!contains(keys, str))
			//	str = getstring();
			find(&str, array);
			free(str);
		} else if (flag == '3') {
			printf("-----------------------------------\n");
			for (int i = 0; i < ARRAY_SIZE; i++) {
				printf("%d - ", i);
				ft_print(&array[i]);
			}
		} else if (flag == '4') {
			char	*str;
			char	c;

			printf("-----------------------------------\n");
			printf("Введите ключ, который нужно удалить:\n");
			str = getstring();
			//while (!contains(keys, str))
			//	str = getstring();
			delete(&str, array);
			free(str);
		}
		else if (flag == '5') {
			int smol[] = {11, 13, 14};

			for (int i = 0; i < 3; i++) {
				int	 size = smol[i];
				t_list **arr = malloc(sizeof(t_list *) * size);
				for (int j = 0; j < size; j++)
					ft_init(&arr[j]);

				for (int j = 0; j < KEYS; j++) {
					char *s = strdup(keys[j]);
					add(&s, arr);
				}
				for (int j = 0; j < KEYS; j++) {
					char *s = strdup(keys[j]);
					find(&s, arr);
					free(s);
				}
				for (int k = 0; k < size; k++) {
					printf("%d - ", k);
					ft_print(&arr[k]);
				}
				for (int k = 0; k < size; k++)
					if (arr[k])
						ft_lstclear(&arr[k]);
				free(arr);
				printf("-----------------------------------\n");
			}
		}
	}
}
