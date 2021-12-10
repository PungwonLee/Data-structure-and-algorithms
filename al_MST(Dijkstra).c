#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
	int v, w;
	struct edge* next;
}edge;

typedef struct pq {
	int u,v, w;
}pq;

int Find(int* unf, int v) {
	if (unf[v] == v) return v;
	else return unf[v] = Find(unf,unf[v]);
}
int Union(int* unf, int u, int v) {
	int a = Find(unf,u);
	int b= Find(unf,v);
	if (a != b) unf[a] = b;
}

int main(void) {

	int  N, M, u, v, w;
	int d[3000] = { 0, };
	int size, idx, p, c, res = 0;
	size = 0;
	idx = 1;
	pq temp;
	scanf("%d %d", &N, &M);
	pq* q = (pq*)malloc(sizeof(pq) *  M);
	int* unf = (int*)malloc(sizeof(int) * (N + 1));
	for (int i = 0; i < M; ++i) {
		scanf("%d %d %d", &temp.u, &temp.v, &temp.w);

		idx = ++size;

		while ((idx - 1) && (temp.w < q[idx / 2].w)) {
			q[idx] = q[idx / 2];
			q[idx] = q[idx / 2];
			idx /= 2;
		}
		q[idx].u = temp.u;
		q[idx].w = temp.w;
		q[idx].v = temp.v;


	}
	for (int i = 1; i <= N; i++) unf[i] = i;
	




			//접점 삽입
			



	for (int i = 1; i <= N; ++i)
		d[i] = 0;



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

		int fa = Find(unf, cur.u);
		int fb = Find(unf, cur.v);
		if (fa != fb) {
			printf("%d ", cur.w);
			res += cur.w;
			Union(unf,cur.u, cur.v);
		}

	
	}
	printf("\n%d", res);



	return 0;
}
