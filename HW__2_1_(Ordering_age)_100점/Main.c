#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1000

char temp_name[50];
int temp_age;
int temp_rank;

struct HORSE { // 말 구조체
	char name[50];
	int age;
	int rank;
};

struct HORSE arr[MAX_LEN]; // 말 구조체 배열

int compare(const void * A, const void * B) { // compare fucntion : A가 B보다 앞설때는 음수, 뒤질때는 양수, 같으면 0 return
	struct HORSE a = (*(struct HORSE*)A);
	struct HORSE b = (*(struct HORSE*)B);
	if (a.age != b.age) {
		return b.age - a.age;
	}
	if (a.name != b.name) {
		return strcmp(a.name, b.name);
	}
}

// rank 순으로만 정렬시키면 됨

void SWAP(int i, int j) {
	strcpy(temp_name, arr[i].name);
	temp_age = arr[i].age;
	temp_rank = arr[i].rank;
	strcpy(arr[i].name, arr[j].name);
	arr[i].age = arr[j].age;
	arr[i].rank = arr[j].rank;
	strcpy(arr[j].name, temp_name);
	arr[j].age = temp_age;
	arr[j].rank = temp_rank;
}

void sort(int N) {
	int first=0;
	int last=0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			first = i;
			while ( !strcmp(arr[i].name, arr[j].name) ) { // 이름 같은애들 first last 정하기
				last = j;
				j++;
			}
			if (last == first) break; // 동명이마 없는경우 break
			else {
				for (int k = first; k <= last; k++) {
					for (int l = k + 1; l <= last; l++) {
						if ( arr[k].rank > arr[l].rank ) { // 알파벳 순으로 정렬
							SWAP(k, l);
						}
					}
				}
			}
		}
	}
}

int main() {
	int N; // 입력받을 말의 개수
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s %d %d", arr[i].name, &arr[i].age, &arr[i].rank);
	}
	// N개의 말 정보 입력받았음

	qsort(arr, N, sizeof(arr[0]), compare);

	sort(N);

	for (int i = 0; i < N; i++) {
		printf("%d %s %d\n", arr[i].age, arr[i].name, arr[i].rank);
	}

	return 0;
}