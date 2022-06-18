#include "lab1.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*create_array(int n)
{
	int	*array;

	array = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		array[i] = rand() % 1000;
	return (array);
}

int	*copy_array(int arr[], int size)
{
	int	*sorted_array;

	sorted_array = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		sorted_array[i] = arr[i];
	return (sorted_array);
}

void	print_array(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void	bubble_sort(int *arr, int size)
{
	int	changes;
	int	compares;

	changes = 0;
	compares = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			compares++;
			if (arr[j] > arr[j + 1])
			{
				changes++;
				swap(&arr[j + 1], &arr[j]);
			}
		}
	}
	printf("Сортировка пузырьком: %d сравнений, %d перестановок.\n", compares, changes);
}

void	selection_sort(int *arr, int size)
{
	int	min_index;
	int	changes;
	int	compares;

	changes = 0;
	compares = 0;
	for (int i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < size; j++)
		{
			compares++;
			if (arr[j] < arr[min_index])
				min_index = j;
		}
		if (min_index != i) {
			changes++;
			swap(&arr[i], &arr[min_index]);
		}
	}
	printf("Сортировка методом выбора: %d сравнений, %d перестановок.\n", compares, changes);
}

void	insertion_sort(int *arr, int size)
{
	int	j;
	int	temp;
	int	changes;
	int	compares;

	changes = 0;
	compares = 0;
	for (int i = 1; i < size; i++) {
		temp = arr[i];
		j = i - 1;

		compares++;
		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			if (j != i - 1)
				changes++;
			j--;
			compares++;
		}
		if (arr[j + 1] == temp)
            changes--;
		arr[j + 1] = temp;
		changes++;
	}
	printf("Сортировка вставками: %d сравнений, %d перестановок.\n", compares, changes);
}

void	shell_sort(int *arr, int size)
{
	int	t, k, j;
	int	temp;
	int	changes;
	int	compares;
	int h[] = { 1, 3, 5, 9, 17, 33, 65, 129, 257, 513, 1025, 2049, 4097, 8194 };

	changes = 0;
	compares = 0;
	t = (log(size)/log(2) - 1);
	for (int m = t - 1; m > -1; m--)
	{
		k = h[m];
		for (int i = k; i < size; i++) {
			temp = arr[i];
			j = i - k;

			compares++;
			while (j >= 0 && arr[j] > temp)
			{
				arr[j + k] = arr[j];
				if (j != i - k)
					changes++;
				j = j - k;
				compares++;
			}
			if (arr[j + k] == temp)
				changes--;
			arr[j + k] = temp;
			changes++;
		}
	}
	printf("Сортировка методом Шелла: %d сравнений, %d перестановок.\n", compares, changes);
}

void	quick_sort(int *array, int size, int first, int last)
{
	int			i, j, pivot, temp;
	static int	compares = 0;
	static int	changes = 0;

	i = first;
	j = last;
	pivot = array[(first + last) / 2];
	do
	{
		compares++;
		while (array[i] < pivot)
		{
			i++;
			compares++;
		}
		compares++;
		while (array[j] > pivot)
		{
			j--;
			compares++;
		}
		compares++;
		if (i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++; j--;
			changes++;
		}
		compares++;
	} while (i < j);
	compares++;
	if (first < j)
		quick_sort(array, size, first , j);
	compares++;
	if (i < last)
		quick_sort(array, size, i , last);

	if (first == 0 && last == (size - 1))
	{
		printf("Быстрая сортировка: %d сравнений, %d перестановок.\n", compares, changes);
		changes = 0;
		compares = 0;
	}
}

void	sito(int *array, int left, int right, int *changes, int *compares)
{
	int	i;
	int	j;
	int	x;

	i = left;
	j = 2 * left;
	x = array[left];
	(*compares)++;
	if (j < right && array[j + 1] < array[j])
		j = j + 1;
	(*compares)++;
	while (j <= right && array[j] < x)
	{
		array[i] = array[j];
		i = j;
		j = 2 * j;
		(*compares)++;
		if (j < right && array[j + 1] < array[j])
			j++;
		(*compares)++;
	}
	array[i] = x;
	(*changes)++;
}

void	pyramidal_sort(int *arr, int size)
{
	int	left;
	int	right;
	int	temp;
	int	changes = 0;
	int	compares = 0;

	left = size / 2;
	right = size - 1;
	while (left > 0)
	{
		left--;
		sito(arr, left, right, &changes, &compares);
		compares++;
	}
	compares++;
	while (right > 0)
	{
		changes++;
		temp = arr[0];
		arr[0] = arr[right];
		arr[right] = temp;
		right--;
		sito(arr, left, right, &changes, &compares);
		compares++;
	}
	printf("Пирамидальная сортировка: %d сравнений, %d перестановок.\n", compares, changes);
}
