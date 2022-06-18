#ifndef _FT_BTREE_H
# define _FT_BTREE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

typedef struct	s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	int				key;
	int				occurs;
}				t_btree;

t_btree	*btree_create_node(int key);
void	btree_add_elem(t_btree **root, int key);
void	btree_add_elem_nonrec(t_btree **root, int key);
void	btree_print(t_btree *root, int i);
void	btree_print_lined(t_btree *root);
void	btree_search(t_btree *btree, int key);
void	changer(t_btree **p, t_btree **tmp);
void	delete_node(t_btree **root, int key);
void	btree_clear(t_btree **root);
void	create_random_tree(t_btree **tree, int i);

#endif
