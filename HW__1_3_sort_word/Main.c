#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>

int cnt[1000][2];
int a; // 
char arr[1000][51];
char output[1000][51];
char tmp[51]="";
char ck[51];
int len;

int main() {
	int n;

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", &arr[i]);
	for (int i = 0; i < n; i++)
		cnt[i][0] = i; // count배열 넘버링
	for (int i = 0; i < n; i++)
	{
		if (ck[i] == 1) continue;
		for (int j = 0; j < n; j++)
		{
			if (!strcmp(arr[i], arr[j]))
			{
				ck[j] = 1; // j번째 단어가 i번째 단어와 같다.
				cnt[i][1]++; // i번째 단어가 count번 반복된다.
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		int max = cnt[i][1];
		int max_pos = i, temp;
		for (int j = i + 1; j < n; j++)
		{
			if (cnt[j][1] > max)
			{
				max = cnt[j][1]; // count의 최댓값
				max_pos = j; // count가 최대인 칸의 index
			}
		}
		//여기서부터 count 배열을 내림차순으로 정렬
		temp = cnt[i][1];
		cnt[i][1] = cnt[max_pos][1];
		cnt[max_pos][1] = temp;

	// 이 시점이 되면 빈도수 내림차순으로 인덱스-횟수 를 원소로 갖는 count 정렬 완료

		temp = cnt[i][0];
		cnt[i][0] = cnt[max_pos][0];
		cnt[max_pos][0] = temp;
	}

	//for (int i = 0; i < n; i++)
	//{
	//	printf("%d %d\n", cnt[i][0], cnt[i][1]);
	//}

	// 빈도수가 같을 때 알파벳 순으로 정렬하기
	for (int i=0; i < n; i ++) {
		int first=i;
		int last=i;

		//for (int j = first ; j < n; j++) {
		//	if (cnt[first][1] == cnt[j][1]) {
		//		last=j;
		//	}
		//}

		while (cnt[first][1] == cnt[last][1] && last < n) {
			//printf("			%d %d\n", cnt[first][1], cnt[last][1]);
			last++;
		}
		last--;

		//printf("first : %d , last : %d\n", i, last);
		
		//strcpy(tmp, arr[cnt[i][0]]);

		//for (i = 0; i < last - i + 1; i ++) {
		//	for (int j = first + i + 1; j <= last; j++) {
		//		if (strcmp(tmp, arr[cnt[j][0]])) { // count수가 같고, 뒤에 있는게 더 내림차순이라면
		//			strcpy(tmp, arr[cnt[j][0]]);
		//		}
		//	}
		//	strcpy(arr[cnt[i][0]], tmp);
		//	cnt[i][0] = cnt[a][0];
		//}
		i += last - first;
		for (int cycle = first; cycle <= last; cycle++) {
			for (int temp = first; temp < last; temp++)
			{
				if (strcmp(arr[cnt[temp][0]], arr[cnt[temp + 1][0]]) > 0) {
					strcpy(tmp, arr[cnt[temp][0]]);
					strcpy(arr[cnt[temp][0]], arr[cnt[temp + 1][0]]);
					strcpy(arr[cnt[temp + 1][0]], tmp);
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		//printf("인덱스 : %d - 값 : %d \n", cnt[i][0], cnt[i][1]);
		if (cnt[i][1] != 0) printf("%s\n", arr[cnt[i][0]]);
	}

	return 0;
}