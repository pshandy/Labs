#include "dynamic_queue.c"
#include "dynamic_queue.h"

//-----------------------Программа---------------------------

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
 * _getchar()
 * Считывает с консоли число и возвращает его.
 * Не обрабатывает неверный ввод.
 */

int main()
{
	char flag = '1';

	printf("Выбрано задание 5:\n");

	printf("\
	0 - выход\n \
	1 - проверка пустоты стека\n \
	2 - добавление элемента в очередь\n \
	3 - удаление элемента из очереди\n \
	4 - вывод текущего состояния очереди\n");

	printf("Введите номер операции:\n");

	while(1) {
		flag = _getchar();

		if (flag == '0') {
			clear_queue();
			return (0);

		} else if (flag == '1') {
			if (is_empty())
				printf(">Очередь пуста\n");
			else
				printf(">Очередь не пуста\n");

		} else if (flag == '2') {
			printf("Введите какой элемент добавить:\n");
			add(_getchar());
			printf(">Элемент добавлен\n");

		} else if (flag == '3') {
			if (del() == -1)
				printf(">Возможно очередь пуста\n");
			else
				printf("Элемент удалён\n");

		} else if (flag == '4') {
			printf("Печатаю очередь: \n->");
			print();
			printf("\n");
		}
	}
}
