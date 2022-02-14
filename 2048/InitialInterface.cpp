#include<easyx.h>
#include<conio.h>
#include<stdio.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
void CreatNewBlock();
void InitialInterface() {
	mciSendString("open ../music/bgm.mp3 alias BGM", 0, 0, 0);
	mciSendString("play BGM repeat", 0, 0, 0);
	initgraph(480, 640);
	/*setbkcolor(WHITE);
	cleardevice();*/
	settextstyle(64, 0, _T("黑体"));
	outtextxy(125,100 , _T("2 0 4 8"));

	settextstyle(25, 0, _T("黑体"));
	outtextxy(165, 200, _T("作者:Minjer"));
	settextstyle(25, 0, _T("楷体"));
	outtextxy(170, 300, _T("关注嘉然"));
	outtextxy(170, 350, _T("顿顿解馋"));
	settextstyle(25, 0, _T("黑体"));
	outtextxy(110, 400, _T("按下回车键开始游戏..."));
	while (true)
	{
		if (_kbhit()) {
			break;
		}
	}
	//随机生成两个初始方块
	CreatNewBlock();
	CreatNewBlock();
}