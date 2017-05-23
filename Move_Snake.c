#include "Head.h"

void Del_Snake_End(Snake_Pointer snake);
void Add_Snake_Head(Snake_Pointer snake, int x, int y);

//核心步骤：改变Snake表
void _Move(Snake_Pointer snake, int a, int b) {
	//a和b是前进点的x,y坐标
	//Test_Snake(s);
	//Sleep(2000);
	Del_Snake_End(snake); //删除队尾
	Add_Snake_Head(snake, a, b); //添加snake表头
}


//判断超界:
//分析前进点的坐标
//如果超界面，修改得到正确的坐标
void Move(Snake_Pointer snake, int a, int b) {
	
	Snake_Node_Pointer sp = snake->head;
	int wide = sp->next->x + a;
	int height = sp->next->y + b;
	//printf("%d %d\n", a, b);
	//Sleep(2000);

	if (wide<0) {
		_Move(snake, WIDE, height);
	}
	else if (wide>WIDE - 1) {
		_Move(snake, 0, height);
	}
	else if (height < 0) {
		_Move(snake, wide, HEIGHT);
	}
	else if (height > HEIGHT - 1) {
		_Move(snake, wide, 0);
	}
	else {
		_Move(snake, wide, height);
	}
}

//判断方向，确定snake_head坐标的增减
//  w
//a s d
//a: (-1, 0)
//w: (0. -1)
//s: (0, 1)
//d: (1, 0)
void Move_Snake(Snake_Pointer snake, char key) {
	if (key == 'a') {
		puts("a");
		Move(snake, -1, 0);
	}
	else if (key == 'w') {
		puts("w");
		Move(snake, 0, -1);
	}
	else if (key == 's') {
		puts("s");
		Move(snake, 0, 1);
	}
	else if (key == 'd') {
		puts("d");
		Move(snake, 1, 0);
	}
}