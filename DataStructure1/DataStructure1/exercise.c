/*
	n���� �ܾ �ް�, �� �ܾ��� ���̸� ����ϴ� ���α׷� �ۼ�
	input : ù �ٿ� �� �Է� �޴� �ܾ��� ���� N �Է� -> �� ���� N�ٿ� ���� N���� �ܾ� �Էµ�
	output : �� �ܾ��� ���̸� �� �� �� �� ��� (�� �ܾ��� ���� <= 50)
*/

#include "header.h"

int exercise()
{
	const unsigned int max_wlen = 51;
	int n = -1;

	char** buf = NULL;

	printf("input the # of words.\n");

	scanf_s("%d", &n);

	buf = malloc(sizeof(char*) * n); // char�������� size * n ��ŭ�� �޸� �Ҵ� : 1���� �����迭
	for (int i = 0; i < n; i++)
		buf[i] = malloc(sizeof(char) * max_wlen); // �� buf[i]�� ���� char*max_wlen�� ũ�⸸ŭ �޸� �Ҵ� : 2���� �����迭 �ϼ�

	for (int i = 0; i < n; i++)
		scanf_s("%s", buf[i]);

	for (int i = 0; i < n; i++)
		printf("%lu\n", strlen(buf[i])); // %lu : unsigned long int

	for (int i = 0; i < n; i++)
		free(buf[i]); // buf���� free�ϸ� 2���� �迭�鿡 �Ҵ�� memory�� ������ ����� ���� ������, buf[i]���� free�ϰ�!

	free(buf); // �������� buf�� free ����

	return 0;
}