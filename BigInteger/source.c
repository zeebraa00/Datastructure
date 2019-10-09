#pragma warning (disable: 4996)
#include <stdio.h>

int main() {
	char buf1[101];
	char buf2[101];
	char input1[101];
	char input2[101];
	char temp[201];
	char output[201] = "";
	char oper[2];
	int i, j;
	int len1, len2;
	int sum = 0;
	int carry = 0;

	scanf("%c", &oper);
	scanf("%s", &buf1);
	for (i = 0; buf1[i] != NULL; i++);
	len1 = i;
	for (j = 0; j < 100 - i; j++) {
		input1[j] = '0';
	}
	for (j = 0; j <= i; j++) {
		input1[100 - i + j] = buf1[j];
	}
	scanf("%s", &buf2);
	for (i = 0; buf2[i] != NULL; i++);
	len2 = i;
	for (j = 0; j < 100 - i; j++) {
		input2[j] = '0';
	}
	for (j = 0; j <= i; j++) {
		input2[100 - i + j] = buf2[j];
	}

	if (oper[0] == '+') {
		for (i = 99; i >= 0; i--) {
			sum = (input1[i] - '0') + (input2[i] - '0') + carry;
			carry = sum / 10;
			sum = sum % 10;
			output[i + 1] = sum + '0';
		}
		output[0] = carry + '0';
		for (i = 0; output[i] == '0'; i++);
		printf("%s\n", output + i);
	}
	else if (oper[0] == '*') {

		//fucking °öÇÏ±â¾¾ ÆÈ
		temp[200] = NULL;
		for (i = 0; i < 200; i++) {
			temp[i] = 0;
		}

		for (i = 99; i >= 100 - len1; i--) {
			for (j = 99; j >= 100 - len2; j--) {
				sum = (input1[i] - '0') * (input2[j] - '0') + carry;
				carry = sum / 10;
				sum = sum % 10;
				temp[j + 100 - (99-i)] += sum;
			}
			temp[199 - len2 - (99-i)] += carry;
		}



		for (i = 0; i < 201; i++) {
			output[i] = temp[i] + '0';
		}
		for (i = 0; output[i] == '0'; i++);
		printf("%s\n", output + i);
	
	
	
	}
	else {
		return -1;
	}
	return 0;
}