#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	struct Node* next;
	int data;
}Node;

int hash(int data, int m);
void insert(Node* v, int data, int m);
int search(Node* v, int data, int m);
int deletetable(Node* v, int data, int m);
void printtable(Node* v, int m);
Node* initNode() {
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	return node;
}
int main() {
	int m, data;
	char op;
	scanf("%d", &m);
	Node* arr = (Node*)malloc(m * sizeof(Node));
	for (int i = 0; i < m; i++)arr[i].next = NULL;
	while (1) {
		getchar();
		scanf("%c", &op);

		if (op == 'i') {
			scanf(" %d", &data);
			insert(arr, data, m);
		}
		else if (op == 's') {
			scanf(" %d", &data);
			printf("%d\n", search(arr, data, m));
		}
		else if (op == 'd') {
			scanf(" %d", &data);
			printf("%d\n", deletetable(arr, data, m));
		}
		else if (op == 'p')
			printtable(arr, m);
		else break;
	}
	for (int i = 0; i < m; i++) {
		Node* p = arr[i].next;
		while (p != NULL) {
			Node* tmp = p;
			p = p->next;
			free(tmp);
		}
	}
	free(arr);
}
int hash(int data, int m) {
	return data % m;
}
void insert(Node* v, int data, int m) {
	Node* node = initNode();
	node->data = data;
	node->next = v[hash(data, m)].next;
	v[hash(data, m)].next = node;

}
int search(Node* v, int data, int m) {
	int idx = 0;
	Node* p = v[hash(data, m)].next;
	while (p != NULL) {
		idx++;
		if (p->data == data)return idx;
		p = p->next;
	}
	return 0;
}
int deletetable(Node* v, int data, int m) {

	Node* p = v[hash(data, m)].next;
	if (p == NULL) return 0;

	if (p->data == data) {
		v[hash(data, m)].next = v[hash(data, m)].next->next;
		free(p);
		return 1;
	}

	int idx = 1;

	while (p->next != NULL) {
		idx++;
		if (p->next->data == data) {
			Node* tmp = p->next;
			p->next = p->next->next;
			free(tmp);
			return idx;
		}
		p = p->next;
	}

	return 0;
}
void printtable(Node* v, int m) {
	for (int i = 0; i < m; i++) {
		Node* p = v[i].next;
		while (p != NULL) {
			printf("%d ", p->data);
			p = p->next;
		}
	}
	printf("\n");
}
