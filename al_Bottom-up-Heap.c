#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>    // bool, true, false가 정의된 헤더 파일
#include <stdio.h>

void insertItem(int key);
int removeMax();
void upHeap(int idx);
void downHeap(int idx);
void printHeap();

void swap(int idx);
int n = 0, H[105];

int main() {
	char op;
	int key;
	while (true) {
		scanf("%c", &op);
		if (op == 'i') {
			scanf(" %d", &key);
			insertItem(key);
		}
		else if (op == 'd') {
			printf("%d\n", removeMax());
		}

		else if (op == 'p') {
			printHeap();
		}
		else break;

		getchar();
	}
}

void insertItem(int key) {
	n++;
	H[n] = key;
	upHeap(n);
	printf("0\n");
}
int removeMax() {
	int rootKey = H[1];
	H[1] = H[n];
	n--;
	downHeap(1);

	return rootKey;
}
void upHeap(int idx) {
	if (idx <= 1)
		return;
	if (H[idx] <= H[idx / 2])
		return;
	int tmp = H[idx];
	H[idx] = H[idx / 2];
	H[idx / 2] = tmp;
	upHeap(idx / 2);
}
void downHeap(int idx) {
	if (idx * 2 > n)
		return;

	if (H[idx * 2] > H[idx * 2 + 1]) {
		int tmp = H[idx];
		H[idx] = H[idx * 2];
		H[idx * 2] = tmp;
		downHeap(idx * 2);
	}
	else {
		int tmp = H[idx];
		H[idx] = H[idx * 2 + 1];
		H[idx * 2 + 1] = tmp;
		downHeap(idx * 2 + 1);
	}

}
void printHeap() {
	for (int i = 1; i <= n; i++) {
		printf("%d ", H[i]);
	}
	printf("\n");
}

void swap(int idx) {
	int tmp = H[idx];
	H[idx] = H[idx / 2];
	H[idx / 2] = tmp;

	tmp = H[idx + 1];
}
