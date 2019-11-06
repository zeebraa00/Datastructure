#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1000

struct HORSE { // �� ����ü
	char name[50];
	int age;
	int rank;
};

struct HORSE arr[MAX_LEN]; // �� ����ü �迭

int compare(const void * A, const void * B) {
	struct HORSE a = (*(struct HORSE*)A);
	struct HORSE b = (*(struct HORSE*)B);
	if (a.age != b.age) {
		return b.age - a.age;
	}
	else if (a.name != b.name) {
		return b.name - a.name;
	}
	else
		return a.rank - b.rank;
}

int main() {
	int N; // �Է¹��� ���� ����
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s %d %d", arr[i].name, &arr[i].age, &arr[i].rank);
	}
	// N���� �� ���� �Է¹޾���

	qsort(arr, N, sizeof(arr[0]), compare);

	for (int i = 0; i < N; i++) {
		printf("%d %s %d\n", arr[i].age, arr[i].name, arr[i].rank);
	}

	return 0;
}