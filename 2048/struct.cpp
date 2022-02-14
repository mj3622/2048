#include"struct.h"
blocks block[maxn][maxn];
void InitializeBlock() {
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			block[i][j].left = j * 120;
			block[i][j].top = 160 + 120 * i;
			block[i][j].right = (j + 1) * 120;
			block[i][j].bottom = 160 + 120 * (i + 1);
			block[i][j].value = 0;
		}
	}
}