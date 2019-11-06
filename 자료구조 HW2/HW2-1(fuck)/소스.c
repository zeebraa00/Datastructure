#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 2000

struct Horse {
	char name[50]; // �ִ� 30��
	int age; // 1~100 ����
	int rank;
};
struct Horse list[MAX_LEN]; // Horse ����ü ����Ʈ ����
int CheckList[MAX_LEN];
int N; // �Է¹��� ���� ����
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

	scanf("%d", &N); // ���� ���� �Է¹ޱ�
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d", list[i].name, &list[i].age, &list[i].rank);
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (list[i].age < list[j].age) { // ���� ���� �� ������
				SWAP(i, j);
			}
		}
	}
	//���̼����� ���� �Ϸ�

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			first = i;
			while (list[i].age == list[j].age) { // ���� �����ֵ� first last ���ϱ�
				last = j;
				j++;
			}
			if (last == first) break; // �������� ���°�� break
			else {
				for (int k = first; k <= last; k++) {
					for (int l = k + 1; l <= last; l++) {
						if (strcmp(list[k].name, list[l].name) == 1) { // ���ĺ� ������ ����
							SWAP(k, l);
						}
					}
				}
			}
		}
	}
	// ���̼�+�̸������� ���ĿϷ�

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			first = i;
			while (list[i].age == list[j].age && strcmp(list[i].name,list[j].name) == 0) { // ���� ���� �̸� ���� ���� first last ���ϱ�
				last = j;
				j++;
			}
			if (last == first) break; // ����+�������� ���°�� break
			else {
				for (int k = first; k <= last; k++) {
					for (int l = k + 1; l <= last; l++) {
						if (list[k].rank>list[l].rank) { // rank ������ ����
							SWAP(k,l);
						}
					}
				}
			}
		}
	}
	// �� �� ��

	for (int i = 0; i < N; i++) {
		printf("%d %s %d\n", list[i].age, list[i].name, list[i].rank);
	}
	return 0;
}