#include "static_stack.h"

/*
 * int is_full(t_stack *stack)
 * Проверяет полон ли стэк t_stack *stack.
 */

int is_full(t_stack *stack) {
	if (stack->spos == SIZE)
		return (1);
	return (0);
}

/*
 * int is_empty(t_stack *stack)
 * Проверяет пуст ли стэк t_stack *stack.
 */

int is_empty(t_stack *stack) {
	if (stack->spos == 0)
		return (1);
	return (0);
}

/*
 * int	push(t_stack *stack, char i)
 * Добавляет i в стэк.
 * Возвращает (1), если добавление удалось.
 * В случае неудачи возвращает (-1).
 */

int	push(t_stack *stack, char i) {
	if (is_full(stack))
		return (-1);
	stack->array[stack->spos] = i;
	stack->spos++;
	return (1);
}

/*
 * int	pop(t_stack *stack)
 * Удаляет элемент стэка.
 * Возвращает (1), если добавление удалось.
 * В случае неудачи возвращает (-1).
 */

int	pop(t_stack *stack) {
	if (is_empty(stack))
		return (-1);
	stack->spos--;
	stack->array[stack->spos] = 0;
	return(1);
}

/*
 * void print_stack(t_stack *stack)
 * Выводит на экран элементы стэка через пробел.
 * Если стэк пуст, ничего не происходит.
 */

void print_stack(t_stack *stack) {
	int i = stack->spos;
	if (is_empty(stack))
		return ;
	for (int j = 0; j < i; j++) {
		printf("%c ", stack->array[j]);
	}
}

/*
 * Зануляет стэк и устанавливает индекс свободного места на ноль.
 */

void clear_stack(t_stack *stack) {
	for (int i = 0; i < SIZE; i++) {
		stack->array[i] = 0;
	}
	stack->spos = 0;
}

/*
 * Добавляет n случайных элементов в стэк.
 */

void	add_random(t_stack *stack, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		if (push(stack, 'a' + (rand() % 26)) == -1) {
			printf("Стэк заполнен!\n");
			return ;
		}
	}
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

	printf("Выбрано задание 1:\n");

	printf("\
	0 - выход\n \
	1 - проверка пустоты стека\n \
	2 - проверка заполненности стекового массива\n \
	3 - добавление элемента в вершину стека\n \
	4 - удаление элемента из вершины стека\n \
	5 - вывод текущего состояния стека на экран\n \
	6 - Добавление n элементов в список\n");

	printf("Введите номер операции:\n");

	t_stack stack;
	clear_stack(&stack);

	while(1) {
		flag = _getchar();

		if (flag == '0') {
			return (0);
		} else if (flag == '1') {
			if (is_empty(&stack))
				printf(">Стэк пуст\n");
			else
				printf(">Стэк не пуст\n");

		} else if (flag == '2') {
			if (is_full(&stack))
				printf(">Стэк полон\n");
			else
				printf(">Стэк не полон\n");

		} else if (flag == '3') {
			printf("Введите какой элемент добавить:\n");
			if(push(&stack, _getchar()) == 1)
				printf(">Элемент добавлен\n");
			else
				printf(">Возможно стэк полон\n");

		} else if (flag == '4') {
			if (pop(&stack) == 1)
				printf(">Элемент удалён\n");
			else
				printf(">Возможно стэк пуст\n");
		} else if (flag == '5') {
			printf("Печатаю стэк: \n->");
			print_stack(&stack);
			printf("\n");
		} else if (flag == '6') {
			printf("Введите сколько элементов добавить:\n");
			add_random(&stack, _getnumber());
			printf(">Элементы добавлены\n");
		}
	}
}
