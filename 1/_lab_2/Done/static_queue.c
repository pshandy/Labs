#include "static_queue.h"

/*
 * int is_full(t_queue *queue)
 * Проверяет заполнена ли очередь.
 */

int	is_full(t_queue *queue) {
	if (queue->n == SIZE)
		return (1);
	return (0);
}

/*
 * int is_empty(t_queue *queue)
 * Проверяет пуста ли очередь.
 */

int	is_empty(t_queue *queue) {
	if (queue->n == 0)
		return (1);
	return (0);
}

/*
 * clear(t_queue *queue)
 * Инициализирует очередь нулевыми значениями.
 */

void	clear(t_queue *queue) {
	for (int i = 0; i < SIZE; i++)
		queue->array[i] = '\0';
	queue->first = 0;
	queue->last = 0;
	queue->n = 0;
}

/*
 * void add(t_queue *queue, char c)
 * Добавляет элемент 'c' в очередь.
 */

int add(t_queue *queue, char c) {
	if (is_full(queue))
		return (-1);
	queue->array[queue->last] = c;
	queue->last = (queue->last + 1) % SIZE;
	// if (queue->last == SIZE)
	// 	queue->last = 0;
	queue->n++;
	return (1);
}

/*
 * void del(t_queue *queue)
 * Удаляет элемент из очереди.
 */

int del(t_queue *queue) {
	if (is_empty(queue))
		return (-1);
	queue->array[queue->first] = '\0';
	queue->first++;
	if (queue->first == SIZE)
		queue->first = 0;
	queue->n--;
	return (1);
}
// 1 _ 2 3 4 5
/*
 * void print(t_queue *queue)
 * Выводит очередь на экран.
 */

void	print(t_queue *queue) {
	int flag = 0;
	int i = queue->first;

	do {
		printf("%c ", queue->array[i]);
		i++;
		if (i == SIZE)
			i = 0;
	} while (i % SIZE != queue->last);
}

// void print(t_queue *queue) {
// 	for (int i = 0; i < SIZE; i++) {
// 		if (queue->array[i] == '\0')
// 			printf("  ");
// 		else
// 			printf("%c ", queue->array[i]);
// 	}
// }

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

// int main()
// {
// 	t_queue queue;
// 	clear(&queue);
//
// 	add(&queue, '1');
// 	add(&queue, '2');
// 	add(&queue, '3');
// 	add(&queue, '4');
// 	add(&queue, '5');
// 	printf("%d ", queue.first);
// 	printf("%d ", queue.last);
// 	printf("%d\n", queue.n);
// 	del(&queue);
// 	printf("%d ", queue.first);
// 	printf("%d ", queue.last);
// 	printf("%d\n", queue.n);
// 	add(&queue, '6');
// 	printf("%d\n", queue.first);
// 	printf("%d\n", queue.last);
// 	printf("%d\n", queue.n);
//
// 	for (int i = queue.first; i <= queue.n; i++)
// 		printf("%c ", queue.array[i % SIZE]);
// 	printf("\n");
//
// 		for (int i = 0; i < SIZE; i++) {
// 			if (queue.array[i] == '\0')
// 				printf("  ");
// 			else
// 				printf("%c ", queue.array[i]);
// 		}
//
//
// }

int main()
{
	char flag = '1';

	printf("Выбрано задание 1:\n");

	printf("\
	0 - выход\n \
	1 - проверка пустоты очереди\n \
	2 - проверка заполненности стековой очереди\n \
	3 - добавление элемента в очередь\n \
	4 - удаление элемента из очереди\n \
	5 - вывод текущего состояния очереди на экран\n");

	printf("Введите номер операции:\n");

	t_queue queue;
	clear(&queue);

	while(1) {
		flag = _getchar();

		if (flag == '0') {
			return (0);
		} else if (flag == '1') {
			if (is_empty(&queue))
				printf(">Очередь пуста\n");
			else
				printf(">Очередь не пуста\n");

		} else if (flag == '2') {
			if (is_full(&queue))
				printf(">Очередь полна\n");
			else
				printf(">Очередь не полна\n");

		} else if (flag == '3') {
			printf("Введите какой элемент добавить:\n");
			if(add(&queue, _getchar()) == 1)
				printf(">Элемент добавлен\n");
			else
				printf(">Возможно очередь полна\n");

		} else if (flag == '4') {
			if (del(&queue) == 1)
				printf(">Элемент удалён\n");
			else
				printf(">Возможно очередь пуста\n");
		} else if (flag == '5') {
			printf("Печатаю очередь: \n->");
			print(&queue);
			printf("\n");
		}
	}
}
