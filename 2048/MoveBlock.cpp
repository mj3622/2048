#include"struct.h"
#include<Windows.h>
#include<conio.h>
void CreatNewBlock();
extern blocks block[maxn][maxn];
void MoveBlock() {
	if (_kbhit())
	{
		bool ismove = false;
		switch (_getch())
		{
		//���������ƶ�
		case 'W':
		case 'w':
		case 72:
			for (int i = 0; i < maxn; i++) {			//�ӵ�һ�п�ʼ
				for (int j = 1; j < maxn; j++) {		//�ӵڶ��п�ʼ�ƶ�
					//�жϸ�λ���Ƿ���ڷ���
					if (block[j][i].value != 0) {
						//�ҵ�����ķ����λ��
						bool isfind = false;
						for (int k = j - 1; k >= 0; k--) {
							if (block[k][i].value != 0) {
								//�ҵ��˶��ϵķ���
								isfind = true;
								//����������Ժϲ�ʱ
								if (block[j][i].value == block[k][i].value) {
									block[k][i].value *= 2;
									block[j][i].value = 0;
									ismove = true;
								}
								//�������鲻�ܹ��ϲ�ʱ
								else if (k + 1 != j) {
									block[k + 1][i].value = block[j][i].value;
									block[j][i].value = 0;
									ismove = true;
								}
								break;
							}
						}
						//����û�з���ʱ
						if (!isfind) {
							block[0][i].value = block[j][i].value;
							block[j][i].value = 0;
							ismove = true;
						}
					}
				}
			}
			break;
		//���������ƶ�
		case 'S':
		case 's':
		case 80:
			for (int i = 0; i < maxn; i++) {
				for (int j = maxn - 2; j >= 0; j--) {
					if (block[j][i].value != 0) {
						bool isfind = false;
						for (int k = j + 1; k < maxn; k++) {
							if (block[k][i].value != 0) {
								isfind = true;
								if (block[j][i].value == block[k][i].value) {
									block[k][i].value *= 2;
									block[j][i].value = 0;
									ismove = true;
								}
								else if (k - 1 != j) {
									block[k - 1][i].value = block[j][i].value;
									block[j][i].value = 0;
									ismove = true;
								}
								break;
							}
						}
						if (!isfind) {
							block[maxn - 1][i].value = block[j][i].value;
							block[j][i].value = 0;
							ismove = true;
						}
					}
				}
			}
			break;
		//���������ƶ�
		case 'A':
		case 'a':
		case 75:
			//�ӵ�һ�п�ʼ
			for (int i = 0; i < maxn; i++) {
				//�ӵڶ��п�ʼ����
				for (int j = 1; j < maxn; j++) {
					//�жϸ�λ���Ƿ���ڷ���
					if (block[i][j].value != 0) {
						bool isfind = false;
						for (int k = j - 1; k >= 0; k--) {
							if (block[i][k].value != 0) {
								//��ߴ��ڷ���ʱ
								isfind = true;
								//�����������ֵ���ʱ
								if (block[i][j].value == block[i][k].value) {
									block[i][k].value *= 2;
									block[i][j].value = 0;
									ismove = true;
								}
								else if (k + 1 != j) {
									block[i][k + 1].value = block[i][j].value;
									block[i][j].value = 0;
									ismove = true;
								}
								break;
							}
						}
						if (!isfind) {
							block[i][0].value = block[i][j].value;
							block[i][j].value = 0;
							ismove = true;
						}
					}
				}
			}
			break;
		//���������ƶ�
		case 'D':
		case 'd':
		case 77:
			for (int i = 0; i < maxn; i++) {
				for (int j = maxn - 2; j >=0; j--) {
					if (block[i][j].value != 0) {
						bool isfind = false;
						for (int k = j + 1; k < maxn; k++) {
							if (block[i][k].value != 0) {
								//�ұߴ��ڷ���ʱ
								isfind = true;
								//�����������ֵ���ʱ
								if (block[i][j].value == block[i][k].value) {
									block[i][k].value *= 2;
									block[i][j].value = 0;
									ismove = true;
								}
								else if (k - 1 != j) {
									block[i][k - 1].value = block[i][j].value;
									block[i][j].value = 0;
									ismove = true;
								}
								break;
							}
						}
						if (!isfind) {
							block[i][3].value = block[i][j].value;
							block[i][j].value = 0;
							ismove = true;
						}
					}
				}
			}
			break;
		}
		if (ismove)CreatNewBlock();
	}
}