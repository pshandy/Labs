#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

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
	for (int i = 0; i < SIZE; i++) {
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
    code = code % SIZE;
    return code;
}

int main()
{
	char	*keys[] = {"START", "STOP", "END", "RETURN", "GET", "STRING", "IF", "ELSE", "THIS", "PRIVATE"};
	char	flag = '1';
	char	*array[SIZE] = {};

	printf("\
	Введите команду:\n\
	0 - Выход из программы.\n\
	1 - Добавление элемента в таблицу.\n\
	2 - Поиск элемента.\n\
	3 - Вывод элементов.\n\
	4 - Удаление элемента.\n\
	5 - Заполнение таблицы.\
	");

	printf("Введите номер операции:\n");

	while(1) {
		flag = _getchar();
		if (flag == '0') {
			printf("-----------------------------------\n");
			printf("Выход.\n");
			for (int i = 0; i < SIZE; i++)
				if (array[i])
					free(array[i]);
			return (0);
		}
		else if (flag == '1') {
			char	*str;
			char	c;
			int		hashcode;

			printf("-----------------------------------\n");
			printf("Введите ключ, который нужно добавить:\n\
			START, STOP, END, RETURN, GET,\n\
			STRING, IF, ELSE, THIS, PRIVATE\n");
			str = getstring();
			while (!contains(keys, str))
				str = getstring();

			hashcode = get_hash(str);
			if (!array[hashcode] || strcmp(array[hashcode], str) != 0) {
				array[hashcode] = str;
				printf("Ключ добавлен\n");
			}
			else
				printf("Элемент уже есть в списке");
		}
		else if (flag == '2') {
			char	*str;
			char	c;
			int		hashcode;

			printf("-----------------------------------\n");
			printf("Введите ключ, который нужно найти:\n\
			START, STOP, END, RETURN, GET,\n\
			STRING, IF, ELSE, THIS, PRIVATE\n");
			str = getstring();
			while (!contains(keys, str))
				str = getstring();

			hashcode = get_hash(str);
			if (array[hashcode] && strcmp(array[hashcode], str) == 0)
				printf("Ключ есть в массиве.\n");
			else
				printf("Ключа нету в массиве.\n");
		}
		else if (flag == '3') {
			for (int i = 0; i < SIZE; i++)
				printf("%d - %s\n", i, array[i]);
		}
		else if (flag == '4') {
			char	*str;
			char	c;
			int		hashcode;

			printf("-----------------------------------\n");
			printf("Введите ключ, который нужно удалить:\n\
			START, STOP, END, RETURN, GET,\n\
			STRING, IF, ELSE, THIS, PRIVATE\n");
			str = getstring();
			while (!contains(keys, str))
				str = getstring();

			hashcode = get_hash(str);
			if (array[hashcode] && strcmp(array[hashcode], str) == 0) {
				array[hashcode] = NULL;
				free(array[hashcode]);
				printf("Ключ удалён\n");
			}
			else
				printf("Элемента нету в списке!\n");
		}
		else if (flag == '5') {
			int hashcode;

			printf("-----------------------------------\n");
			printf("Автоматическое заполнение массива.\n");
			for (int i = 0; i < SIZE; i++) {
				hashcode = get_hash(keys[i]);
				array[hashcode] = strdup(keys[i]);
			}
			printf("Массив заполнен.\n");
		}
	}
}
