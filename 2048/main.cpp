#include<iostream>
using namespace std;
void InitialInterface();
void GameInterface();
void InitializeBlock();
void CreatNewBlock();
void MoveBlock();
void DeathJudge();
int main() {
	InitializeBlock();
	InitialInterface();

	while (true){
	GameInterface();
	MoveBlock();
	DeathJudge();
	}
	system("pause");
	return 0;
}