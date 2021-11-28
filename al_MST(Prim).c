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
	
	int  N, M, u, v, w;
	int d[3000] = { 0, };
	int size, idx, p, c, res = 0;
	scanf("%d %d", &N, &M);
	
	edge** g=(edge**)malloc(sizeof(edge*)*(N+1));
	for (int i = 0; i <= N; i++)
		g[i] = NULL;
	pq* q = (pq*)malloc(sizeof(pq) * (N * M));
	for (int i = 0; i < M; ++i) {
		scanf("%d %d %d", &u, &v, &w);

		edge* newnode = (edge*)malloc(sizeof(edge));

		newnode->v = v;
		newnode->w = w;
		newnode->next = g[u];

		g[u] = newnode;


		edge* newnode2 = (edge*)malloc(sizeof(edge));

		newnode2->v = u;
		newnode2->w = w;
		newnode2->next = g[v];

		g[v] = newnode2;

	}

	for (int i = 1; i <= N; ++i) 
		d[i] = 0;
	

	size = 1;
	idx = 1;
	
	q[idx].w = 0;
	q[idx].v = 1;

	while (size) {

		pq cur = q[1];


		pq tmpq = q[size];
		--size;
		p = 1;
		c = 2;
		while (c <= size) {
			if ((c < size) && (q[c].w > q[c + 1].w)) 
				++c;
			if (tmpq.w <= q[c].w) 
				break;

			q[p] = q[c];
			p = c;
			c *= 2;
		}
		q[p] = tmpq;

		if (d[cur.v]) //방문했으면 continue
			continue;
		

		d[cur.v] = 1; //방문 체크
		res += cur.w;
		printf("%d ", cur.v);
		
		edge* tmp = g[cur.v];

		while (tmp) {
	
			if (!d[tmp->v]) {
				
				//접점 삽입
				idx = ++size;

				while ((idx - 1) && (tmp->w < q[idx / 2].w)) {
					q[idx] = q[idx / 2];
					q[idx] = q[idx / 2];
					idx /= 2;
				}
				q[idx].w = tmp->w;
				q[idx].v = tmp->v;
			}

			tmp = tmp->next;
		}
	}
	printf("\n%d", res);

	for (int i = 0; i < N+1; ++i) {
		edge *p = g[i];
		while (p) {
			edge *tmp = p;
			p = p->next;
			free(tmp);
		}
	}

	return 0;
}
