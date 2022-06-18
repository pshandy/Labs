#include "static_list_p.h"

t_record	array[SIZE];
int			size;

void init() {
	for (int i = 0; i < SIZE; i++) {
		array[i].data = '\0';
		array[i].next = -1;
	}
	array[0].next = 0;
	size = 0;
}

int	find_char(char to_find) {
	int tmp;
	int i;

	i = 0;
	tmp = array[0].next;
	while (tmp != 0) {
		if (array[tmp].data == to_find)
			return (i);
		tmp = array[tmp].next;
		i++;
	}
	return (-1);
}

int	search() {
	for (int i = 0; i < SIZE; i++)
		if (array[i].next == -1)
			return (i);
	return (0);
}

int get_pos(int idx) {

	int tmp = 0;
	int b = 0;
	int i = 0;

	if (idx > size)
		return (size);
	while (i++ < idx) {
		b = tmp;
		tmp = array[tmp].next;
	}
	return (b);
}

int del(int idx) {
	int i;
	int j;

	if (size == 0 || idx <= 0 || idx > size)
		return (0);
	i = get_pos(idx);
	j = array[i].next;
	array[i].next = array[j].next;
	array[j].next = -1;
	array[j].data ='\0';
	size--;
	return (1);
}

void print() {
	int tmp;

	tmp = array[0].next;
	while (array[tmp].next != 0) {
		printf("%c ", array[tmp].data);
		tmp = array[tmp].next;
	}
	printf("%c \n", array[tmp].data);
}

int add(char c, int idx, char flag) {
	int i;
	int j;

	if (size == SIZE - 1|| idx <= 0)
		return (0);
	if (flag == '2')
		idx++;
	i = get_pos(idx);
	j = search();
	array[j].next = array[i].next;
	array[j].data = c;
	array[i].next = j;
	size++;
	return (1);
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
	5 - Напечатать.\n");

	printf("Введите номер операции:\n");

	init();

	while(1) {
		flag = _getchar();

		if (flag == '0') {
			return (0);

		} else if (flag == '1') {
			printf("Что искать:\n");
			char ch = _getchar();

			if (find_char(ch) == -1)
				printf("Ничего не найдено!\n");
			else
				printf("Элемент существует. Его индекс: %d\n", find_char(ch));

		} else if (flag == '2') {
			int		idx;
			char	ch;

			printf("Введите, что добавить:\n");
			ch = _getchar();
			if (array[0].next == 0) {
				add(ch, 1, '1');
				printf("Добавлено!\n");
				continue ;
			}
			printf("Введите после чего добавить:\n");
			// idx = _getnumber();
			idx = find_char(_getchar());
			if (!add(ch, idx, '2'))
				printf("Не добавлено!\n");
			else
				printf("Добавлено!\n");

		} else if (flag == '3') {
			int		idx;
			char	ch;

			// printf("Введите, что добавить:\n");
			// ch = _getchar();
			// printf("Введите перед чем добавить:\n");
			// idx = _getnumber();
			printf("Введите, что добавить:\n");
			ch = _getchar();
			if (array[0].next == 0) {
				add(ch, 1, '1');
				printf("Добавлено!\n");
				continue ;
			}
			printf("Введите до чего добавить:\n");
			idx = find_char(_getchar());
			if (!add(ch, idx, '1'))
				printf("Не добавлено!\n");
			else
				printf("Добавлено!\n");

		} else if (flag == '4') {
			char c;

			printf("Введите, что удалить:\n");
			if (!del(find_char(_getchar())))
				printf("Не удалось удалить!\n");
			else
				printf("Удалено!\n");

		} else if (flag == '5') {
			printf("Печатаю: \n->");
			print();
		}
	}
}

// int main() {
// 	init();
// 	add('a', 32, '2');
// 	add('b', 2, '2');
// 	//add('3', 2, '1');
// 	// print();
// 	// del(1);
// 	print();
// //	add('a', 1);
// 	//del(1);
// 	// for (int i = 0; i < SIZE; i++)
// 	// 	add('a', i);
// 	// printf("2) ");
// 	// print();
// 	// del(1);
// 	// del(2);
// 	// del(1);
// 	// printf("2) ");
// 	// print();
// 	// for (int i = 1; i < SIZE + 10; i++) {
// 	// 	printf("%d) ", 1);
// 	// 	print();
// 	// 	del(i);
// 	// }
// 	//print();
// 	// for (int i = 0; i < SIZE; i++) {
// 	// 	printf("%c ", array[i].data);
// 	// }
// //	printf("%c<\n", array[2].data);
// 	//printf("%p", (array[0]).data);
// }
