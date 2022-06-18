#include "sort.h"

static char _getchar()
{
	char	c;
	char	m;

	scanf("%c", &m);
	while ((c = getchar()) != EOF && c != '\n');
	return (m);
}

static int _getnumber()
{
 	char	c;
 	char	m[sizeof(char)*10];

 	scanf("%s", m);
 	while ((c = getchar()) != EOF && c != '\n');
 	return (atoi(m));
}

int	main()
{
	srand(time(NULL));

	int		*array = NULL;
	int		size = 0;
	char	flag = '1';

	printf("\
	0 - Выход.\n \
	1 - Простейшая карманная сортировка без исп-я массива.\n \
	2 - Простейшая карманная сортировка с исп-ем массива.\n \
	3 - Обобщенная карманная сортировка.\n \
	4 - Поразрядная сортировка.\n \
	5 - Создать массив без повторяющихся ключей.\n \
	6 - Создать массив с повторяющимися ключами.\n");

	printf("Введите номер операции:\n");

	while(1) {
		flag = _getchar();
		if (flag == '0') {
			if (array != NULL)
				free(array);
			exit(0);
		} else if (flag == '1') {
			int	*copy;

			if (array == NULL || !is_unique(array, size))
			{
				printf("Массив пуст или содержит дупликаты.\n");
				continue ;
			}
			copy = copy_array(array, size);
			pocket_sort(copy, size);
			print_array(copy, size);
			free(copy);
		} else if (flag == '2') {
			int	*copy;

			if (array == NULL || !is_unique(array, size))
			{
				printf("Массив пуст или содержит дупликаты.\n");
				continue ;
			}
			copy = copy_array(array, size);
			array_pocket_sort(&copy, size);
			print_array(copy, size);
			free(copy);
		} else if (flag == '3') {
			int	*copy;

			if (array == NULL)
			{
				printf("Массив пуст.\n");
				continue ;
			}
			copy = copy_array(array, size);
			general_pocket_sort(&copy, size);
			print_array(copy, size);
			free(copy);
		} else if (flag == '4') {
			int	*copy;

			if (array == NULL)
			{
				printf("Массив пуст.\n");
				continue ;
			}
			copy = copy_array(array, size);
			radix_sort(&copy, size);
			print_array(copy, size);
			free(copy);
		} else if (flag == '5') {
			if (array != NULL)
				free(array);
			printf("Введите количество элементов массива без повторяющихся ключей:\n");
			size  = _getnumber();
			array = create_unique_array(size);
			print_array(array, size);
		} else if (flag == '6') {
			int max_key;

			if (array != NULL)
				free(array);
			printf("Введите количество элементов массива с повторяющимися ключами:\n");
			size  = _getnumber();
			printf("Введите значение максимального ключа:\n");
			max_key  = _getnumber();
			array = create_array(size, max_key);
			print_array(array, size);
		}
	}
}
