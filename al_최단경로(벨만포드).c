#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
	int v, w;
	struct edge* next;
}edge;

typedef struct pq {
	int v, w;
}pq;


int main(void) {

	int  N, M, S, u, v, w;
	int d[3000] = { 0, };
	scanf("%d %d %d", &N, &M, &S);

	edge** g = (edge**)malloc(sizeof(edge*) * (N + 1));
	for (int i = 0; i <= N; i++) {
		g[i] = NULL;
	}
	pq* q = (pq*)malloc(sizeof(pq) * (N * M));
	for (int i = 0; i < M; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		edge* newnode = (edge*)malloc(sizeof(edge));
		newnode->v = v;
		newnode->w = w;
		newnode->next = g[u];
		g[u] = newnode;

	}

	for (int i = 1; i <= N; ++i)
		d[i] = 2100000000;

	d[S] = 0;
	int cycle = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			edge* tmp = g[j];
			while (tmp) {
				if (d[j] != 2100000000 && d[tmp->v] > d[j] + tmp->w) {
					d[tmp->v] = d[j] + tmp->w;
					if (i == N)cycle = 1; //N번째에서 값이 변하면 사이클.
				}
				tmp = tmp->next;
			}
		}
	}
	//printf("%d", cycle);
	for (int i = 1; i <= N; i++)
		if(d[i]!=2100000000 && i!=S)
			printf("%d %d\n",i, d[i]);
}
