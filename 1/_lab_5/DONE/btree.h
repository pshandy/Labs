#ifndef __FT_BTREE_H__
# define __FT_BTREE_H__

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

typedef struct	s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}				t_btree;

int 	*get_random();
int		ft_compare(void *a, void *b);
int		btree_add_elem_right(t_btree **elem, void *data_ref, void *data, int (*cmp)(void *, void *));
int		btree_add_elem_left(t_btree **elem, void *data_ref, void *data, int (*cmp)(void *, void *));
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *, int), int i);
void	btree_apply_infix(t_btree *root, void (*applyf)(void *, int), int i);
void	btree_apply_infix_rev(t_btree *root, void (*applyf)(void *, int), int i);
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *, int), int i);
void	btree_balanced(t_btree **root, int N);
void	print_data(void *data, int i);
void	btree_clear(t_btree **root);
t_btree *btree_search_item(t_btree *root, void *data_ref, int (*cmp)(void *, void *));
t_btree	*btree_create_node(void *item);

#endif
