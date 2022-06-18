#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 1000
#define MAX_KEY 99

typedef struct	s_list
{
	int 	data;
	struct 	s_list *prev;
	struct 	s_list *next;
}				t_list;

//UTILS
void	swap(int *a, int *b);
void	print_array(int *arr, int size);
int		*create_unique_array(int max_key);
int		*create_unique_array(int max_key);
int		*create_array(int n, int max_key);
int		*copy_array(int arr[], int size);
int		getMax(int arr[], int size);
int 	is_unique(int arr[], int size);

//DOUBLY_LIST
void	ft_init(t_list **list);
void	ft_lstadd_back(t_list **list, int data);
void	ft_lstclear(t_list **lst);

//SORT
void	pocket_sort(int *arr, int size);
void	array_pocket_sort(int **arr, int size);
void	general_pocket_sort(int **arr, int size);
void	radix_sort(int **arr, int size);

#endif
