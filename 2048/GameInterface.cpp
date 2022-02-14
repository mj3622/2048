#include"struct.h"
#include<easyx.h>
#include<stdio.h>
extern blocks block[maxn][maxn];
void GameInterface() {
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

	//计算分数
	int score = 0;
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			score += block[i][j].value;
		}
	}
	char score_put[6];
	sprintf_s(score_put,"%d", score);
	//显示分数
	settextstyle(64, 0, _T("黑体"));
	outtextxy(100, 60, _T("分数："));
	outtextxy(270, 60, score_put);

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
	//结束双缓冲绘图
	EndBatchDraw();
}