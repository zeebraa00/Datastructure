#include <stdio.h>
#include <stdlib.h>

int map[1000][1000];
int row, col;

void DFS(int i, int j) {

	if (i < 0 || i >= row || j < 0 || j >= col) {
		return;
	}

	map[i][j] = -1;

	if (map[i+1][j] == 0) {
		DFS(i + 1, j);
	}
	if (map[i][j + 1] == 0) {
		DFS(i, j + 1);
	}
	if (map[i - 1][j] == 0) {
		DFS(i - 1, j);
	}
	if (map[i][j - 1] == 0) {
		DFS(i, j - 1);
	}
}

int main() {

	int cnt = 0;

	scanf("%d %d", &row, &col);

	//int** map = (int**)malloc(sizeof(int *) * row);
	//for (int i = 0; i < row; i++) {
	//	map[i] = (int*)malloc(sizeof(int) * col);
	//}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	//printf("Init input\n");

	//for (int k = 0; k < row; k++) {
	//	for (int l = 0; l < col; l++) {
	//		printf("%d ", map[k][l]);
	//	}
	//	printf("\n");
	//}
	//printf("\n----------------------\n\n");

	for(int i = 0; i < row; i++) {
		for(int j = 0; j <col; j++) {
			// ���� ��ġ�� 0 �϶�
			if (map[i][j] == 0) {
				// ���� ĭ�� ���� ����� �ʾҴٸ�
				if (i + 1 < row && i + 1 < col) {
					// ������ ĭ �Ʒ�ĭ �����ʾƷ�ĭ ��� 0�̶�� ===> �� ��ġ(i, j)�� ������ �»�� ��ġ

					// ������ �ϳ��� �������� Ž���ϴ� �ڵ�
					if (map[i][j + 1] == 0 && map[i + 1][j] == 0 && map[i + 1][j + 1] == 0) {
						// ���� ���� ����
						cnt++;
						// ������ �������ΰ��� ã�� �Լ�
						DFS(i, j);
					}
					// ������ �ƴϾ����ɷ�
					else {
						continue;
					}
				}
				// ����ĭ�� ����
				else {
					continue;
				}
			}
			// ������ �ƴ� ĭ
			else {
				continue;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}