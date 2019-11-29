#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define INF 9999
#define N 1500

int num; // 입력받을 정점의 개수
float graph[N][N]; // edge 가중치 저장
int ck[N]; // 0이면 안지나감, 1이면 지나감
float sum = 0; // 경로 가중치의 합

typedef struct vertex {
	int x;
	int y;
}Vertex;

void prim(int start) {
	float min; // minimum 값 저장할거임

	ck[start] = 1; // 출발 vertex 체크

	for (int count = 0; count < num - 1; count++) {
		min = INF;
		int x = start, y = start;
		for (int i = 0; i < num; i++) {
			if (ck[i] == 0) continue; // 지나갔던 vertex들이 시작점이 되어서
			for (int j = 0; j < num; j++) {
				if (ck[j] == 0) { // 나머지 안지나간 vertex들로 가는 edge들 중에서
					if (min > graph[i][j]) {
						min = graph[i][j]; // 가장 가중치가 짧은 vertex를 고른다
						x = i, y = j;
					}
				}
			}
		}
		ck[y] = 1;
		if (graph[x][y] != INF) {
			sum += graph[x][y];
		}
	}
}


int main() {
	scanf("%d", &num); // 입력받을 정점의 개수
	//printf("%d\n", num);

	Vertex arr[N]; // Vertex 구조체 배열 선언 num칸

	for (int i = 0; i < N; i++) {
		ck[i] = 0; // used 배열 0으로 초기화
		for (int j = 0; j < N; j++) {
			graph[i][j] = INF; // graph 다 INF로 초기화
		}
	}

	int from;
	int to;
	float len;

	for (int i = 0; i < num; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y); // num개의 좌표 입력받는다.
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			len = sqrt(pow((arr[i].x - arr[j].x),2) + pow((arr[i].y - arr[j].y), 2));
			graph[i][j] = len;
			graph[j][i] = len;
		}
	}
	// graph 2차원배열 구성 끝

	//for (int i = 0; i < num; i++) {
	//	for (int j = 0; j < num; j++) {
	//		printf("%.2f  ", graph[i][j]);
	//	}
	//	puts("");
	//}

	prim(1);
	printf("%.2f", sum);

	return 0;
}