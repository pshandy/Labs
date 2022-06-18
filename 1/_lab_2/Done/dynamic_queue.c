#include "dynamic_queue.h"

t_record *head = NULL;
t_record *last = NULL;

/*
 * int	is_empty()
 * Проверяет пуста ли очередь.
 */

int	is_empty() {
	if (head == NULL)
		return (1);
	return (0);
}

/*
 * t_record	*create_element(char data)
 * Возвращает новый элемент с нулевыми значениями полей.
 */

t_record	*create_element(char data) {
   t_record	*elem;

   elem = malloc(sizeof(t_record));
   if (elem == NULL)
	   return (NULL);
   elem->data = data;
   elem->next = NULL;
   return (elem);
}

/*
 * void add(char data)
 * Добавляет элемент в очередь.
 */

void add(char data) {
	t_record *tmp;

	tmp = create_element(data);
	if (last == NULL) {
		head = tmp;
		last = tmp;
	}
	else {
		last->next = tmp;
        last = last->next;
	}
}

/*
 * int del()
 * Удаляет элемент из очереди.
 */

int del() {
	t_record *tmp;

	if (is_empty())
		return (-1);
	else {
		tmp = head;
		if (head->next != NULL)
			head = head->next;
		else {
			head = NULL;
			last = NULL;
		}
		free(tmp);
		tmp = NULL;
	}
	return (1);
}

/*
 * void print()
 * Выводит содержимое очереди на экран.
 */

void print() {
	t_record *tmp;

	tmp = head;
	while (tmp) {
		printf("%c ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

/*
 * void	clear_queue()
 * Освобождает выделенную память очереди.
 */

void	clear_queue()
{
	t_record	*tmp;
	t_record	*l;

 	l = head;
 	while (l)
 	{
 		if (l->next)
 			tmp = l->next;
 		else
 			tmp = NULL;
 		free(l);
 		l = tmp;
	}
 	head = NULL;
}
