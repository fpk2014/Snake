#include "Head.h"

short Test_Food_Not_In_Snake(Snake_Pointer snake, Food_Pointer food);
time_t time(time_t *timer);

Food_Pointer Init_Food(Snake_Pointer snake) {
	srand((unsigned int)time(NULL));
	Food_Pointer food = (Food_Pointer)malloc(sizeof(Food));
	do {
		food->x = rand() % (WIDE);
		food->y = rand() % (HEIGHT);
	} while (!Test_Food_Not_In_Snake(snake, food));
	return food;
}

//test,√ª”–”√
/*
int* Get_Food_Position(Snake_Pointer s) {
	
	//while (1) {
	//printf("%3d", rand() % (HEIGHT));
	//Sleep(1000);
	//}
	
	int x, y;
	do {
		x = rand() % (WIDE);
		y = rand() % (HEIGHT);
	} while (!Test_Food_Not_In_Snake(s, x, y));
	int *Food_Position = NULL;
	Food_Position = (int *)malloc(2 * sizeof(int));
	Food_Position[0] = x;
	Food_Position[1] = y;
	return Food_Position;
}
*/