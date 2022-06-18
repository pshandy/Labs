#include "sort.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*create_unique_array(int max_key)
{
	int	*array;

	array = malloc(sizeof(int) * max_key);
	for (int i = 0; i < max_key; i++)
		array[i] = i;
	if (max_key > 1)
    {
        size_t i;
        for (i = 0; i < max_key - 1; i++)
        {
          size_t j = i + rand() / (RAND_MAX / (max_key - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
	return (array);
}

int	*create_array(int n, int max_key)
{
	int	*array;

	array = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		array[i] = i % (max_key + 1);
	if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
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

int getMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int is_unique(int arr[], int size)
{
	for(int i = 0; i < size; i++)
		for(int j = i + 1; j < size; j++)
			if(arr[i] == arr[j])
				return (0);
	return (1);
}
