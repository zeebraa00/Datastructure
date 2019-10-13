#pragma warning (disable: 4996)
#include <stdio.h>

char output[1001] = "";

void init(char output[]) {
	for (int i = 0; i < 1000; i++) {
		output[i] = '0';
	}
	output[1000] = '\0';
}

void plus1(char input1[], char input2[]) {
	int i, sum;
	int carry = 0;

	for (i = 999; i >= 0; i--) {
		sum = (input1[i] - '0') + (input2[i] - '0') + carry;
		carry = sum / 10;
		sum = sum % 10;
		output[i + 1] = sum + '0';
	}
	output[0] = carry + '0';
}

void plus2(char input1[], char input2[]) {
	int i, sum;
	int carry = 0;

	for (i = 999; i >= 0; i--) {
		sum = (input1[i] - '0') + (input2[i] - '0') + carry;
		carry = sum / 10;
		sum = sum % 10;
		output[i] = sum + '0';
	}
	output[0] = carry + '0';
}

int main() {
	char buf1[1001];
	char buf2[1001];
	char input1[1001];
	char input2[1001];
	char temp[1001];
	char oper[2];
	int i, j;
	int len1, len2;
	int sum = 0;
	int carry = 0;

	scanf("%s", oper);
	scanf("%s", buf1);
	for (i = 0; buf1[i] != '\0'; i++);
	len1 = i;
	for (j = 0; j < 1000 - i; j++) {
		input1[j] = '0';
	}
	for (j = 0; j <= i; j++) {
		input1[1000 - i + j] = buf1[j];
	}
	scanf("%s", buf2);
	for (i = 0; buf2[i] != '\0'; i++);
	len2 = i;
	for (j = 0; j < 1000 - i; j++) {
		input2[j] = '0';
	}
	for (j = 0; j <= i; j++) {
		input2[1000 - i + j] = buf2[j];
	}
	if (oper[0] == '+') {
		plus1(input1, input2);
		for (i = 0; output[i] == '0'; i++);
		if ((output + i)[0] == '\0')	printf("0");
		else printf("%s", output + i);
	}
	else if (oper[0] == '*') {
		init(temp);
		init(output);
		for (i = 999; i >= 1000 - len2; i--) {
			for (j = 999; j >= 1000 - len1; j--) {
				sum = (input2[i] - '0') * (input1[j] - '0') + carry;
				carry = sum / 10;
				temp[j - (999 - i)] += (sum % 10);
			}
			temp[999 - len2 - (999 - i)] += carry;
			plus2(temp, output);
			init(temp);
			carry = 0;
		}
		for (i = 0; output[i] == '0'; i++);
		if ((output + i)[0] == '\0')	printf("0");
		else printf("%s", output + i);
	}
	else {
		return -1;
	}
	return 0;
}