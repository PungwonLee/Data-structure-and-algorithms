#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m, a, q[100] = { 0, }, e = 0, s = 0;
	scanf("%d %d %d", &n, &m, &a);

	int* ch = (int*)malloc(sizeof(int) * (n + 1));
	int** arr = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 1; i <= n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * (n + 1));
		ch[i] = 0;
		for (int j = 1; j <= n; j++)
			arr[i][j] = 0;
	}
	int v1, v2;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &v1, &v2);
		arr[v1][v2] = 1;
		arr[v2][v1] = 1;
	}
	q[e++] = a;
	ch[a] = 1;
	while (s < e) {
		int cur = q[s++];
		printf("%d\n", cur);
		for (int i = 1; i <= n; i++) {
			if (arr[cur][i] == 1 && ch[i] == 0) {
				ch[i] = 1;
				q[e++] = i;
			}
		}
	}
	for (int i = 0; i <= n; i++)
		free(arr[i]);
	free(arr);
	free(ch);
}
