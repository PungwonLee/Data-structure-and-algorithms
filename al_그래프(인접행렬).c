#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void make(int** arr, int n, int m, int k);
void print(int** arr, int n);
int main() {
	char op;
	int n, m, k;
	int** arr = (int**)malloc(7 * sizeof(int*));

	for (int i = 0; i < 7; i++) {
		arr[i] = (int*)malloc(7 * sizeof(int));
		for (int j = 0; j < 7; j++)
			arr[i][j] = 0;
	}
	make(arr, 2, 1, 1);
	make(arr, 2, 3, 1);
	make(arr, 1, 4, 1);
	make(arr, 1, 6, 2);
	make(arr, 1, 3, 1);
	make(arr, 3, 5, 4);
	make(arr, 5, 6, 3);
	make(arr, 5, 5, 4);

	while (1) {
		scanf("%c", &op);
		if (op == 'm') {
			scanf("%d %d %d", &n, &m, &k);
			make(arr, n, m, k);
		}
		else if (op == 'a') {
			scanf("%d", &n);
			print(arr, n);
		}
		else {
			break;
		}
		getchar();
	}
	return 0;
}


void make(int** arr, int n, int m, int k) {
	if (n < 1 || n > 6)return printf("-1\n");
	if (m < 1 || m > 6)return printf("-1\n");

	arr[n][m] = k;
	arr[m][n] = k;
}

void print(int** arr, int n) {
	if (n<1 ||n > 6)return printf("-1\n");
	
	for (int i = 0; i < 7; i++) {
		if (arr[n][i])
			printf("%d %d ", i, arr[n][i]);
	}
	printf("\n");
}
