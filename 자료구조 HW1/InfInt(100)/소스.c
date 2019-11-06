#pragma warning (disable: 4996)
#include "stdio.h"
#define Digit 1001

char temp[Digit]; // input �����ϰ� �ʱ�ȭ�� �� ����� ��
char output[Digit] = {'0', }; // ���� ���� ���
char tmp[Digit] = {'0', }; // ���� ��� ó���� �� ���
char tmp_2[Digit] = { '0', }; // ���� ��� ó���� �� ���
int length; // output�� �ڸ���

void Add(char input1[], char input2[]) {
	int sum;
	int carry=0; // �ڸ��� �ø� ����

	//output �ʱ�ȭ
	for (int i = 0; i < Digit - 1; i++) {
		output[i] = '0';
	}
	output[Digit - 1] = '\0';

	// ū �� ���ϱ�
	for (int i = Digit - 2; i > 0; i--) {
		sum = (input1[i] - '0') + (input2[i] - '0') + carry;
		carry = sum / 10;
		sum = sum % 10;
		output[i] = (sum + '0');
	}
}

void Product(char input1[], char input2[]) {
	int sum;
	int carry = 0;

	// �迭 ��ó��
	for (int i = 0; i < Digit-1; i++) {
		output[i] = '0';
	}
	output[Digit - 1] = '\0';
	for (int i = 0; i < Digit-1; i++) {
		tmp[i] = '0';
	}
	tmp[Digit - 1] = '\0';
	for (int i = 0; i < Digit-1; i++) {
		tmp_2[i] = '0';
	}
	tmp_2[Digit - 1] = '\0';

	// ū �� ���ϱ�
	for (int i = Digit-2; i > 0; i--) {
		for (int j = Digit-2; j > 0; j--) {
			sum = (input1[i] - '0') * (input2[j] - '0') + carry;
			carry = sum / 10;
			sum = sum % 10;
			tmp[j-(Digit-2-i)] = sum+'0';
		}
		Add(tmp_2, tmp);
		for (int i = 0; i < Digit; i++) {
			tmp_2[i] = output[i];
		}
		// tmp �ʱ�ȭ
		for (int i = 0; i < Digit; i++) {
			tmp[i] = '0';
		}
		tmp[Digit - 1] = '\0';
	}
	for (int i = 0; i < Digit; i++) {
		output[i] = tmp_2[i];
	}
}

int main() {
	char input1[Digit];
	char input2[Digit];
	char operator;

	// ������ �Է¹ޱ�
	scanf("%c", &operator);

	// input�� ���� �Է¹ޱ�
	scanf("%s", input1);
	scanf("%s", input2);

	// �Է¹��� ������ �ڸ��� ���
	int len;
	for (len = 0; input1[len] != '\0'; len++); // len�� �ڸ��� �ǹ�

	// input1 �迭 ������ �ʱ�ȭ
	for ( int i=0 ; i < Digit-len-1 ; i++) {
		temp[i] = '0'; // ���� �� 0���� ä���
	}
	for (int i = Digit-len-1 ; i < Digit ; i++) {
		temp[i] = input1[i-(Digit-len-1)]; // ��ȿ�� ���ڵ� �� �ڷ� ����
	}
	for (int i = 0; i < Digit; i++) {
		input1[i] = temp[i]; // temp�� �ִ��� input1���� ����
	}

	// input2 �迭 ������ �ʱ�ȭ
	for (len = 0; input2[len] != '\0'; len++); // len�� �ڸ��� �ǹ�
	for (int i = 0; i < Digit - len - 1; i++) {
		temp[i] = '0'; // ���� �� 0���� ä���
	}
	for (int i = Digit - len - 1; i < Digit; i++) {
		temp[i] = input2[i - (Digit - len - 1)]; // ��ȿ�� ���ڵ� �� �ڷ� ����
	}
	for (int i = 0; i < Digit; i++) {
		input2[i] = temp[i]; // temp�� �ִ��� input2���� ����
	}

	// ���� ó��
	if (operator == '+') {
		Add(input1, input2);
		for (length = 0; output[length] == '0'; length++);
		if (length == Digit - 1) {
			printf("0"); // �����==0 �� �� ����ó��
		}
		else {
			printf("%s", output + length);
		}
	}
	else if (operator == '*') {
		Product(input1, input2);
		for (length = 0; output[length] == '0'; length++);
		if (length == Digit - 1) {
			printf("0"); // �����==0 �� �� ����ó��
		}
		else {
			printf("%s", output + length);
		}
	}
	return 0;
}