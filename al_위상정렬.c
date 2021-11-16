#include<stdio.h>
#include<stdlib.h>
typedef struct edge{
	struct edge *next;
	char name;
	
}edge;
typedef struct vertex {
	struct edge *edges;
	char name;
	int idx;
}vertex;

void insertEdge(vertex* v, char v1, char v2,int* idxList);
int main() {
	int n, m;
	scanf("%d", &n);
	vertex* v = (vertex*)malloc(sizeof(vertex) * (n));
	int* idxList = (int*)malloc(sizeof(int) * (200));
	int* in = (int*)malloc(sizeof(int) * n);
	char* res = (char*)malloc(sizeof(char) * n);
	for (int i = 0; i < n; i++) {
		v[i].edges = (edge*)malloc(sizeof(edge));
		v[i].edges->next = NULL;
		in[i] = 0;
		res[i] = 0;
		idxList[i] = -1;
	}
	for (int i = 0; i < 200; i++)idxList[i] = 0;
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c", &v[i].name);
		v[i].idx = i;
		idxList[v[i].name - 'A'] = i;
	}

	scanf("%d", &m);
	char a, b;
	for (int i = 0; i < m; i++) {
		getchar();
		scanf("%c %c", &a, &b);
		insertEdge(v, a, b, idxList);
		in[idxList[b - 'A']]++;
	}

	int* q = (int*)malloc(sizeof(int) * (m+n));
	int l = 0, r = 0, idx = 0;

	for (int i = 0; i < n; i++) {
		if (in[i] == 0)
			q[r++] = i;
	}
	while (l < r) {
		res[l] = v[q[l]].name;
		edge* p = v[q[l++]].edges->next;
		while (p != NULL) {
			in[idxList[p->name - 'A']]--;
			if (in[idxList[p->name - 'A']] == 0)
				q[r++] = idxList[p->name - 'A'];
			p = p->next;
		}
	}
	if (l==n)
		for (int i = 0; i < l; i++)
			printf("%c ", res[i]);
	else
		printf("0");
	for (int i = 0; i < n; i++) {
		edge* p = v[i].edges;
		while (p != NULL) {
			edge* tmp = p;
			p = p->next;
			free(tmp);
		}
	}
	free(v);
	free(idxList);
	free(res);
	free(q);
	free(in);
}

void insertEdge(vertex* v, char v1, char v2,int * idxList) {
	edge* p = v[idxList[v1-'A']].edges;
	edge* e = (edge*)malloc(sizeof(edge));
	e->name = v2;
	e->next = p->next;
	p->next = e;
}
