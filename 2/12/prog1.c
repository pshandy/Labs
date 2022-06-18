#include "lab1.c"

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
	1 - Сортировка пузырьком.\n \
	2 - Сортировка вставками.\n \
	3 - Сортировка выбором.\n \
	4 - Создать | обновить массив.\n \
	5 - Анализ эффективности.\n \
	----------------------------------\n\
	6 - Сортировка методом Шелла.\n \
	7 - Быстрая сортировка.\n \
	8 - Пирамидальная сортировка.\n \
	9 - Анализ эффективности.\n \
	k - Общий анализ.\n");

	printf("Введите номер операции:\n");

	while(1) {
		flag = _getchar();
		if (flag == '0') {
			if (array != NULL)
				free(array);
			exit(0);
		} else if (flag == '1') {
			int	*copy;

			if (array == NULL)
			{
				printf("Массив пуст.\n");
				continue ;
			}
			copy = copy_array(array, size);
			bubble_sort(copy, size);
			print_array(copy, size);
			free(copy);
		} else if (flag == '2') {
			int	*copy;

			if (array == NULL)
			{
				printf("Массив пуст.\n");
				continue ;
			}
			copy = copy_array(array, size);
			insertion_sort(copy, size);
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
			selection_sort(copy, size);
			print_array(copy, size);
			free(copy);
		} else if (flag == '4') {
			if (array != NULL)
				free(array);
			printf("Введите количество элементов массива:\n");
			size  = _getnumber();
			array = create_array(size);
			print_array(array, size);
		} else if (flag == '5') {
			for (int i = 1; i <= 10000; i = i * 10)
			{
				if (array != NULL)
					free(array);
				printf("Пересоздаю / cоздаю массив на %d элементов\n", i);
				array	  = create_array(i);
				// print_array(array, i);
				int	*arr1 = copy_array(array, i);
				int	*arr2 = copy_array(array, i);
				int	*arr3 = copy_array(array, i);
				bubble_sort(arr1, i);
				selection_sort(arr2, i);
				insertion_sort(arr3, i);
				free(arr1);
				free(arr2);
				free(arr3);
				printf("----------------------------------------------\n");
			}
		} else if (flag == '6') {
			int	*copy;

			if (array == NULL)
			{
				printf("Массив пуст.\n");
				continue ;
			}
			copy = copy_array(array, size);
			shell_sort(copy, size);
			print_array(copy, size);
			free(copy);
		} else if (flag == '7') {
			int	*copy;

			if (array == NULL)
			{
				printf("Массив пуст.\n");
				continue ;
			}
			copy = copy_array(array, size);
			quick_sort(copy, size, 0, size - 1);
			print_array(copy, size);
			free(copy);
		} else if (flag == '8') {
			int	*copy;

			if (array == NULL)
			{
				printf("Массив пуст.\n");
				continue ;
			}
			copy = copy_array(array, size);
			pyramidal_sort(copy, size);
			print_array(copy, size);
			free(copy);
		} else if (flag == '9') {
			for (int i = 2; i <= 10000; i = i * 10)
			{
				if (array != NULL)
					free(array);
				printf("Пересоздаю / cоздаю массив на %d элементов\n", i);
				array	  = create_array(i);
				// print_array(array, i);
				int	*arr1 = copy_array(array, i);
				int	*arr2 = copy_array(array, i);
				int	*arr3 = copy_array(array, i);
				shell_sort(arr1, i);
				quick_sort(arr2, i, 0, i - 1);
				pyramidal_sort(arr3, i);
				free(arr1);
				free(arr2);
				free(arr3);
				printf("----------------------------------------------\n");
			}
		} else if (flag == 'k') {
			for (int i = 1; i <= 10000; i = i * 10)
			{
				if (array != NULL)
					free(array);
				printf("Пересоздаю / cоздаю массив на %d элементов\n", i);
				array	  = create_array(i);
				// print_array(array, i);
				int	*arr1 = copy_array(array, i);
				int	*arr2 = copy_array(array, i);
				int	*arr3 = copy_array(array, i);
				int	*arr4 = copy_array(array, i);
				int	*arr5 = copy_array(array, i);
				int	*arr6 = copy_array(array, i);
				bubble_sort(arr1, i);
				selection_sort(arr2, i);
				insertion_sort(arr3, i);
				shell_sort(arr4, i);
				quick_sort(arr5, i, 0, i - 1);
				pyramidal_sort(arr6, i);
				free(arr1);
				free(arr2);
				free(arr3);
				free(arr4);
				free(arr5);
				free(arr6);
				printf("----------------------------------------------\n");
			}
		}
	}
}
