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
	settextstyle(64, 0, _T("����"));
	outtextxy(125,100 , _T("2 0 4 8"));

	settextstyle(25, 0, _T("����"));
	outtextxy(165, 200, _T("����:Minjer"));
	settextstyle(25, 0, _T("����"));
	outtextxy(170, 300, _T("��ע��Ȼ"));
	outtextxy(170, 350, _T("�ٶٽ��"));
	settextstyle(25, 0, _T("����"));
	outtextxy(110, 400, _T("���»س�����ʼ��Ϸ..."));
	while (true)
	{
		if (_kbhit()) {
			break;
		}
	}
	//�������������ʼ����
	CreatNewBlock();
	CreatNewBlock();
}