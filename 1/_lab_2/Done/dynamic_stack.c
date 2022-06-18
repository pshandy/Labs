#include "dynamic_stack.h"

/* t_stack	*create_element(char data)
 * Выделяет память для элемента стэка и возвращает указатель на неё.
 * Устанавливает переданное значение data в поле data элемента.
 * Указатель на следующий элемент устанавливается на NULL.
 * В случае неудачи возвращается NULL.
 */

t_stack	*create_element(char data) {
   t_stack	*elem;

   elem = malloc(sizeof(t_stack));
   if (elem == NULL)
	   return (NULL);
   elem->data = data;
   elem->next = NULL;
   return (elem);
}

/*
 * push(t_stack **stack, char data)
 * Добавляет элемент 'new' в стэк
 */

void	push(t_stack **stack, char data) {
	t_stack *new;

	new = create_element(data);
	if (*stack) {
		new->next = *stack;
		*stack = new;
	}
	else
		*stack = new;
}

/*
 * void	print(t_stack *stack)
 * Выводит элементы стэка на экран.
 */

void	print(t_stack *stack) {
	t_stack	*tmp;

	tmp = stack;
	while(tmp) {
		printf("%c ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

/*
 * int is_empty(t_stack *stack)
 * Проверяет пуст ли стэк
 */

int is_empty(t_stack *stack) {
	return (stack == NULL ? 1 : 0);
}

/*
 * pop(t_stack **stack)
 * Удаляет элементы с вершины стэка
 */

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

/*
 * clear(t_stack **head)
 * Очищает стэк.
 */

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

 /*
  * void	add_random_d(t_stack **stack, int n)
  * Добавляет n случайных элементов.
  */

void	add_random_d(t_stack **stack, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		push(stack, 'a' + (rand() % 26));
	}
}

 /*
  * move_d(t_d_stack **stack_a, t_d_stack **stack_b)
  * Перемещает элемент стэка 'а' в стэк 'б'.
  */

void move(t_stack **stack_a, t_stack **stack_b) {
	t_stack *tmp;

 	if (*stack_a == NULL)
 		return ;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
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

	printf("Выбрано задание 2:\n");

	t_stack *stack_a;
	stack_a = NULL;

	t_stack *stack_b;
	stack_b = NULL;

	printf("\
	0 - выход\n \
	1 - проверка пустоты стека\n \
	2 - добавление элемента в вершину стека\n \
	3 - удаление элемента из вершины стека\n \
	4 - вывод текущего состояния стека на экран\n \
	5 - Добавление n элементов в список\n \
	6 - вывод текущего состояния стека удалённых элементов на экран\n");

	printf("Введите номер операции:\n");

	while(1) {
		flag = _getchar();

		if (flag == '0') {
			clear(&stack_a);
			clear(&stack_b);
			return (0);

		} else if (flag == '1') {
			if (is_empty(stack_a))
				printf(">Стэк пуст\n");
			else
				printf(">Стэк не пуст\n");

		} else if (flag == '2') {
			printf("Добавить новый(у) или Переместить(любой символ)?\n");
			if (_getchar() == 'y') {
				printf("Введите какой элемент добавить:\n");
				push(&stack_a, _getchar());
				printf(">Элемент добавлен\n");
			} else {
				move(&stack_b, &stack_a);
				printf(">Done.\n");
			}

		} else if (flag == '3') {
			printf("Удалить(у) или Переместить(любой символ)?\n");
			if (_getchar() == 'y') {
				if (pop(&stack_a) == -1)
					printf(">Возможно стэк пуст\n");
				else
					printf("Элемент удалён\n");
			} else {
				move(&stack_a, &stack_b);
				printf(">Done.\n");
			}
		} else if (flag == '4') {
			printf("Печатаю стэк: \n->");
			print(stack_a);
			printf("\n");
		} else if (flag == '5') {
			printf("Введите сколько элементов добавить:\n");
			add_random_d(&stack_a, _getnumber());
			printf(">Элементы добавлены\n");
		} else if (flag == '6') {
			printf("Печатаю стэк удалённых элементов: \n->");
			print(stack_b);
			printf("\n");
		}
	}
}
