#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct edge {
	struct edge* next;
	int v;
	int val;
}edge;

typedef struct vertex {
	struct edge* edges;

}vertex;
void print(vertex* v, int e);

void insertEege(vertex* v, int v1, int v2, int val);
int main() {
	vertex* v = (vertex*)malloc(sizeof(vertex) * 7);
	for (int i = 0; i < 7; i++) {
		v[i].edges = (edge*)malloc(sizeof(edge));
		v[i].edges->next = NULL;
	}

	insertEege(v, 1, 2, 1);
	insertEege(v, 1, 4, 1);
	insertEege(v, 1, 6, 2);
	insertEege(v, 1, 3, 1);
	insertEege(v, 2, 3, 1);
	insertEege(v, 3, 5, 4);
	insertEege(v, 5, 5, 4);
	insertEege(v, 5, 6, 3);
	char op;
	int a, b, c;
	while (1) {
		scanf("%c", &op);
		if (op == 'a') {
			scanf(" %d", &a);
			print(v, a);
		}
		else if (op == 'm') {
			scanf(" %d %d %d", &a, &b, &c);
			insertEege(v, a, b, c);
		}
		else break;
		getchar();
	}
}
void print(vertex* v, int e) {
	if (e < 1 || e > 6)return printf("-1\n");
	edge* p = v[e].edges->next;

	while (p != NULL) {
		printf("%d %d ", p->v, p->val);
		p = p->next;
	}
	printf("\n");
}
void insertEege(vertex* v, int v1, int v2, int val) {
	if (v1 < 1 || v1 > 6 || v2 < 1 || v2 > 6)return printf("-1\n");
	edge* p = v[v1].edges;

	while (p->next != NULL && p->next->v < v2) {
		p = p->next;
	}
	if (val) {
		if (p->next == NULL || p->next->v != v2) {
			edge* e = (edge*)malloc(sizeof(edge));
			e->v = v2;
			e->val = val;
			e->next = NULL;

			e->next = p->next;
			p->next = e;
		}
		else p->next->val = val;
	}
	else {
		if (p->next == NULL)return;
		edge* tmp = p->next;
		p->next = p->next->next;
		free(tmp);
	}

	if (v1 == v2)return;

	p = v[v2].edges;

	while (p->next != NULL && p->next->v < v1) {
		p = p->next;
	}
	if (val) {
		if (p->next == NULL || p->next->v != v1) {
			edge* e2 = (edge*)malloc(sizeof(edge));
			e2->v = v1;
			e2->val = val;
			e2->next = NULL;

			e2->next = p->next;
			p->next = e2;
		}
		else p->next->val = val;

	}
	else {
		if (p->next == NULL)return;
		edge* tmp = p->next;
		p->next = p->next->next;
		free(tmp);

	}



}
