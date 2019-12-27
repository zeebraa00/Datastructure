#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1000

struct BUFF {
	char input1;
	char input2;
};

struct HORSE { // 말 구조체
	int age; // input1
	int rank; // input2
};

struct HORSE arr[MAX_LEN]; // 말 구조체 배현웅
struct BUFF array[MAX_LEN];

int compare(const void * A, const void * B) { // compare fucntion : A가 B보다 앞설때는 음수, 뒤질때는 양수, 같으면 0 return
	struct HORSE a = (*(struct HORSE*)A);
	struct HORSE b = (*(struct HORSE*)B);
	if (a.age != b.age) {
		return a.age - b.age;
	}
	if (a.rank != b.rank) {
		return a.rank - b.rank;
	}
}

int main() {
	int N; // 입력받을 말의 개수
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s %s", &array[i].input1, &array[i].input2);
	}

	for (int i = 0; i < N ; i++) {
		if (array[i].input1 == 'C') {
			arr[i].age = 1;
		}
		else if (array[i].input1 == 'D') {
			arr[i].age = 2;
		}
		else if (array[i].input1 == 'H') {
			arr[i].age = 3;
		}
		else if (array[i].input1 == 'S') {
			arr[i].age = 4;
		}
	}

	for (int i=0 ; i<N ; i++) {
		if (array[i].input2 == 'J') {
			arr[i].rank = 11;
		}
		else if (array[i].input2 == 'Q') {
			arr[i].rank = 12;
		}
		else if (array[i].input2 == 'K') {
			arr[i].rank = 13;
		}
		else if (array[i].input2 == 'A') {
			arr[i].rank = 14;
		}
		else if (array[i].input2 == '2') {
			arr[i].rank = 2;
		}
		else if (array[i].input2 == '3') {
			arr[i].rank = 3;
		}
		else if (array[i].input2 == '4') {
			arr[i].rank = 4;
		}
		else if (array[i].input2 == '5') {
			arr[i].rank = 5;
		}
		else if (array[i].input2 == '6') {
			arr[i].rank = 6;
		}
		else if (array[i].input2 == '7') {
			arr[i].rank = 7;
		}
		else if (array[i].input2 == '8') {
			arr[i].rank = 8;
		}
		else if (array[i].input2 == '9') {
			arr[i].rank = 9;
		}
		else {
			arr[i].rank = 10;
		}
	}

	qsort(arr, N, sizeof(arr[0]), compare);

	for (int i = 0; i < N; i++) {
		if (arr[i].age == 1) {
			array[i].input1 = 'C';
		}
		else if (arr[i].age == 2) {
			array[i].input1 = 'D';
		}
		else if (arr[i].age == 3) {
			array[i].input1 = 'H';
		}
		else if (arr[i].age == 4) {
			array[i].input1 = 'S';
		}
	}

	for (int i = 0; i < N; i++) {
		if (arr[i].rank == 11) {
			array[i].input2 = 'J';
		}
		else if (arr[i].rank == 12) {
			array[i].input2 = 'Q';
		}
		else if (arr[i].rank == 13) {
			array[i].input2 = 'K';
		}
		else if (arr[i].rank == 14) {
			array[i].input2 = 'A';
		}
		else if (arr[i].rank == 10) {
			array[i].input2 = '10';
		}
		else if (arr[i].rank == 2) {
			array[i].input2 = '2';
		}
		else if (arr[i].rank == 3) {
			array[i].input2 = '3';
		}
		else if (arr[i].rank == 4) {
			array[i].input2 = '4';
		}
		else if (arr[i].rank == 5) {
			array[i].input2 = '5';
		}
		else if (arr[i].rank == 6) {
			array[i].input2 = '6';
		}
		else if (arr[i].rank == 7) {
			array[i].input2 = '7';
		}
		else if (arr[i].rank == 8) {
			array[i].input2 = '8';
		}
		else if (arr[i].rank == 9) {
			array[i].input2 = '9';
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%c %c \n", array[i].input1, array[i].input2);
	}

	return 0;
}