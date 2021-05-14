#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	char elem;
	struct Node* prev, * next;
}Node;
typedef struct List {
	Node* Head, *Tail;
}List;
Node* mall() {
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	node->prev = NULL;
	return node;
}
List* initlist() {
	List* list = (List*)malloc(sizeof(List));

	list->Head = mall();
	list->Tail = mall();

	list->Head->next = list->Tail;
	list->Tail->prev= list->Head;
	return list;
}
void add(List* H, int idx, int ch);
void print(List* H);
void delete(List* H, int idx);
void get(List* H, int idx);
int n = 1;
int main() {
	List* list = initlist();
	
	int k, idx;
	char op, ch;
	scanf("%d", &k);
	while (k) {
		k--;
		getchar();
		scanf("%c", &op);
		if (op == 'A') {
			scanf("%d %c", &idx, &ch);
			add(list, idx, ch);
		}
		else if (op == 'P') {
			print(list);
		}
		else if (op == 'D') {
			scanf("%d", &idx);
			delete(list, idx);
		}
		else if (op == 'G') {
			scanf("%d", &idx);
			get(list, idx);
		}

	}

	return 0;
}

void add(List* H, int idx, int ch) {
	if (idx > n) {
		printf("invalid position\n");
		return;
	}
	Node* node = mall();
	node->elem = ch;
	Node* p = H->Head;

	for (int i = 0; i < idx; i++)
		p = p->next;

	node->prev = p->prev;
	node->next = p;
	(p->prev)->next = node;
	p->prev = node;
	n += 1;

}
void print(List* H) {
	if (n <= 1) {
		printf("invalid position\n");
		return;
	}
	Node* p = H->Head;
	for (int i = 0; i < n - 1; i++) {
		p = p->next;
		printf("%c", p->elem);
	}
	printf("\n");
}
void delete(List* H, int idx) {
	if (n < idx + 1 || n <= 1) {
		printf("invalid position\n");
		return;
	}
	Node* p = H->Head;
	for (int i = 0; i < idx; i++) {
		p = p->next;
	}
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
	n -= 1;
}
void get(List* H, int idx) {
	if (n < idx + 1 || n <= 1) {
		printf("invalid position\n");
		return;
	}
	Node* p = H->Head;
	for (int i = 0; i < idx; i++)
		p = p->next;
	printf("%c\n", p->elem);
}
