#include<time.h>
#include<Windows.h>
#include"struct.h"
extern blocks block[maxn][maxn];
void CreatNewBlock() {
	int tmpx = 0;
	int tmpy = 0;
	//ȷ��λ��
	srand((unsigned)time(NULL));
	tmpx = rand() % maxn;
	tmpy = rand() % maxn;
	while (1) {
		if (block[tmpx][tmpy].value != 0) {
			rand() % 2 == 1 ? tmpx++: tmpy++;
			if (tmpx >= maxn)tmpx = 0;
			if (tmpy >= maxn)tmpy = 0;
		}
		if (block[tmpx][tmpy].value == 0)break;
	}
	//��ֵ
	int tmpvalue = rand() % 10;	//ʮ��֮һ�ĸ��ʳ���4
	if (tmpvalue == 9)
		block[tmpx][tmpy].value = 4;
	else
		block[tmpx][tmpy].value = 2;
}