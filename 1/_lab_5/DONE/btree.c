#include "btree.h"
#include "dynamic_stack.h"

int 	*get_random()
{
	int *num;

	num = malloc(sizeof(int));
	if (num == NULL)
		exit(-1);
	*num = rand() % 100;
	return (num);
}

/*
 * Создание поддерева
 */

t_btree	*btree_create_node(void *item)
{
	t_btree	*btree;

	btree = NULL;
	btree = (t_btree*)malloc(sizeof(t_btree));
	if (btree)
	{
		btree->left = 0;
		btree->right = 0;
		btree->item = item;
	}
	return (btree);
}

/*
 * Прямой обход
 */

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *, int), int i)
{
	if (root)
	{
		(*applyf)(root->item, i);
		if (root->left)
			btree_apply_prefix(root->left, applyf, i + 1);
		if (root->right)
			btree_apply_prefix(root->right, applyf, i + 1);
	}
}

/*
 * Симметричный обход / Центрированный обход
 */

void	btree_apply_infix(t_btree *root, void (*applyf)(void *, int), int i)
{
	if (root)
	{
		if (root->left)
			btree_apply_infix(root->left, applyf, i + 1);
		(*applyf)(root->item, i);
		if (root->right)
			btree_apply_infix(root->right, applyf, i + 1);
	}
}

/*
 * Нерекурсивный симметричный обход / Центрированный обход
 */

void	btree_apply_infix_nonrec(t_btree *root, void (*applyf)(void *, int), int i)
{
	t_stack *stack;
	t_btree	*tmp;
	int		flag;

	stack = NULL;
	tmp = root;
	flag = 1;
	while (flag)
	{
		while (tmp != NULL)
		{
			push(&stack, (void *)tmp);
			tmp = tmp->left;
		}
		if (is_empty(stack))
			flag = 0;
		else
		{
			tmp = (t_btree *)get(&stack);
			(*applyf)(tmp->item, i);
			tmp = tmp->right;
		}
	}
}

/*
 * Обратно-симметричный обход
 */

void	btree_apply_infix_rev(t_btree *root, void (*applyf)(void *, int), int i)
{
	if (root)
	{
		if (root->right)
			btree_apply_infix_rev(root->right, applyf, i + 1);
		(*applyf)(root->item, i);
		if (root->left)
			btree_apply_infix_rev(root->left, applyf, i + 1);
	}
}

/*
 * Обратный обход
 */

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *, int), int i)
{
	if (root)
	{
		if (root->left)
			btree_apply_suffix(root->left, applyf, i + 1);
		if (root->right)
			btree_apply_suffix(root->right, applyf, i + 1);
		(*applyf)(root->item, i);
	}
}

/*
 * Создание идеально сбалансированного двоичного дерева.
 */

void	btree_balanced(t_btree **root, int N)
{
	t_btree	*tmp;
	int		N_left;
	int		N_right;

	if (N == 0)
		*root = NULL;
	else
	{
		N_left = N / 2;
		N_right = N - N_left - 1;
		tmp = btree_create_node((void *)get_random());
		btree_balanced(&(tmp->left), N_left);
		btree_balanced(&(tmp->right), N_right);
		*root = tmp;
	}
}

/*
 * Поиск элемента
 */


t_btree *btree_search_item(t_btree *root, void *data_ref,
 							int (*cmp)(void *, void *))
{
 	t_btree	*result;

 	result = NULL;
 	if (root->left)
 		result = btree_search_item(root->left, data_ref, cmp);
 	if (!result && cmp(root->item, data_ref))
		return (root);
 	if (!result && root->right)
 		result = btree_search_item(root->right, data_ref, cmp);
 	return (result);
}

/*
 * Добавить элемент в правую часть ноды
 */

int		btree_add_elem_right(t_btree **elem, void *data_ref, void *data, int (*cmp)(void *, void *))
{
	t_btree	*tmp;

	tmp = btree_search_item(*elem, data_ref, cmp);
	if (tmp == NULL || tmp->right != NULL)
		return (0);
	tmp->right = btree_create_node(data);
	return (1);
}

/*
 * Добавить элемент в левую часть ноды
 */

int		btree_add_elem_left(t_btree **elem, void *data_ref, void *data, int (*cmp)(void *, void *))
{
	t_btree	*tmp;

	tmp = btree_search_item(*elem, data_ref, cmp);
	if (tmp == NULL || tmp->left != NULL)
		return (0);
	tmp->left = btree_create_node(data);
	return (1);
}

/*
 * Функция вывода информационной части на экран.
 */

void	print_data(void *data, int i)
{
	for (int j = 0; j < i * 5; j++)
		printf(" ");
	printf("%d ", *(int *)data);
	printf("\n");
}

/*
 * Функция сравнения информационных частей
 */

int		ft_compare(void *a, void *b)
{
	if (*(int *)a == *(int *)b)
		return (1);
	return (0);
}

/*
 * Очистка дерева
 */

void	btree_clear(t_btree **root)
{
	if (*root)
 	{
 		if ((*root)->left)
 			btree_clear(&(*root)->left);
 		if ((*root)->right)
 			btree_clear(&(*root)->right);
		free((*root)->item);
		free(*root);
		(*root) = NULL;
	}
}
