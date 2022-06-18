#include "btree.c"

/*
 * _getnumber()
 * Считывает с консоли число и возвращает его.
 * Не обрабатывает неверный ввод.
 */

static int _getnumber()
{
 	char	c;
 	char	m[sizeof(char)*10];

 	scanf("%s", m);
 	while ((c = getchar()) != EOF && c != '\n');
 	return (atoi(m));
}

int main()
{
	srand(time(NULL));
	t_btree *root;
	root = NULL;

	printf("Введите количество элементов дерева:\n");
	btree_balanced(&root, _getnumber());
	printf("------Прямой обход------\n");
	btree_apply_prefix(root, &print_data, 0);
	printf("------Симметричный обход------\n");
	btree_apply_infix(root, &print_data, 0);
	printf("------Обратно-симметричный обход------\n");
	btree_apply_infix_rev(root, &print_data, 0);
}
