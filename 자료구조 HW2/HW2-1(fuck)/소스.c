#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 2000

struct Horse {
	char name[50]; // 최대 30자
	int age; // 1~100 사이
	int rank;
};
struct Horse list[MAX_LEN]; // Horse 구조체 리스트 선언
int CheckList[MAX_LEN];
int N; // 입력받을 말의 개수
char temp_name[50];
int temp_age;
int temp_rank;

void SWAP(int i, int j) {
	strcpy(temp_name, list[i].name);
	temp_age = list[i].age;
	temp_rank = list[i].rank;
	strcpy(list[i].name, list[j].name);
	list[i].age = list[j].age;
	list[i].rank = list[j].rank;
	strcpy(list[j].name, temp_name);
	list[j].age = temp_age;
	list[j].rank = temp_rank;
}

int main() {
	int first=0;
	int last=0;

	scanf("%d", &N); // 말의 개수 입력받기
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d", list[i].name, &list[i].age, &list[i].rank);
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (list[i].age < list[j].age) { // 나이 많은 말 앞으로
				SWAP(i, j);
			}
		}
	}
	//나이순으로 정렬 완료

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			first = i;
			while (list[i].age == list[j].age) { // 나이 같은애들 first last 정하기
				last = j;
				j++;
			}
			if (last == first) break; // 동갑내기 없는경우 break
			else {
				for (int k = first; k <= last; k++) {
					for (int l = k + 1; l <= last; l++) {
						if (strcmp(list[k].name, list[l].name) == 1) { // 알파벳 순으로 정렬
							SWAP(k, l);
						}
					}
				}
			}
		}
	}
	// 나이순+이름순으로 정렬완료

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			first = i;
			while (list[i].age == list[j].age && strcmp(list[i].name,list[j].name) == 0) { // 나이 같고 이름 같은 말들 first last 정하기
				last = j;
				j++;
			}
			if (last == first) break; // 동명+동갑내기 없는경우 break
			else {
				for (int k = first; k <= last; k++) {
					for (int l = k + 1; l <= last; l++) {
						if (list[k].rank>list[l].rank) { // rank 순으로 정렬
							SWAP(k,l);
						}
					}
				}
			}
		}
	}
	// 다 했 다

	for (int i = 0; i < N; i++) {
		printf("%d %s %d\n", list[i].age, list[i].name, list[i].rank);
	}
	return 0;
}