#include "btree.c"

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

	char flag = '1';

	printf("\
	0 - Выход.\n \
	1 - Создать дерево.\n \
	2 - Добавить в дерево.\n \
	3 - Найти элемент в дереве.\n \
	4 - Обратно-симметричный вывод.\n \
	5 - Вывод в порядке возрастания ключей.\n \
	6 - Удалить элемент.\n");

	printf("Введите номер операции:\n");

	while(1) {
		flag = _getchar();
		if (flag == '0') {
			printf("Выход.");
			btree_clear(&root);
			exit(0);
		} else if (flag == '1') {
			printf("Сколько элементов будет в дереве?\n");
			create_random_tree(&root, _getnumber());
			printf("Выполнено.\n");
		} else if (flag == '2') {
			printf("Какой элемент добавить?\n");
			btree_add_elem(&root, _getnumber());
			printf("Выполнено.\n");
		} else if (flag == '3') {
			printf("Какой элемент найти?\n");
			btree_search(root, _getnumber());
		} else if (flag == '4') {
			printf("------Обратно-симметричный обход------\n");
			btree_print(root, 0);
			printf("Выполнено.\n");
		} else if (flag == '5') {
			printf("Вывод в порядке возрастания ключей:\n");
			btree_print_lined(root);
			printf("Выполнено.\n");
		} else if (flag == '6') {
			printf("Какой элемент удалить?\n");
			delete_node(&root, _getnumber());
			printf("Выполнено.\n");
		}
	}
}
