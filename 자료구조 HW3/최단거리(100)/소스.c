#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define INF 9999
#define N 1500

int num; // �Է¹��� ������ ����
float graph[N][N]; // edge ����ġ ����
int ck[N]; // 0�̸� ��������, 1�̸� ������
float sum = 0; // ��� ����ġ�� ��

typedef struct vertex {
	int x;
	int y;
}Vertex;

void prim(int start) {
	float min; // minimum �� �����Ұ���

	ck[start] = 1; // ��� vertex üũ

	for (int count = 0; count < num - 1; count++) {
		min = INF;
		int x = start, y = start;
		for (int i = 0; i < num; i++) {
			if (ck[i] == 0) continue; // �������� vertex���� �������� �Ǿ
			for (int j = 0; j < num; j++) {
				if (ck[j] == 0) { // ������ �������� vertex��� ���� edge�� �߿���
					if (min > graph[i][j]) {
						min = graph[i][j]; // ���� ����ġ�� ª�� vertex�� ����
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
	scanf("%d", &num); // �Է¹��� ������ ����
	//printf("%d\n", num);

	Vertex arr[N]; // Vertex ����ü �迭 ���� numĭ

	for (int i = 0; i < N; i++) {
		ck[i] = 0; // used �迭 0���� �ʱ�ȭ
		for (int j = 0; j < N; j++) {
			graph[i][j] = INF; // graph �� INF�� �ʱ�ȭ
		}
	}

	int from;
	int to;
	float len;

	for (int i = 0; i < num; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y); // num���� ��ǥ �Է¹޴´�.
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			len = sqrt(pow((arr[i].x - arr[j].x),2) + pow((arr[i].y - arr[j].y), 2));
			graph[i][j] = len;
			graph[j][i] = len;
		}
	}
	// graph 2�����迭 ���� ��

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