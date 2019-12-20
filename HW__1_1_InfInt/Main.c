#pragma warning (disable: 4996)
#include "stdio.h"
#define Digit 1001

char temp[Digit]; // input 적절하게 초기화할 때 사용할 것
char output[Digit] = {'0', }; // 최종 연산 결과
char tmp[Digit] = {'0', }; // 연산 결과 처리할 때 사용
char tmp_2[Digit] = { '0', }; // 연산 결과 처리할 때 사용
int length; // output의 자릿수

void Add(char input1[], char input2[]) {
	int sum;
	int carry=0; // 자릿수 올림 변수

	//output 초기화
	for (int i = 0; i < Digit - 1; i++) {
		output[i] = '0';
	}
	output[Digit - 1] = '\0';

	// 큰 수 더하기
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

	// 배열 전처리
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

	// 큰 수 곱하기
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
		// tmp 초기화
		for (int i = 0; i < Digit; i++) {
			tmp[i] = '0';
		}
		tmp[Digit - 1] = '\0';
	}
	//printf("곱셈결과 : %s\n", tmp_2);
	for (int i = 0; i < Digit; i++) {
		output[i] = tmp_2[i];
	}
}

int main() {
	char input1[Digit];
	char input2[Digit];
	char operator;

	// 연산자 입력받기
	scanf("%c", &operator);

	// input에 정수 입력받기
	scanf("%s", input1);
	scanf("%s", input2);

	// 입력받은 정수의 자릿수 계산
	int len;
	for (len = 0; input1[len] != '\0'; len++); // len이 자릿수 의미

	// input1 배열 적절히 초기화
	for ( int i=0 ; i < Digit-len-1 ; i++) {
		temp[i] = '0'; // 앞을 다 0으로 채우기
	}
	for (int i = Digit-len-1 ; i < Digit ; i++) {
		temp[i] = input1[i-(Digit-len-1)]; // 유효한 숫자들 맨 뒤로 뺴기
	}
	for (int i = 0; i < Digit; i++) {
		input1[i] = temp[i]; // temp에 있던거 input1으로 복붙
	}

	// input2 배열 적절히 초기화
	for (len = 0; input2[len] != '\0'; len++); // len이 자릿수 의미
	for (int i = 0; i < Digit - len - 1; i++) {
		temp[i] = '0'; // 앞을 다 0으로 채우기
	}
	for (int i = Digit - len - 1; i < Digit; i++) {
		temp[i] = input2[i - (Digit - len - 1)]; // 유효한 숫자들 맨 뒤로 뺴기
	}
	for (int i = 0; i < Digit; i++) {
		input2[i] = temp[i]; // temp에 있던거 input2으로 복붙
	}

	// 연산 처리
	if (operator == '+') {
		Add(input1, input2);
		for (length = 0; output[length] == '0'; length++);
		if (length == Digit - 1) {
			printf("0"); // 결과값==0 일 때 예외처리
		}
		else {
			printf("%s", output + length);
		}
	}
	else if (operator == '*') {
		Product(input1, input2);
		for (length = 0; output[length] == '0'; length++);
		if (length == Digit - 1) {
			printf("0"); // 결과값==0 일 때 예외처리
		}
		else {
			printf("%s", output + length);
		}
	}
	return 0;
}