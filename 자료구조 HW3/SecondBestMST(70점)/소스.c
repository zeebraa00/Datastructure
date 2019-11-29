#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 100000
#define N 1500

int num; // 입력받을 정점의 개수
int graph[N][N]; // edge 가중치 저장
int ck[N]; // 0이면 안지나감, 1이면 지나감
int sum = 0; // 경로 가중치의 합

int temp;
int Second[N];

int prim(int start) {
	int min; // minimum 값 저장할거임
	sum = 0;

	for (int i = 0; i < N; i++) {
		ck[i] = 0; // ck 배열 0으로 초기화
	}

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
	return sum;
}

int findSecond() { // idea : graph에서 edge를 하나씩 없앤 상태에서 prim() 돌려서 나온 값들 => second best mst의 후보이다.
	int count = 0;
	int minimum = INF;
	int compare;
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			temp = graph[i][j];
			compare = prim(0);
			graph[i][j] = INF;
			graph[j][i] = INF;
			if (prim(0) != compare) {
				Second[count] = prim(0);
				count++;
			}
			graph[i][j] = temp;
			graph[j][i] = temp;
		}
	}
	for (int i = 0; i < count; i++) {
		if (minimum > Second[i]) {
			minimum = Second[i];
		}
	}
	return minimum;
}

int main() {
	scanf("%d", &num); // 입력받을 정점의 개수

	for (int i = 0; i < N; i++) {
		Second[i] = INF; // Second 배열 다 INF으로 초기화
		for (int j = 0; j < N; j++) {
			graph[i][j] = INF; // graph 다 INF로 초기화
		}
	}

	int from;
	int to;
	int len;

	while ((scanf("%d %d %d\n", &from, &to, &len)) > 0) {
		graph[from][to] = len;
		graph[to][from] = len;
	}
	// graph 2차원배열 구성 끝

	printf("%d\n", prim(1));
	printf("%d\n", findSecond());

	return 0;
}