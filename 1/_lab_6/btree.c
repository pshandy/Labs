#include "btree.h"

t_btree	*btree_create_node(int key)
{
	t_btree	*btree;

	btree = NULL;
	btree = (t_btree*)malloc(sizeof(t_btree));
	if (btree)
	{
		btree->left = 0;
		btree->right = 0;
		btree->key = key;
		btree->occurs = 1;
	}
	return (btree);
}

void	btree_add_elem(t_btree **root, int key)
{
	if (*root == NULL)
		*root = btree_create_node(key);
	else
	{
		if ((*root)->key > key)
			btree_add_elem(&(*root)->left, key);
		else if ((*root)->key < key)
			btree_add_elem(&(*root)->right, key);
		else
			(*root)->occurs++;
	}
}

void	btree_add_elem_nonrec(t_btree **root, int key)
{
	t_btree *curr;
	t_btree *parent;

	if (*root == NULL)
		*root = btree_create_node(key);
	else
	{
		curr = *root;
		while (curr != NULL)
		{
			parent = curr;
			if (curr->key > key)
				curr = curr->left;
			else if (curr->key < key)
				curr = curr->right;
			else
			{
				curr->occurs++;
				curr = NULL;
			}
		}
		if (parent->key > key)
			parent->left = btree_create_node(key);
		else if (parent->key < key)
			parent->right = btree_create_node(key);
	}
}

void	btree_print(t_btree *root, int i)
{
	if (root)
	{
		if (root->right)
			btree_print(root->right, i + 1);

		for (int j = 0; j < i * 5; j++)
			printf(" ");
		printf("%d \n", root->key);

		if (root->left)
			btree_print(root->left, i + 1);
	}
}

void	btree_print_lined(t_btree *root)
{
	if (root)
	{
		if (root->left)
			btree_print_lined(root->left);

		printf("%d(%d) ", root->key, root->occurs);

		if (root->right)
			btree_print_lined(root->right);
	}
}


void	btree_search(t_btree *btree, int key)
{
	t_btree	*tmp;
	int		flag;

	flag = 1;
	tmp = btree;
	while (tmp && flag)
	{
		if (tmp->key > key)
			tmp = tmp->left;
		else if (tmp->key < key)
			tmp = tmp->right;
		else
			flag = 0;
	}
	if (tmp)
		printf("Вершина %d: %d повторений\n", tmp->key, tmp->occurs);
	else
		printf("Вершины нет\n");
}

void	changer(t_btree **p, t_btree **tmp)
{
	if ((*p)->right != NULL)
		changer(&(*p)->right, tmp);
	else
	{
		(*tmp)->key = (*p)->key;
		*tmp = *p;
		*p = (*p)->left;
	}
}

void	delete_node(t_btree **root, int key)
{
	t_btree	*tmp;

	if (*root)
	{
		if ((*root)->key > key)
			delete_node(&(*root)->left, key);
		else if ((*root)->key < key)
			delete_node(&(*root)->right, key);
		else
		{
			tmp = *root;
			if (!tmp->right)
				*root = tmp->left;
			else if (!tmp->left)
				*root = tmp->right;
			else
				changer(&(*root)->left, &tmp);
			free(tmp);
		}
	}
}

void	btree_clear(t_btree **root)
{
	if (*root)
 	{
 		if ((*root)->left)
 			btree_clear(&(*root)->left);
 		if ((*root)->right)
 			btree_clear(&(*root)->right);
		free(*root);
		(*root) = NULL;
	}
}

void	create_random_tree(t_btree **tree, int i)
{
	if (i <= 0)
		return ;
	while (i--)
		btree_add_elem(tree, rand() % 100);
}

// int main()
// {
// 	srand(time(NULL));
// 	printf("Started!\n");
//
// 	t_btree	*btree;
//
// 	btree = NULL;
// 	create_random_tree(&btree, 10);
// 	btree_add_elem(&btree, 10);
// 	btree_add_elem(&btree, 2);
// 	btree_add_elem(&btree, 3);
// 	btree_add_elem_nonrec(&btree, 3);
// 	btree_add_elem_nonrec(&btree, 4);
// 	btree_add_elem_nonrec(&btree, 3);
// 	// btree_clear();
// 	// btree_print_lined(btree);
// 	// btree_search(btree, 1);
// 	delete_node(&btree, 2);
// 	btree_print(btree, 0);
//
// 	printf("\nEnd.\n");
// }
