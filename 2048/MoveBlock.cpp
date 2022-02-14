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
		//整体向上移动
		case 'W':
		case 'w':
		case 72:
			for (int i = 0; i < maxn; i++) {			//从第一列开始
				for (int j = 1; j < maxn; j++) {		//从第二行开始移动
					//判断该位置是否存在方块
					if (block[j][i].value != 0) {
						//找到最顶部的方块的位置
						bool isfind = false;
						for (int k = j - 1; k >= 0; k--) {
							if (block[k][i].value != 0) {
								//找到了顶上的方块
								isfind = true;
								//两个方块可以合并时
								if (block[j][i].value == block[k][i].value) {
									block[k][i].value *= 2;
									block[j][i].value = 0;
									ismove = true;
								}
								//两个方块不能够合并时
								else if (k + 1 != j) {
									block[k + 1][i].value = block[j][i].value;
									block[j][i].value = 0;
									ismove = true;
								}
								break;
							}
						}
						//顶上没有方块时
						if (!isfind) {
							block[0][i].value = block[j][i].value;
							block[j][i].value = 0;
							ismove = true;
						}
					}
				}
			}
			break;
		//整体向下移动
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
		//整体向左移动
		case 'A':
		case 'a':
		case 75:
			//从第一行开始
			for (int i = 0; i < maxn; i++) {
				//从第二列开始往左靠
				for (int j = 1; j < maxn; j++) {
					//判断该位置是否存在方块
					if (block[i][j].value != 0) {
						bool isfind = false;
						for (int k = j - 1; k >= 0; k--) {
							if (block[i][k].value != 0) {
								//左边存在方块时
								isfind = true;
								//当两个方块的值相等时
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
		//整体向右移动
		case 'D':
		case 'd':
		case 77:
			for (int i = 0; i < maxn; i++) {
				for (int j = maxn - 2; j >=0; j--) {
					if (block[i][j].value != 0) {
						bool isfind = false;
						for (int k = j + 1; k < maxn; k++) {
							if (block[i][k].value != 0) {
								//右边存在方块时
								isfind = true;
								//当两个方块的值相等时
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