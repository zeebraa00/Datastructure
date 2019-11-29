#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 100000
#define N 1500

int num; // �Է¹��� ������ ����
int graph[N][N]; // edge ����ġ ����
int ck[N]; // 0�̸� ��������, 1�̸� ������
int sum = 0; // ��� ����ġ�� ��

int temp;
int Second[N];

int prim(int start) {
	int min; // minimum �� �����Ұ���
	sum = 0;

	for (int i = 0; i < N; i++) {
		ck[i] = 0; // ck �迭 0���� �ʱ�ȭ
	}

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
	return sum;
}

int findSecond() { // idea : graph���� edge�� �ϳ��� ���� ���¿��� prim() ������ ���� ���� => second best mst�� �ĺ��̴�.
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
	scanf("%d", &num); // �Է¹��� ������ ����

	for (int i = 0; i < N; i++) {
		Second[i] = INF; // Second �迭 �� INF���� �ʱ�ȭ
		for (int j = 0; j < N; j++) {
			graph[i][j] = INF; // graph �� INF�� �ʱ�ȭ
		}
	}

	int from;
	int to;
	int len;

	while ((scanf("%d %d %d\n", &from, &to, &len)) > 0) {
		graph[from][to] = len;
		graph[to][from] = len;
	}
	// graph 2�����迭 ���� ��

	printf("%d\n", prim(1));
	printf("%d\n", findSecond());

	return 0;
}