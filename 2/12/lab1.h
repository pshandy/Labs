#ifndef LAB1_H
#define LAB1_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int		*copy_array(int arr[], int size);
int		*create_array(int n);
void	print_array(int *arr, int size);
void	swap(int *a, int *b);
void	bubble_sort(int *arr, int size);
void	selection_sort(int *arr, int size);
void	insertion_sort(int *arr, int size);
void	shell_sort(int *arr, int size);
void	quick_sort(int *array, int size, int first, int last);
void	sito(int *array, int left, int right, int *changes, int *compares);
void	pyramidal_sort(int *arr, int size);

#endif
