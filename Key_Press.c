#include "Head.h"

int _kbhit(void);
int _getch(void);

//�ж��ǲ��ǰ��µļ����˶������Ƿ����
//������ȷ��keyֵ
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