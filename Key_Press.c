#include "Head.h"

int _kbhit(void);
int _getch(void);

//判断是不是按下的键和运动方向是否合理
//返回正确的key值
char KbHit(char orient) {
	char key;

	if (_kbhit()) {
		key = _getch();
		if (orient != 'd' && key == 'a') {
			orient = key;
		}
		else if (orient != 'a' && key == 'd') {
			orient = key;
		}
		else if (orient != 'w' && key == 's') {
			orient = key;
		}
		else if (orient != 's' && key == 'w') {
			orient = key;
		}
		else if (27 == key) {
			orient = key;
		}
	}

	return orient;
}