#include "dynamic_queue.c"
#include "dynamic_queue.h"

//-----------------------Программа---------------------------

int flag = 1;

void handler() {
	flag = 0;
	printf("\nПрекращение.");
	clear_queue();
}

int main()
{
	signal(SIGINT, handler);
	printf("Выбрано задание 7:\n");
	srand(time(NULL));
	printf("Генератор псевдослучайных чисел подключён.\n");

	while(flag == 1) {
		int r = rand() % 3 + 1;
		// int r = 3;
		// int k = rand() % 5 + 1;
		if (rand() % 2 == 1) {
			printf("Добавление %d эл-в: ", r);
			for (int i = 0; i < r; i++)
				add('A' + rand() % 26);
			// for (int i = 0; i < k; i++)
				// add('A' + rand() % 26);
		} else {
			printf("Удаление %d эл-в  : ", r);
			for (int i = 0; i < r; i++)
				del();
		}
		print();
		sleep(1);
	}
}
