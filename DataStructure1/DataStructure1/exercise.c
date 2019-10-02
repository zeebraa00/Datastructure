/*
	n개의 단어를 받고, 각 단어의 길이를 출력하는 프로그램 작성
	input : 첫 줄에 총 입력 받는 단어의 개수 N 입력 -> 그 이후 N줄에 걸쳐 N개의 단어 입력됨
	output : 각 단어의 길이를 한 줄 한 줄 출력 (한 단어의 길이 <= 50)
*/

#include "header.h"

int exercise()
{
	const unsigned int max_wlen = 51;
	int n = -1;

	char** buf = NULL;

	printf("input the # of words.\n");

	scanf_s("%d", &n);

	buf = malloc(sizeof(char*) * n); // char포인터의 size * n 만큼의 메모리 할당 : 1차원 가변배열
	for (int i = 0; i < n; i++)
		buf[i] = malloc(sizeof(char) * max_wlen); // 각 buf[i]에 대해 char*max_wlen의 크기만큼 메모리 할당 : 2차원 가변배열 완성

	for (int i = 0; i < n; i++)
		scanf_s("%s", buf[i]);

	for (int i = 0; i < n; i++)
		printf("%lu\n", strlen(buf[i])); // %lu : unsigned long int

	for (int i = 0; i < n; i++)
		free(buf[i]); // buf부터 free하면 2차원 배열들에 할당된 memory에 접근할 방법이 없기 때문에, buf[i]부터 free하고!

	free(buf); // 마지막에 buf를 free 해줌

	return 0;
}