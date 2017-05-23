#include "Head.h"

//���Snake��ͷ
void Add_Snake_Head(Snake_Pointer snake, int x, int y) {
	Snake_Node_Pointer tmp = (Snake_Node_Pointer)malloc(sizeof(Snake_Node));
	tmp->x = x;
	tmp->y = y;

	Snake_Node_Pointer sp = snake->head->next;
	tmp->next = sp;
	snake->head->next = tmp;
}

//���Snake��β
void Add_Snake_Rear(Snake_Pointer snake, int x, int y) {
	Snake_Node_Pointer tmp = (Snake_Node_Pointer)malloc(sizeof(Snake_Node));
	tmp->x = x;
	tmp->y = y;
	tmp->next = NULL;

	snake->end->next = tmp;
	//��β�ǻ���
	snake->end = tmp;
}

//ɾ��snake��β
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

//��ӡSnake�����е������
void Test_Snake(Snake_Pointer snake) {
	Snake_Node_Pointer sp = snake->head;
	while (sp->next != NULL) {
		printf("x = %d, y = %d\n", sp->next->x, sp->next->y);
		sp = sp->next;
	}
}

//���ɵ�food������snake�ص�������FALSE
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
	//����ָ�붼��Ҫ��ʼ��
	Snake_Pointer snake = (Snake_Pointer)malloc(sizeof(Snake));
	Snake_Node_Pointer sp = (Snake_Node_Pointer)malloc(sizeof(Snake_Node));
	snake->head = snake->end = sp;
	Add_Snake_Rear(snake, 1, 1);
	Add_Snake_Rear(snake, 1, 2);
	return snake;
}