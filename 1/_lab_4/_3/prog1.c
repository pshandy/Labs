#include "list_of_lists.c"

//--------------------------Программа

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

int main()
{
	char flag = '1';

	printf("\
	0 - Выход.\n \
	1 - Вывести всю структуру.\n \
	2 - Вывести всю структуру в обратном направлении.\n \
	-------------------------Главный список-----------------------------\n \
	3 - Добавить элемент в главный список до заданного.\n \
	4 - Добавить элемент в главный список после заданного.\n \
	5 - Удалить элемент главного списка\n \
	----------------------------Подсписки-------------------------------\n \
	6 - Добавить элемент в подсписок до заданного.\n \
	7 - Добавить элемент в подсписок после заданного.\n \
	8 - Добавить элемент в пустой подсписок.\n \
	9 - Удалить элемент подсписка\n \
	\n");

	printf("Введите номер операции:\n");

	t_list_main *list;
	ft_init_main(&list);

	while(1) {
		flag = _getchar();
		if (flag == '0') {
			ft_lstclear_main(&list, &ft_delchar);
			exit(0);
		} else if (flag == '1') {
			printf("Вывожу главный список в прямом направлении:\n>");
			ft_print_main(&list, &p);
		} else if (flag == '2') {
			printf("Вывожу главный список в обратном направлении:\n>");
			ft_print_rev_main(&list, &p);
		} else if (flag == '3') {
			char	*ch;
			char	ch2;

			printf("Введите, что добавить:\n");
			ch = malloc(sizeof(char));
			*ch = _getchar();
			printf("Введите до чего добавить:\n");
			ch2 = _getchar();
			if (!ft_lstadd_before_main(&list, (void *)ch, (void *)&ch2, &cmp))
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
			if (!ft_lstadd_main(&list, (void *)ch, (void *)&ch2, &cmp))
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
			if (!ft_lstdel_main(&list, (void *)&ch, &ft_delchar, &cmp))
				printf("Не удалось удалить!\n");
			else
				printf("Удалено!\n");
		} else if (flag == '6') {
			char	*ch;
			char	ch2;

			printf("Введите, что добавить:\n");
			ch = malloc(sizeof(char));
			*ch = _getchar();
			printf("Введите до чего добавить:\n");
			ch2 = _getchar();
			if (!add_to_list_before(&list, (void *)&ch2, (void *)ch, &cmp))
			{
				printf("Не добавлено!\n");
				free(ch);
			}
			else
				printf("Добавлено!\n");
		} else if (flag == '7') {
			char	*ch;
			char	ch2;

			printf("Введите, что добавить:\n");
			ch = malloc(sizeof(char));
			*ch = _getchar();
			printf("Введите после чего добавить:\n");
			ch2 = _getchar();
			if (!add_to_list(&list, (void *)&ch2, (void *)ch, &cmp))
			{
				printf("Не добавлено!\n");
				free(ch);
			}
			else
				printf("Добавлено!\n");
		} else if (flag == '8') {
			char	*ch;

			printf("Введите, что добавить:\n");
			ch = malloc(sizeof(char));
			*ch = _getchar();
			if (!add_to_empty_list(&list, ch))
			{
				printf("Не добавлено!\n");
				free(ch);
			}
			else
				printf("Добавлено!\n");
		} else if (flag == '9') {
			char ch;

			printf("Введите что удалить:\n");
			ch = _getchar();
			if (!delete_element_from_list(&list, (void *)&ch, &ft_delchar, &cmp))
				printf("Не удалось удалить!\n");
			else
				printf("Удалено!\n");
		}
	}
}
