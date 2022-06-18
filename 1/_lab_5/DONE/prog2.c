#include "btree.c"
#include "dynamic_stack.c"

static char _getchar()
{
	char	c;
	char	m;

	scanf("%c", &m);
	while ((c = getchar()) != EOF && c != '\n');
	return (m);
}

static int _getnumber()
{
 	char	c;
 	char	m[sizeof(char)*10];

 	scanf("%s", m);
 	while ((c = getchar()) != EOF && c != '\n');
 	return (atoi(m));
}

int	main()
{
	srand(time(NULL));
	t_btree *root;
	root = NULL;

	printf("Введите количество элементов дерева:\n");
	btree_balanced(&root, _getnumber());

	char flag = '1';

	printf("\
	0 - Выход.\n \
	1 - Прямой обход.\n \
	2 - Симметричный обход.\n \
	3 - Обратно-симметричный обход.\n \
	4 - Удалить дерево.\n \
	5 - Создать дерево.\n \
	6 - Добавить правого потомка.\n \
	7 - Добавить левого потомка.\n \
	8 - Нерекурсивный симметричный обход.\n");

	printf("Введите номер операции:\n");

	while(1) {
		flag = _getchar();
		if (flag == '0') {
			printf("Выход.");
			btree_clear(&root);
			exit(0);
		} else if (flag == '1') {
			printf("------Прямой обход------\n");
			btree_apply_prefix(root, &print_data, 0);
			printf(">");
		} else if (flag == '2') {
			printf("------Симметричный обход------\n");
			btree_apply_infix(root, &print_data, 0);
			printf(">");
		} else if (flag == '3') {
			printf("------Обратно-симметричный обход------\n");
			btree_apply_infix_rev(root, &print_data, 0);
			printf(">");
		} else if (flag == '4') {
			printf("------Удаляю------\n");
			btree_clear(&root);
			printf(">");
		} else if (flag == '5') {
			printf("Введите количество элементов дерева:\n");
			btree_balanced(&root, _getnumber());
			printf("Создано.\n");
		} else if (flag == '6') {
			int	*i;
			int	j;

			printf("Введите, что добавить:\n");
			i = malloc(sizeof(char));
			*i = _getnumber();
			if (root == NULL) {
				root = btree_create_node((void *)i);
				printf("Добавлено.\n");
				continue ;
			}
			printf("Введите, кому добавить правого потомка:\n");
			j = _getnumber();
			if (!btree_add_elem_right(&root, (void *)&j, (void *)i, &ft_compare))
			{
				printf("Не добавлено!\n");
				free(i);
			}
			else
				printf("Добавлено!\n");
		} else if (flag == '7') {
			int	*i;
			int	j;

			printf("Введите, что добавить:\n");
			i = malloc(sizeof(char));
			*i = _getnumber();
			if (root == NULL) {
				root = btree_create_node((void *)i);
				printf("Добавлено.\n");
				continue ;
			}
			printf("Введите, кому добавить левого потомка:\n");
			j = _getnumber();
			if (!btree_add_elem_left(&root, (void *)&j, (void *)i, &ft_compare))
			{
				printf("Не добавлено!\n");
				free(i);
			}
			else
				printf("Добавлено!\n");
		} else if (flag == '8') {
			printf("------Нерекурсивный симметричный обход------\n");
			btree_apply_infix(root, &print_data, 0);
			printf(">");
		}
	}
}

// void n()
// {
// 	srand(time(NULL));
// 	t_btree *root;
// 	root = NULL;
//
// 	printf("Введите количество элементов дерева:\n");
// 	// btree_balanced(&root, _getnumber());
// 	btree_balanced(&root, 6);
// 	printf("------Симметричный обход------\n");
// 	btree_apply_infix(root, &print_data, 0);
// 	int *a = malloc(sizeof(int));
// 	int *b = malloc(sizeof(int));
// 	*a = 0;
// 	*b = 99;
// 	// btree_add_elem_right(&root, (void *)a, (void *)b, &ft_compare);
// 	//
// 	btree_clear(&(root->left));
// 	printf("------Симметричный обход------\n");
// 	btree_apply_prefix(root, &print_data, 0);
//
// 	printf("------Симметричный обход------\n");
// 	btree_apply_prefix(root, &print_data, 0);
// 	printf("\nEnd.");
// 	free(a);
// 	free(b);
// }
