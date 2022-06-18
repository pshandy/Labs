#include "static_list.h"

int		search(t_list *list, char to_find) {
	for (int i = 0; i < list->size; i++) {
		if (list->array[i] == to_find)
			return (i);
	}
	return (-1);
}

int	del(t_list *list, int index) {
	if (index >= list->size || index < 0)
		return (0);
	for (int i = index; i < list->size - 1; i++)
		list->array[i] = list->array[i + 1];
	list->array[list->size - 1] = '\0';
	list->size--;
	return (1);
}

int	add(t_list *list, char c, int index, char flag) {
	if (list->size == SIZE || index < 0)
		return (0);
	if (flag == '2')
		index++;
	if (index < list->size) {
		for (int i = list->size; i >= index; i--)
			list->array[i] = list->array[i - 1];
		list->array[index] = c;
		list->size++;
	} else {
		list->array[list->size] = c;
		list->size++;
	}
	return (1);
}

int	add_cmp(t_list *list, char c) {
	if (list->size == SIZE)
		return (0);
	for (int i = 0; i < list->size; i++) {
		if (c < list->array[i]) {
			add(list, c, i, '1');
			return (1);
		}
	}
	add(list, c, SIZE, '1');
	return (1);
}

void print(t_list *list) {
	for (int i = 0; i < list->size; i++)
		printf("%c ", list->array[i]);
	printf("\n");
}

void init(t_list *list) {
	list->size = 0;
	for (int i = 0; i < SIZE; i++)
		list->array[i] = '\0';
}

//----------------Программа----------------------

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
	1 - Найти заданный элемент.\n \
	2 - Добавить элемент в список (после).\n \
	3 - Добавить элемент в список (до).\n \
	4 - Удаление элемента.\n\
	5 - Добавить в режиме упорядоченного списка.\n\
	6 - Напечатать.\n");

	printf("Введите номер операции:\n");

	t_list list;
	init(&list);

	while(1) {
		flag = _getchar();

		if (flag == '0') {
			return (0);

		} else if (flag == '1') {
			printf("Что искать:\n");
			char ch = _getchar();

			if (search(&list, ch) == -1)
				printf("Ничего не найдено!\n");
			else
				printf("Элемент существует. Его индекс: %d\n", search(&list, ch));

		} else if (flag == '2') {
			int		idx;
			char	ch;

			printf("Введите, что добавить:\n");
			ch = _getchar();
			printf("Введите после чего добавить:\n");
			idx = _getnumber();
			if (!add(&list, ch, idx, '2'))
				printf("Не добавлено!\n");
			else
				printf("Добавлено!\n");
		} else if (flag == '3') {
			int		idx;
			char	ch;

			printf("Введите, что добавить:\n");
			ch = _getchar();
			printf("Введите перед чем добавить:\n");
			idx = _getnumber();
			if (!add(&list, ch, idx, '1'))
				printf("Не добавлено!\n");
			else
				printf("Добавлено!\n");

		} else if (flag == '4') {
			char c;

			printf("Введите, что удалить:\n");
			if (!del(&list, search(&list, _getchar())))
				printf("Не удалось удалить!\n");
			else
				printf("Удалено!\n");

		} else if (flag == '5') {
			char	ch;

			printf("Добавить в режиме упорядоченного списка: \n->");
			printf("Введите, что добавить:\n");
			ch = _getchar();
			if (!add_cmp(&list, ch))
				printf("Не добавлено!\n");
			else
				printf("Добавлено!\n");

		} else if (flag == '6') {
			printf("Печатаю: \n->");
			print(&list);
		}
	}
}

// int main() {
// 	t_list list;
// 	init(&list);
// 	add(&list, 'a', 0, '2');
// 	add(&list, 'a', 0, '2');
// 	add(&list, 'b', 0, '2');
// 	add(&list, 'a', 0, '2');
// 	add(&list, 'a', 0, '2');
// 	add(&list, 'c', 4, '2');
// 	print(&list);
// }
