#include "sort.h"

void	pocket_sort(int *arr, int size)
{
	int temp;

	for (int i = 0; i < size; i++)
	{
		while (arr[i] != i)
		{
			temp = arr[arr[i]];
			arr[arr[i]] = arr[i];
			arr[i] = temp;
		}
	}
}

void	array_pocket_sort(int **arr, int size)
{
	int *arr_b;

	arr_b = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		arr_b[(*arr)[i]] = (*arr)[i];
	free(*arr);
	*arr = arr_b;
}

void	general_pocket_sort(int **arr, int size)
{
	t_list **arr_b;

	arr_b = malloc(sizeof(t_list *) * size);
	for (int i = 0; i < size; i++)
		ft_init(&arr_b[i]);

	//Сортировка
	for (int i = 0; i < size; i++)
		ft_lstadd_back(&arr_b[(*arr)[i]], (*arr)[i]);

	//Заполнение исходного массива
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		t_list *tmp;

		tmp = (arr_b[i]->next);
		while (tmp != arr_b[i])
		{
			(*arr)[j] = (tmp->data);
			tmp = tmp->next;
			j++;
		}
	}

	// Очистка массива списков
	for (int i = 0; i < size; i++)
		ft_lstclear(&arr_b[i]);
	free(arr_b);
}

void	radix_sort(int **arr, int size)
{
	int max_key = getMax(*arr, size);
	int temp = max_key;
	int k = 0;

	while (temp != 0)
	{
		temp = temp / 10;
		k++;
	}

	for (int j = 0; j < k; j++)
	{
		t_list **arr_b;

		arr_b = malloc(sizeof(t_list *) * size);
		for (int i = 0; i < size; i++)
			ft_init(&arr_b[i]);

		//Сортировка
		for (int i = 0; i < size; i++)
		{
			int temp = (*arr)[i];
			for (int m = 0; m < j; m++)
                temp = temp / 10;
            temp = temp % 10;
			ft_lstadd_back(&arr_b[temp], (*arr)[i]);
		}

		//Заполнение исходного массива
		int g = 0;
		for (int i = 0; i < size; i++)
		{
			t_list *tmp;

			tmp = (arr_b[i]->next);
			while (tmp != arr_b[i])
			{
				(*arr)[g] = (tmp->data);
				tmp = tmp->next;
				g++;
			}
		}

		// Очистка массива списков
		for (int i = 0; i < size; i++)
			ft_lstclear(&arr_b[i]);
		free(arr_b);
	}
}
