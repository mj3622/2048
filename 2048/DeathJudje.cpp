#include"struct.h"
#include<easyx.h>
#include<stdio.h>
extern blocks block[maxn][maxn];
void DeathJudge() {
	bool flag = false;
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			if (block[i][j].value == 0) {
				flag = true;
				break;
			}
			if (i == 0 && j == 0){
				if (block[i][j].value == block[i + 1][j].value || block[i][j].value == block[i][j + 1].value)flag = true;
			}
			else if (i == 0 && j == maxn - 1) {
				if (block[i][j].value == block[i + 1][j].value || block[i][j].value == block[i][j - 1].value)flag = true;
			}
			else if (i == maxn - 1 && j == 0) {
				if (block[i][j].value == block[i - 1][j].value || block[i][j].value == block[i][j + 1].value)flag = true;
			}
			else if (i == maxn - 1 && j == maxn - 1) {
				if (block[i][j].value == block[i - 1][j].value || block[i][j].value == block[i][j - 1].value)flag = true;
			}
			else if (i == 0) {
				if (block[i][j].value == block[i][j - 1].value || block[i][j].value == block[i][j + 1].value || block[i][j].value == block[i + 1][j].value)flag = true;
			}
			else if (i == maxn - 1) {
				if (block[i][j].value == block[i][j - 1].value || block[i][j].value == block[i][j + 1].value || block[i][j].value == block[i - 1][j].value)flag = true;
			}
			else if (j == 0) {
				if (block[i][j].value == block[i + 1][j].value || block[i][j].value == block[i - 1][j].value || block[i][j].value == block[i][j + 1].value)flag = true;
			}
			else if (j == maxn - 1) {
				if (block[i][j].value == block[i + 1][j].value || block[i][j].value == block[i - 1][j].value || block[i][j].value == block[i][j - 1].value)flag = true;
			}
			else {
				if (block[i][j].value == block[i + 1][j].value || block[i][j].value == block[i - 1][j].value || block[i][j].value == block[i][j + 1].value || block[i][j].value == block[i][j - 1].value)flag = true;
			}
		}
		if (flag)break;
	}
	if (!flag) {
		while (1) {
			cleardevice();

			//开始双缓冲绘图
			BeginBatchDraw();



			//绘制游戏主体界面
			setlinecolor(RGB(208, 207, 209));
			for (int i = 0; i < maxn; i++)
				line(i * 120, 160, i * 120, 640);
			for (int i = 0; i < maxn; i++)
				line(0, 160 + i * 120, 480, 160 + i * 120);
			line(479, 160, 479, 640);
			line(0, 639, 480, 639);


			//画方块
			setfillcolor(RGB(135, 139, 153));
			char block_value[6];				//用于显示每个方块的数字
			settextstyle(48, 0, _T("黑体"));
			for (int i = 0; i < maxn; i++) {
				for (int j = 0; j < maxn; j++) {
					if (block[i][j].value != 0) {
						fillrectangle(block[i][j].left, block[i][j].top, block[i][j].right, block[i][j].bottom);
						sprintf_s(block_value, "%d", block[i][j].value);
						setbkmode(TRANSPARENT);
						if (block[i][j].value < 10)
							outtextxy(block[i][j].left + 45, block[i][j].top + 40, block_value);
						else if (block[i][j].value < 100)
							outtextxy(block[i][j].left + 35, block[i][j].top + 40, block_value);
						else if (block[i][j].value < 1000)
							outtextxy(block[i][j].left + 25, block[i][j].top + 40, block_value);
						else
							outtextxy(block[i][j].left + 15, block[i][j].top + 40, block_value);
					}
				}
			}
			settextstyle(64, 0, _T("黑体"));
			outtextxy(110, 60, _T("游戏结束！"));
			//结束双缓冲绘图
			EndBatchDraw();
		}
	}
}