#include "Head.h"

Snake_Pointer Init_Snake(void);
void Add_Snake_Rear(Snake_Pointer snake, int x, int y);
void Add_Snake_Head(Snake_Pointer snake, int x, int y);
short Test_Food_Not_In_Snake(Snake_Pointer snake, Food_Pointer Food_Position);
void Draw(Snake_Pointer snake, Food_Pointer food);
char KbHit(char orient);
void Move_Snake(Snake_Pointer snake, char key);
Food_Pointer Init_Food(Snake_Pointer snake);

void gotoxy(int x, int y)//位置函数  
{
	COORD pos;

	pos.X = x;

	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
	Snake_Pointer snake = Init_Snake();
	Food_Pointer food = Init_Food(snake);
	printf("Food_Positon: x =%d , y =%d \n", food->x, food->y);
	//printf("Food_Positon: x =%d , y =%d \n", *Food_Position, *(Food_Position + 1));
	//Sleep(5000);
	Draw(snake, food);
	//Sleep(5000);
	

	//默认向右运动
	char key = 'd';
	while (1) {
		key = KbHit(key);
		//printf("%d\n", c);
		Move_Snake(snake, key);
		//system("cls");
		gotoxy(0, 0);
		//printf("%p\n", s);
		if (Test_Food_Not_In_Snake(snake, food)) {
			//不重叠时
			Draw(snake, food);
		}
		else {
			//重叠时，改变Snake，添加数据到snake表头，重新添加Food
			Add_Snake_Head(snake, food->x, food->y);
			food = Init_Food(snake);
			Draw(snake, food);
		}
		Sleep(150);
	}
	return 0;
}