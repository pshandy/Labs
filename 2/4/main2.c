#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEYS 10
#define	ARRAY_SIZE 7

static char _getchar() {
	char	c;
	char	m;

	scanf("%c", &m);
	while ((c = getchar()) != EOF && c != '\n');
	return (m);
}

static char *getstring() {
	char	c;
	char	m[sizeof(char)*10];
	char	*str;


	scanf("%s", m);
	while ((c = getchar()) != EOF && c != '\n');
	str = strdup(m);
	return (str);
}

int contains(char *keys[], char *str) {
	for (int i = 0; i < KEYS; i++) {
		if (strcmp(keys[i], str) == 0)
			return (1);
	}
	return (0);
}

int get_hash(char *str) {
    int	code;
	int strLen;

	code = 0;
	strLen = strlen(str);
    for (int i = 0; i < strLen; i++)
        code += str[i];
    code = code % ARRAY_SIZE;
    return code;
}

void add(char **str, char **array) {
	int hashcode;
	int compares;

	hashcode = get_hash(*str);
	compares = 0;
	if (!array[hashcode]) {
		array[hashcode] = *str;
		printf("Ключ добавлен\n");
	}
	else if (strcmp(array[hashcode], *str) == 0) {
		printf("Элемент уже есть в списке\n");
		compares++;
	} else {
		int flag = 1;
		for (int i = 0; i < ARRAY_SIZE; i++) {
			int j = (hashcode + i) % ARRAY_SIZE;
			compares++;
			if (!array[j]) {
				array[j] = *str;

				flag = 0;
				printf("Элемент был переставлен!\n");
				break ;
			} else if (array[j] && strcmp(array[j], *str) == 0) {
				flag = 0;
				printf("Элемент уже был в таблице!\n");
				break ;
			}
		}
		if (flag)
			printf("В массиве нет места!\n");
	}
	printf("Количество сравнений: %d\n", compares);
}

void find(char **str, char **array) {
	int hashcode;
	int compares;

	compares = 0;
	hashcode = get_hash(*str);
	if (!array[hashcode])
		printf("Ключ не найден\n");
	else if (strcmp(array[hashcode], *str) == 0) {
		printf("Элемент есть в таблице, его позиция: %d\n", hashcode);
		compares++;
	} else {
		int flag = 1;
		for (int i = 0; i < ARRAY_SIZE; i++) {
			int j = (hashcode + i) % ARRAY_SIZE;
			printf("--->%d", j);
			compares++;
			if (array[j] && strcmp(array[j], *str) == 0) {
				flag = 0;
				printf("Элемент был найден на позиции %d\n", j);
				break ;
			}
		}
		if (flag)
			printf("Элемент не найден!\n");
	}
	printf("Количество сравнений: %d\n", compares);
}

int main()
{
	char	*keys[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven",
							"Eight", "Nine", "Ten"};
	char	flag = '1';
	char	**array = malloc(sizeof(char *) * ARRAY_SIZE);

	printf("\
	Введите команду:\n\
	0 - Выход из программы.\n\
	1 - Добавление элемента в таблицу.\n\
	2 - Поиск элемента.\n\
	3 - Вывод элементов.\n\
	4 - Заполнение таблицы.\
	");

	printf("Введите номер операции:\n");

	while(1) {
		flag = _getchar();
		if (flag == '0') {
			printf("-----------------------------------\n");
			printf("Выход.\n");
			for (int i = 0; i < ARRAY_SIZE; i++)
				if (array[i])
					free(array[i]);
			return (0);
		} else if (flag == '1') {
			char	*str;
			char	c;

			printf("-----------------------------------\n");
			printf("Введите ключ, который нужно добавить:\n");
			str = getstring();
		//	while (!contains(keys, str))
		//	str = getstring();
			add(&str, array);
		} else if (flag == '2') {
			char	*str;
			char	c;

			printf("-----------------------------------\n");
			printf("Введите ключ, который нужно найти:\n");
			str = getstring();
		//	while (!contains(keys, str))
		//	str = getstring();
			find(&str, array);
		} else if (flag == '3') {
			printf("-----------------------------------\n");
			for (int i = 0; i < ARRAY_SIZE; i++)
				printf("%d - %s\n", i, array[i]);
		} else if (flag == '4') {
			int smol[] = {11, 13, 14};

			for (int i = 0; i < 3; i++) {
				int	 size = smol[i];
				char **arr = malloc(sizeof(char *) * size);

				for (int j = 0; j < KEYS; j++) {
					char *s = strdup(keys[j]);
					add(&s, arr);
				}
				for (int j = 0; j < KEYS; j++) {
					char *s = strdup(keys[j]);
					find(&s, arr);
				}
				for (int k = 0; k < size; k++)
					printf("%d - %s\n", k, arr[k]);
				printf("-----------------------------------\n");
			}
		}
	}
}
