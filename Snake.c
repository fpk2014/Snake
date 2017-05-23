#include "Head.h"

//添加Snake表头
void Add_Snake_Head(Snake_Pointer snake, int x, int y) {
	Snake_Node_Pointer tmp = (Snake_Node_Pointer)malloc(sizeof(Snake_Node));
	tmp->x = x;
	tmp->y = y;

	Snake_Node_Pointer sp = snake->head->next;
	tmp->next = sp;
	snake->head->next = tmp;
}

//添加Snake表尾
void Add_Snake_Rear(Snake_Pointer snake, int x, int y) {
	Snake_Node_Pointer tmp = (Snake_Node_Pointer)malloc(sizeof(Snake_Node));
	tmp->x = x;
	tmp->y = y;
	tmp->next = NULL;

	snake->end->next = tmp;
	//队尾是缓存
	snake->end = tmp;
}

//删除snake表尾
void Del_Snake_End(Snake_Pointer snake) {
	Snake_Node_Pointer tmp = (Snake_Node_Pointer)malloc(sizeof(Snake_Node));
	Snake_Node_Pointer need = (Snake_Node_Pointer)malloc(sizeof(Snake_Node));
	tmp = snake->head;
	while (tmp->next != NULL) {
		need = tmp;
		tmp = tmp->next;
	}
	need->next = NULL;
	snake->end = need;
}

//打印Snake的所有点的坐标
void Test_Snake(Snake_Pointer snake) {
	Snake_Node_Pointer sp = snake->head;
	while (sp->next != NULL) {
		printf("x = %d, y = %d\n", sp->next->x, sp->next->y);
		sp = sp->next;
	}
}

//生成的food坐标与snake重叠将返回FALSE
short Test_Food_Not_In_Snake(Snake_Pointer snake, Food_Pointer food) {
	Snake_Node_Pointer sp = snake->head;
	while (sp->next != NULL) {
		if (sp->next->x==food->x &&  sp->next->y==food->y) {
			return FALSE;
		}
		sp = sp->next;
	}
	return TRUE;
}

Snake_Pointer Init_Snake() {
	//所有指针都需要初始化
	Snake_Pointer snake = (Snake_Pointer)malloc(sizeof(Snake));
	Snake_Node_Pointer sp = (Snake_Node_Pointer)malloc(sizeof(Snake_Node));
	snake->head = snake->end = sp;
	Add_Snake_Rear(snake, 1, 1);
	Add_Snake_Rear(snake, 1, 2);
	return snake;
}