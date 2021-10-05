#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>



typedef struct Node {
	struct Node* next;
	int data;
}Node;

typedef struct List {
	Node* head;
	int size;
}List;

typedef struct pList {
	List* L1, *L2;
}pList;

List* initList(int size);
Node* initNode();
void mergeSort(List ** L);
List* merge(List* L1, List* L2);
pList* partition(List* L, int k);
void printList(List* L);
void deleteList(List* L);

int main() {
	int n;
	scanf("%d", &n);

	List* list = initList(n);
	Node* p = list->head;
	for (int i = 0; i < n; i++) {
		p->next = initNode();
		scanf("%d", &p->next->data);
		(p) = (p)->next;
	}
	
	mergeSort(&list);
	printList(list);
	deleteList(list);
	
}
void mergeSort(List** L) {
	List* L1 =NULL,  *L2 = NULL;

	if ((*L)->size > 1) {
		pList* pL = partition(*L, (*L)->size);
		
		L1 = pL->L1;
		L2 = pL->L2;
		mergeSort(&L1);
		mergeSort(&L2);

		*L=merge(L1, L2);
		
	}

}
pList* partition(List* L, int k) {
	pList *pL = (pList*)malloc(sizeof(List));
	pL->L1 = initList(k/2);
	pL->L2 = initList(k-k/2);

	pL->L1->head->next = L->head->next;

	Node* p = L->head->next;
	for (int i = 0; i < k / 2-1; i++) {
		p = p->next;
	}
	
	pL->L2->head->next = p->next;
	p->next = NULL;

	return pL;

}
List* merge(List* L1, List* L2) {
	List* list = initList(L1->size+L2->size);
	Node* p = list->head;
	Node* l = L1->head->next;
	Node* r = L2->head->next;
	
	while (l != NULL && r != NULL) {
		p->next = initNode();
		if (l->data < r->data) {
			p->next->data = l->data;

			l = l->next;
		}
		else {
			
			p->next->data = r->data;
			r = r->next;
		}
		p = p->next;
	}
	while (l != NULL) {
		p->next = initNode();
		p->next->data = l->data;
		l = l->next;
		p = p->next;
	}

	while (r != NULL) {
		p->next = initNode();
		p->next->data = r->data;
		r = r->next;
		p = p->next;
	}
	deleteList(L1);
	deleteList(L2);
	return list;
}



void printList(List* L) {
	Node* p = L->head->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}


List* initList(int size) {
	List* list = (List*)malloc(sizeof(List));
	list->head = initNode();
	list->size = size;
	return list;
}
Node* initNode() {
	Node* node = (Node*)malloc(sizeof(node));
	node->next = NULL;
	return node;
}
void deleteList(List* L) {
	Node* p = (L->head);
	while (p != NULL) {
		Node* tmp = p;
		p = p->next;
		free(tmp);
	}
	free(L);
}
