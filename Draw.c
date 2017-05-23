#include "Head.h"

//打印Snake，遍历整条Snake,如果x,y同时满足，则打印
void Print_Snake(Snake_Pointer snake, int x, int y) {
	if (snake->head != NULL) {
		Snake_Node_Pointer sp = snake->head;
		while (sp->next) {
			if (sp->next->x == x&&sp->next->y == y) {
				printf(SNAKE_Body);
				return;
			}
			sp = sp->next;
		}
		printf("  ");
	}
	else {
		printf("  ");
	}
}

/*
short Print_Food(Snake_Pointer s, int x, int y) {
int *p = Get_Food_Position(s);
if (*p == x && *(p + 1) == y) {
printf(FOOD);
return TRUE;
}
return FALSE;
}
*/

void Draw(Snake_Pointer snake, Food_Pointer food) {
	int x = WIDE, y = HEIGHT;
	//printf("Food_Positon: x =%d %p, y =%d %p\n", *Food_Position, Food_Position, *(Food_Position + 1), (Food_Position + 1));
	//Sleep(5000);
	for (int i = 0; i < y + 2; i++) {
		if (i == 0 || i == y + 1) {
			for (int j = 0; j < x + 2; j++) {
				printf("═");
			}
			printf("\n");
		}
		else {
			printf("║");
			//打印内容:
			for (int j = 0; j < x; j++) {
				//printf("%d %d", j, i);
				if (food->x == j && food->y == i - 1) {
					printf(FOOD);
					//Sleep(5000);
				}
				else
					Print_Snake(snake, j, i - 1);
			}
			//:内容
			printf("║\n");
		}

	}
}