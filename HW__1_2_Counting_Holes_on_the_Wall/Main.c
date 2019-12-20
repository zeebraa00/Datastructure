#include <stdio.h>
#include <stdlib.h>

int map[1000][1000];
int row, col;

void DFS(int i, int j) {
	//printf("Start DFS function at pos : %d %d\n", i, j);

	if (i < 0 || i >= row || j < 0 || j >= col) {
		return;
	}

	map[i][j] = -1;

	//printf("Current pos : %d %d\n", i, j);
	//for (int k = 0; k < row; k++) {
	//	for (int l = 0; l < col; l++) {
	//		printf("%d ", map[k][l]);
	//	}
	//	printf("\n");
	//}
	//printf("\n----------------------\n\n");


	if (map[i+1][j] == 0) {
		//map[i + 1][j] = -1;
		DFS(i + 1, j);
	}
	if (map[i][j + 1] == 0) {
		//map[i][j + 1] = -1;
		DFS(i, j + 1);
	}
	if (map[i - 1][j] == 0) {
		//map[i - 1][j] = -1;
		DFS(i - 1, j);
	}
	if (map[i][j - 1] == 0) {
		//map[i][j - 1] = -1;
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
			// 현재 위치가 0 일때
			if (map[i][j] == 0) {
				// 다음 칸이 맵을 벗어나지 않았다면
				if (i + 1 < row && i + 1 < col) {
					// 오른쪽 칸 아래칸 오른쪽아래칸 모두 0이라면 ===> 이 위치(i, j)는 구멍의 좌상단 위치

					// 어디까지 하나의 구멍인지 탐색하는 코드
					if (map[i][j + 1] == 0 && map[i + 1][j] == 0 && map[i + 1][j + 1] == 0) {
						// 구멍 숫자 증가
						cnt++;
						// 구멍이 어디까지인가를 찾는 함수
						DFS(i, j);
					}
					// 구멍이 아니었던걸로
					else {
						continue;
					}
				}
				// 다음칸이 없음
				else {
					continue;
				}
			}
			// 구멍이 아닌 칸
			else {
				continue;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}