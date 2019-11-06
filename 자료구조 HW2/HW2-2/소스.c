#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStruct {
	int value;
	struct NodeStruct* leftChild;
	struct NodeStruct* rightChild;
};

struct NodeStruct* root = NULL;

struct NodeSturct* BST_I(struct NodeStruct* node, int value) {
	if (node == NULL) { // ó���̸�
		node = (struct Node*)malloc(sizeof(struct NodeStruct));
		node->leftChild = node->rightChild = NULL;
		node->value = value;
		return node;
	}
	else { // ó���� �ƴϸ�
		if (node->value > value) {
			node->leftChild = BST_I(node->leftChild, value);
		}
		else {
			node->rightChild = BST_I(node->rightChild, value);
		}
	}
	return node;
}

int DEPTH(struct NodeStruct* node) {
	int max = 0, depth;
	if (node == NULL)
		return 0; // ��Ʈ���� ���� = 0
	else {
		depth = DEPTH(node->leftChild) + 1; // ���� = ���� ���� + 1
		if (depth > max)
			max = depth;
		depth = DEPTH(node->rightChild) + 1;
		if (depth > max)
			max = depth;
		return max;
	}
}

int main() {
	int N; // �Է¹��� ����
	int input; // �ԷµǴ� ����
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		root = BST_I(root, input);
	}

	printf("%d", DEPTH(root)-1);

	return 0;
}