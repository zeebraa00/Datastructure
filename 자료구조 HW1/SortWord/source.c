//#pragma warning (disable: 4996)
//#include "stdio.h"
//#include "string.h"
//#include "stdlib.h"
//
//int main() {
//	const unsigned int max_wlen = 51;
//	int n = -1;
//	int count = 0;
//	char** buf = NULL;
//	int arr[1000];
//
//	scanf("%d", &n); // 입력받을 단어의 개수
//
//	buf = malloc(sizeof(char*) * n);
//	for (int i = 0; i < n; i++)
//		buf[i] = malloc(sizeof(char) * max_wlen);
//
//	for (int i = 0; i < n; i++)
//		scanf("%s", buf[i]); // 단어 입력받기
//
//	for (int i = 0; i < n ; i++) {
//		for (int j = i+1; j < n; j ++) {
//			if (!strcmp(buf[i], buf[j])) {
//				count++;
//				arr[j]=-1;
//			}
//		}
//		arr[i] = count;
//		count = 0;
//	}
//
//
//
//
//
//
//
//	for (int i = 0; i < n; i++)
//		free(buf[i]);
//	free(buf);
//	return 0;
//}