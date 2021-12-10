#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int m, data, n;
	char op;
	scanf("%d %d", &m, &n);
	int* arr = (int*)malloc(m * sizeof(int));
	for (int i = 0; i < m; i++)arr[i] = 0;
	while (1) {
		getchar();
		scanf("%c", &op);

		if (op == 'i') {
			scanf(" %d", &data);

			int idx = data % m;
			while (arr[idx]) {
				idx = (idx + 1) % m;
				printf("C");
			}
			arr[idx] = data;
			printf("%d\n", idx);
		}
		else if (op == 's') {
			scanf(" %d", &data);

			int idx = data % m;
			if (!arr[idx]) {
				printf("-1\n");
				continue;
			}
			int cnt = 0;
			while (arr[idx] != data && cnt != m + 1) {
				idx = (idx + 1) % m;
				cnt++;
			}
			if (cnt == m + 1) {
				printf("-1\n");
				continue;
			}
			printf("%d %d\n", idx, arr[idx]);
		}
		else break;
	}
	free(arr);
}
